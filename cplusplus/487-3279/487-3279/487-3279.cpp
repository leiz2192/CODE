// 487-3279.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef std::map<std::string, int> NumberCountType;

// A ~ Z map to number, no mapping for Q and Z
const std::string LettersToNumbers = "2223334445556667Q77888999Z";

bool g_NoDuplicates = false;

void letterConvert(const std::string& lhs, std::string& rhs)
{
    rhs.clear();
    for (std::string::size_type i = 0; i < lhs.size(); ++i) {
        if ((lhs[i] >= '0') && (lhs[i] <= '9')) {
            rhs.push_back(lhs[i]);
        }
        else if ((lhs[i] >= 'A') && (lhs[i] <= 'Z')) {
            rhs.push_back(LettersToNumbers[lhs[i] - 'A']);
        }
    }
}

void printNumber(std::pair<std::string, int> numberCount)
{
    if (numberCount.second > 1) {
        std::cout << numberCount.first << " " << numberCount.second << "\n";
        g_NoDuplicates = true;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    NumberCountType numberCount;
    int N;
    std::cin >> N;
    while (N > 0) {
        std::string beforeConvert;
        std::cin >> beforeConvert;

        std::string afterConvert;
        letterConvert(beforeConvert, afterConvert);
        afterConvert.insert(3, 1, '-');
        ++numberCount[afterConvert];
        --N;
    }

    std::for_each(numberCount.begin(), numberCount.end(), printNumber);
    if (!g_NoDuplicates) {
        std::cout << "No duplicates." << "\n";
    }
    return 0;
}

/*
Sample Input

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

Sample Output

310-1010 2
487-3279 4
888-4567 3
*/

