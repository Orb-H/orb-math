#include "whole_number.h"

using namespace std;
using namespace orbmath;

WholeNumber::WholeNumber(unsigned long long l) { data.push_back(l); }

string WholeNumber::toBinString()
{
    string res;
    unsigned long long l;
    unsigned long long mask = 0x8000000000000000ULL;
    char tmp;

    res.append("0b");
    for (int i = data.size() - 1; i >= 0; i--)
    {
        l = data[i];
        for (int j = 0; j < 64; j++)
        {
            tmp = (char)(((l & mask) >> 63) & 0x1);
            if (tmp > 0)
                res += '1';
            else if ((res.size() > 2) || (!i && j == 15))
                res += '0';
            l <<= 1;
        }
    }
    return res;
}

string WholeNumber::toHexString()
{
    string res;
    unsigned long long l;
    unsigned long long mask = 0xf000000000000000ULL;
    char tmp;

    res.append("0x");
    for (int i = data.size() - 1; i >= 0; i--)
    {
        l = data[i];
        for (int j = 0; j < 16; j++)
        {
            tmp = (char)(((l & mask) >> 60) & 0xf);
            if (tmp >= 10)
                res += tmp - 10 + 'a';
            else if (tmp > 0)
                res += tmp + '0';
            else if ((res.size() > 2) || (!i && j == 15))
                res += '0';
            l <<= 4;
        }
    }
    return res;
}

WholeNumber WholeNumber::fromULL(unsigned long long l) { return WholeNumber(l); }
