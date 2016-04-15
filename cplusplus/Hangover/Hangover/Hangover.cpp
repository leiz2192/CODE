// Hangover.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

inline void printstring(const std::string& str)
{
    std::cout << str << "\n";
}

int getNCards(double indata)
{
    double sum = 0.0;
    int n = 0;
    while (++n) {
        sum += 1.0 / (n + 1);
        if (sum > indata) {
            break;
        }
    }

    return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<std::string> result;
    double indata;
    while (std::cin >> indata) {
        if ((indata - 0.00) < 0.00001) {
            break;
        }

        std::ostringstream oss;
        oss << getNCards(indata) << " card(s)";
        result.push_back(oss.str());
    }

    std::for_each(result.begin(), result.end(), printstring);

    return 0;
}

