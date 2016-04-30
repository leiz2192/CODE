// EdgeDetection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <cmath>

//typedef std::pair<int, int> PixPair;

struct DetectPix {
    int val_;
    int pos_;

    DetectPix(int val, int pos)
        : val_(val)
        , pos_(pos)
    {}
};

struct PixPair {
    int val_;
    int cnt_;

    PixPair(int val, int cnt)
        : val_(val)
        , cnt_(cnt)
    {}
};

struct ShowOnePixPair {
    void operator()(const PixPair& pixPair)
    {
        std::cout << pixPair.val_ << ' ' << pixPair.cnt_ << '\n';
    }
};

struct CompairDetectPix {
    bool operator() (const DetectPix& lhs, const DetectPix& rhs)
    {
        return lhs.pos_ < rhs.pos_;
    }
};

struct UniqueDetectPix {
    bool operator() (const DetectPix& lhs, const DetectPix& rhs)
    {
        return (lhs.val_ == rhs.val_);
    }
};

class Image
{
public:
    virtual ~Image() {}
    Image(int width) : m_width(width), m_totalPixs(0) {}

    void addPixPair(const int value, const int count)
    {
        m_pixPair.push_back(PixPair(value, count));
        m_totalPixs += count;
    }

    void showAllOut()
    {
        std::cout << m_width << '\n';
        std::for_each(m_pixPair.begin(), m_pixPair.end(), ShowOnePixPair());
    }

    void doDetected()
    {
        int pos = 1;
        for (std::size_t p = 0; p < m_pixPair.size(); ++p) {
            int row = (pos - 1) / m_width;
            int col = (pos - 1) % m_width;
            for (int i = (row - 1); i <= (row + 1); ++i) {
                for (int j = (col - 1); j <= (col + 1); ++j) {
                    int thePos = i * m_width + j;
                    if ((i < 0) || (j < 0) || (thePos >= m_totalPixs) || (j >= m_width)) {
                        continue;
                    }

                    m_pixDetect.push_back(DetectPix(getCodeByPos(thePos + 1), thePos + 1));
                }
            }

            pos += m_pixPair[p].cnt_;
        }

        std::sort(m_pixDetect.begin(), m_pixDetect.end(), CompairDetectPix());
        m_pixDetect.erase(std::unique(m_pixDetect.begin(), m_pixDetect.end(), UniqueDetectPix()),
            m_pixDetect.end());
    }

    void showDetected()
    {
        //std::for_each(m_pixDetect.begin(), m_pixDetect.end(), ShowOnePixPair());
        std::cout << m_width << '\n';
        DetectPix& pixDetect = m_pixDetect[0];
        for (std::size_t i = 1; i < m_pixDetect.size(); ++i) {
            //if (pixDetect.val_ == m_pixDetect[i].val_) {
            //    continue;
            //}
            std::cout << pixDetect.val_ << ' ' << m_pixDetect[i].pos_ - pixDetect.pos_ << '\n';
            pixDetect = m_pixDetect[i];
        }
        std::cout << pixDetect.val_ << ' ' << m_totalPixs - pixDetect.pos_ + 1 << '\n';
        std::cout << "0 0\n";
    }

    int getCodeByPos(const int pos)
    {
        int maxABS = 0;
        int value = getValueByPos(pos);

        int row = (pos - 1) / m_width;
        int col = (pos - 1) % m_width;
        for (int i = row - 1; i <= (row + 1); ++i) {
            for (int j = col - 1; j <= (col + 1); ++j) {
                int thePos = i * m_width + j;
                if ((i < 0) || (j < 0) || (j >= m_width) || (thePos >= m_totalPixs) || (thePos == (pos - 1))) {
                    continue;
                }

                int theValue = getValueByPos(thePos + 1);
                int absValue = std::abs(value - theValue);
                if (maxABS < absValue) {
                    maxABS = absValue;
                }
            }
        }

        return maxABS;
    }

    int getValueByPos(const int pos)
    {
        int p = 0;
        std::size_t i = 0;
        while ((p < pos) && (i < m_pixPair.size())) {
            p += m_pixPair[i++].cnt_;
        }

        return m_pixPair[i - 1].val_;
    }

private:
    int m_width;
    int m_totalPixs;
    std::vector<PixPair> m_pixPair;
    std::vector<DetectPix> m_pixDetect;
};

struct ShowImage {
    void operator()(const std::shared_ptr<Image>& image_ptr)
    {
        image_ptr->showAllOut();
    }
};

struct DetectImage {
    void operator()(const std::shared_ptr<Image>& image_ptr)
    {
        image_ptr->doDetected();
    }
};

struct ShowDetectImage {
    void operator()(const std::shared_ptr<Image>& image_ptr)
    {
        image_ptr->showDetected();
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    std::ifstream file("data.ini");
    if (!file.is_open()) {
        std::cout << "File  data.ini open failed\n";
    }

    int width = 0;
    std::vector< std::shared_ptr<Image> > images;
    while ((file >> width) && (width != 0)) {
        std::shared_ptr<Image> pImage = std::make_shared<Image>(Image(width));
        int pair_value = 0;
        int pair_count = 0;

        while ((file >> pair_value >> pair_count) && (pair_count != 0)) {
            pImage->addPixPair(pair_value, pair_count);
        }
        images.push_back(pImage);
    }

    //std::for_each(images.begin(), images.end(), ShowImage());
    std::for_each(images.begin(), images.end(), DetectImage());
    std::for_each(images.begin(), images.end(), ShowDetectImage());
    std::cout << "0\n";

    return 0;
}

