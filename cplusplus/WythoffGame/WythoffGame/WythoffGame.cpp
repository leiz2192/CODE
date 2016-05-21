// WythoffGame.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <sstream>

const double GoldenSection = (1 + std::sqrt(5.0)) / 2.0;

int Wythoff(int lhs, int rhs);
int Wythoff(const std::string &lhs, const std::string &rhs);

int main(int argc, char* argv[])
{
    std::ifstream file("data.ini");
    std::istream_iterator<std::string> dataBegin(file);
    std::istream_iterator<std::string> dataEnd;
    std::vector<std::string> data(dataBegin, dataEnd);

    if (data.size() % 2 != 0) {
        std::cout << "Data Incompleted.\n";
        return -1;
    }

    int cnt = data.size() / 2;
    for (int i = 0; i < cnt; ++i) {
        std::cout << Wythoff(data[2 * i], data[2 * i + 1]) << '\n';
    }
    
    return 0;
}

int Wythoff(int lhs, int rhs)
{
    int diff = std::abs(lhs - rhs);
    int minData = std::min(lhs, rhs);
    return (minData == static_cast<int>(diff * GoldenSection)) ? 0 : 1;
}

int Wythoff(const std::string &lhs, const std::string &rhs)
{
    std::istringstream iss(lhs);
    int lData = 0;
    iss >> lData;

    iss.clear();
    iss.str(rhs);
    int rData = 0;
    iss >> rData;

    return Wythoff(lData, rData);
}

