// DNASorting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

const std::string DataFileName("data.ini");

typedef std::vector< std::pair<std::string, unsigned int> > DNAInversionNumContain;
typedef DNAInversionNumContain::value_type DNAInversionNumType;

inline void printAll(const DNAInversionNumType &dna)
{
    std::cout << dna.first << "\t" << dna.second << "\n";
}

inline void printDNA(const DNAInversionNumType& dna)
{
    std::cout << dna.first << "\n";
}

struct Inversion {
    unsigned int inversions;
    unsigned int numOfA;
    unsigned int numOfC;
    unsigned int numOfG;
    Inversion() 
        : inversions(0)
        , numOfA(0)
        , numOfC(0)
        , numOfG(0)
    {}

    void operator()(const std::string::value_type& c) {
        switch (c) {
        case 'A':
            ++numOfA;
            break;
        case 'C':
            ++numOfC;
            inversions += numOfA;
            break;
        case 'G':
            ++numOfG;
            inversions += numOfA + numOfC;
            break;
        case 'T':
            inversions += numOfA + numOfC + numOfG;
        }
    }
};

struct CalcInversionOfOneDNA {
    DNAInversionNumType operator()(const DNAInversionNumType& dnaInversion) {
        Inversion inversion = std::for_each(dnaInversion.first.rbegin(), dnaInversion.first.rend(), Inversion());
        return DNAInversionNumType(dnaInversion.first, inversion.inversions);
    }
};

void calcInversion(DNAInversionNumContain &dnaInversion)
{
    std::transform(dnaInversion.begin(), dnaInversion.end(), dnaInversion.begin(), CalcInversionOfOneDNA());
}

bool compareByInversion(const DNAInversionNumType& lhs, const DNAInversionNumType& rhs)
{
    return lhs.second < rhs.second;
}

void sortInversion(DNAInversionNumContain &dnaInversion)
{
    std::stable_sort(dnaInversion.begin(), dnaInversion.end(), compareByInversion);
}

int _tmain(int argc, _TCHAR* argv[])
{
    std::ifstream file(DataFileName, std::ios::in);
    if (!file.good()) {
        std::cout << "File Not Good: " << DataFileName << "\n";
        return 0;
    }
    
    unsigned int dnalength = 0;
    unsigned int linenum = 0;
    file >> dnalength >> linenum;
    
    std::string onelineOfFile;
    DNAInversionNumContain dnaInversion;
    for (unsigned int i = 0; i < linenum; ++i) {
        file >> onelineOfFile;
        dnaInversion.push_back(DNAInversionNumType(onelineOfFile, 0));
    }

    //std::cout << dnalength << "\t" << linenum << "\n";
    calcInversion(dnaInversion);
    //std::for_each(dnaInversion.begin(), dnaInversion.end(), printAll);
    //std::cout << std::endl;

    sortInversion(dnaInversion);
    std::for_each(dnaInversion.begin(), dnaInversion.end(), printDNA);
    
    return 0;
}

