#include "whole_number.h"
#include <iostream>

using namespace std;
using namespace orbmath;

int main()
{
    // test ULL 1
    WholeNumber wn = WholeNumber(5);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test ULL 2
    wn = WholeNumber(10000000000000000ULL);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test bin string
    wn = WholeNumber("0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001", 2);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test hex string(same value with bin string above)
    wn = WholeNumber("0x193ea09d0e798f29da9dfebd92ea9", 16);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test ULL static 1
    wn = WholeNumber::fromULL(5);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test ULL static 2
    wn = WholeNumber::fromULL(10000000000000000ULL);
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test bin string static
    wn = WholeNumber::fromBinString("0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001");
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test hex string static
    wn = WholeNumber::fromHexString("0x193ea09d0e798f29da9dfebd92ea9");
    cout << wn.toHexString() << " " << wn.toBinString() << endl;

    // test wrong bin string
    try
    {
        wn = WholeNumber("0b2", 2);
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    // test wrong hex string
    try
    {
        wn = WholeNumber("0xg", 16);
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    // test empty bin string
    try
    {
        wn = WholeNumber("0b", 2);
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    // test empty hex string
    try
    {
        wn = WholeNumber("0x", 16);
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    // test wrong radix
    try
    {
        wn = WholeNumber("034", 6);
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    /// Output
    ///
    /// 0x5 0b101
    /// 0x2386f26fc10000 0b100011100001101111001001101111110000010000000000000000
    /// 0x193ea09d0e798f29da9dfebd92ea9 0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001
    /// 0x193ea09d0e798f29da9dfebd92ea9 0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001
    /// 0x5 0b101
    /// 0x2386f26fc10000 0b100011100001101111001001101111110000010000000000000000
    /// 0x193ea09d0e798f29da9dfebd92ea9 0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001
    /// 0x193ea09d0e798f29da9dfebd92ea9 0b11001001111101010000010011101000011100111100110001111001010011101101010011101111111101011110110010010111010101001
    /// Error : Wrong character for binary integer
    /// Error : Wrong character for hexadecimal integer
    /// Error : Empty string
    /// Error : Empty string
    /// Error : Invalid radix
}