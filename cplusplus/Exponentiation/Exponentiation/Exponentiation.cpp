// Exponentiation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

//char result[200];
std::string result; //��R^N�Ľ��

//��ʵ���ĳ˷�,����ΪFirMultiplier��SecMultiplier���������Result��
void highRealMul(std::string& firstMultiplier, std::string& secondMultiplier, std::string& result);
//�޳�ʵ��β������Ч0��С����
void cutInsignificantTail(std::string& strR);
//����С������ʵ���е�λ��
int countPointIndex(std::string& strR);
//ɾ��ʵ���е�С����,PointIndexΪС������ʵ���д����������ĵڼ�λ
void deletePoint(std::string& strR);

//��ʵ���ĳ˷�,����ΪFirMultiplier��SecMultiplier���������Result��
void highRealMul(std::string& firstMultiplier, std::string& secondMultiplier, std::string& result)
{
    std::string tmpResult(200, '0');
    int firstLen = firstMultiplier.size();
    int secondLen = secondMultiplier.size();
    int carry = 0;//��λ

    //ģ��˷�����
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
    
    //����ʱ�洢�Ĵ�TmpResult��ת���������Ϥ�ķ�ʽ���浽Result��
    result.assign(tmpResult.rbegin(), tmpResult.rend());
}

//�޳�ʵ��β������Ч0��С����
void cutInsignificantTail(std::string& strR)
{
    int index = strR.find(".");
    if (index == strR.npos) {
        return;
    }

    for (int i = strR.size() - 1; i > index; i--) {
        if ('0' == strR[i] || '.' == strR[i]) {
            strR.erase(i);
        } else {
            return;
        }
    }
}

//����С������ʵ���е�λ��
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

//ɾ��ʵ���е�С����, ɾ��С���������ͷ��0
void deletePoint(std::string& strR)
{
    int pos = strR.find(".");
    if (pos != strR.npos) {
        strR.erase(pos, 1);
    }

    pos = strR.find_first_not_of("0");
    if (pos != strR.npos) {
        strR.erase(0, pos);
    }
    else {
        strR = "0";
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    //R��Ӧ���ַ���
    std::string strR;
    int N = 0;
    while (std::cin >> strR >> N)
    {
        cutInsignificantTail(strR);
        //��¼С������ʵ���д����������ĵڼ�λ����1.26�ڵ�3λ��4�ڵ�0λ
        int pointIndex = countPointIndex(strR);
        deletePoint(strR);

        result.assign(strR.begin(), strR.end());
        for (int i = 2; i <= N; i++) {
            highRealMul(result, strR, result);
        }

        int len = result.size();
        if ((len - (pointIndex - 1) * N) < 0) {
            std::cout << "." << std::string((pointIndex - 1) * N - len, '0') << result;
        }
        else {
            std::cout << result.substr(0, len - (pointIndex - 1) * N) << "." << result.substr(len - (pointIndex - 1) * N);
        }
        std::cout << "\n";
    }
    
    return 0;
}

