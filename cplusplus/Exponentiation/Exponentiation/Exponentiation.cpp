// Exponentiation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

//char result[200];
std::string result; //存R^N的结果

//大实数的乘法,乘数为FirMultiplier和SecMultiplier，结果存在Result中
void highRealMul(std::string& firstMultiplier, std::string& secondMultiplier, std::string& result);
//剔除实数尾部的无效0或小数点
void cutInsignificantTail(std::string& strR);
//计算小数点在实数中的位数
int countPointIndex(std::string& strR);
//删除实数中的小数点,PointIndex为小数点在实数中从右向左数的第几位
void deletePoint(std::string& strR);

//大实数的乘法,乘数为FirMultiplier和SecMultiplier，结果存在Result中
void highRealMul(std::string& firstMultiplier, std::string& secondMultiplier, std::string& result)
{
    std::string tmpResult(200, '0');
    int firstLen = firstMultiplier.size();
    int secondLen = secondMultiplier.size();
    int carry = 0;//进位

    //模拟乘法运算
    for (int i = secondLen - 1; i >= 0; i--)
    {
        int firMul = 0;
        int secMul = secondMultiplier[i] - '0';
        int j = 0;
        carry = 0;
        for (j = firstLen - 1; j >= 0; j--)
        {
            firMul = firstMultiplier[j] - '0';
            int tmp = tmpResult[secondLen - 1 - i + firstLen - 1 - j] - '0' + carry + firMul * secMul;;
            tmpResult[secondLen - 1 - i + firstLen - 1 - j] = tmp % 10 + '0';
            carry = tmp / 10;
        }

        if (carry != 0) {
            tmpResult[secondLen - 1 - i + firstLen - 1 - j] = '0' + carry;
        }
    }

    if (carry != 0) {
        tmpResult = tmpResult.substr(0, secondLen + firstLen);
    }
    else {
        tmpResult = tmpResult.substr(0, firstLen + secondLen - 1);
    }
    
    //将临时存储的答案TmpResult倒转变成我们熟悉的方式，存到Result中
    result.assign(tmpResult.rbegin(), tmpResult.rend());
}

//剔除实数尾部的无效0或小数点
void cutInsignificantTail(std::string& strR)
{
    int index = strR.find(".");
    if (index == strR.npos) {
        return;
    }

    for (int i = strR.size() - 1; i > index; i--)
    {
        if ('0' == strR[i] || '.' == strR[i])
        {
            strR.erase(i);
        }
        else
        {
            return;
        }
    }
}

//计算小数点在实数中的位数
int countPointIndex(std::string& strR)
{
    int index = strR.find(".");
    if (index == std::string::npos) {
        index = 0;
    }
    else {
        index = strR.size() - index;
    }

    return index;
}

//删除实数中的小数点
void deletePoint(std::string& strR)
{
    int pos = strR.find(".");
    if (pos != strR.npos) {
        strR = strR.substr(0, pos) + strR.substr(pos + 1, strR.size() - pos);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    //R对应的字符串
    std::string strR;
    int N = 0;
    int i = 0;
    //记录小数点在实数中从右向左数的第几位，如1.26在第3位，4在第0位
    int pointIndex = 0;
    while (std::cin >> strR >> N)
    {
        cutInsignificantTail(strR);
        pointIndex = countPointIndex(strR);
        deletePoint(strR);

        result.assign(strR.begin(), strR.end());
        for (i = 2; i <= N; i++) {
            highRealMul(result, strR, result);
        }

        int len = result.size();
        if ((len - (pointIndex - 1) * N) < 0) {
            std::cout << ".";
            for (i = len - (pointIndex - 1) * N; i < 0; i++) {
                std::cout << "0";
            }
        }
        //输出小数点
        std::cout << result.substr(0, len - (pointIndex - 1) * N) << "." << result.substr(len - (pointIndex - 1) * N + 1, (pointIndex - 1) * N);
        //for (i = 0; i < len; i++) {
        //    if (i == len - (pointIndex - 1) * N) {
        //        std::cout << ".";
        //    }
        //    std::cout << result[i];
        //}
        std::cout << "\n";
    }
    
    return 0;
}

