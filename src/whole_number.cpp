#include "whole_number.h"
#include <stdexcept>

using namespace std;
using namespace orbmath;

WholeNumber::WholeNumber(unsigned long long l) { data.push_back(l); }

WholeNumber::WholeNumber(string s, int radix)
{
    unsigned long long l;
    switch (radix)
    {
    case 2:
        if (s.substr(0, 2) == "0b")
            s = s.substr(2);

        while (s.length() > 64)
        {
            string t = s.substr(s.length() - 64);
            s = s.substr(0, s.length() - 64);

            l = 0;
            for (int i = 0; i < 64; i++)
            {
                switch (t[i])
                {
                case '0':
                case '1':
                    l += ((unsigned long long)(t[i] - '0')) << (63 - i);
                    break;
                default:
                    throw invalid_argument("Wrong character for binary integer");
                }
            }

            data.push_back(l);
        }
        if (s.length() == 0)
            throw invalid_argument("Empty string");

        l = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '0':
            case '1':
                l += ((unsigned long long)(s[i] - '0')) << (s.length() - 1 - i);
                break;
            default:
                throw invalid_argument("Wrong character for binary integer");
            }
        }
        data.push_back(l);
        break;
    case 16:
        if (s.substr(0, 2) == "0x")
            s = s.substr(2);

        while (s.length() > 16)
        {
            string t = s.substr(s.length() - 16);
            s = s.substr(0, s.length() - 16);

            l = 0;
            for (int i = 0; i < 16; i++)
            {
                switch (t[i])
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    l += ((unsigned long long)(t[i] - '0')) << (4 * (15 - i));
                    break;
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                    l += ((unsigned long long)(t[i] - 'a' + 10)) << (4 * (15 - i));
                    break;
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                    l += ((unsigned long long)(t[i] - 'A' + 10)) << (4 * (15 - i));
                    break;
                default:
                    throw invalid_argument("Wrong character for hexadecimal integer");
                }
            }

            data.push_back(l);
        }
        if (s.length() == 0)
            throw invalid_argument("Empty string");

        l = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                l += ((unsigned long long)(s[i] - '0')) << (4 * (s.length() - 1 - i));
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                l += ((unsigned long long)(s[i] - 'a' + 10)) << (4 * (s.length() - 1 - i));
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                l += ((unsigned long long)(s[i] - 'A' + 10)) << (4 * (s.length() - 1 - i));
                break;
            default:
                throw invalid_argument("Wrong character for hexadecimal integer");
            }
        }
        data.push_back(l);
        break;
    default:
        throw invalid_argument("Invalid radix");
    }
}

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
            else if ((res.size() > 2) || (!i && j == 63))
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

WholeNumber WholeNumber::fromBinString(string bin) { return WholeNumber(bin, 2); }

WholeNumber WholeNumber::fromHexString(string hex) { return WholeNumber(hex, 16); }