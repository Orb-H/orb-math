#include <vector>
#include <string>

#ifndef __ORB_WHOLE_H__
#define __ORB_WHOLE_H__

using namespace std;

namespace orbmath
{

    class WholeNumber
    {
    private:
        vector<unsigned long long> data;

    public:
        WholeNumber(unsigned long long l);
        WholeNumber(string s, int radix); //bin and hex only

        string toBinString();
        string toHexString();

        static WholeNumber fromULL(unsigned long long l);
        static WholeNumber fromBinString(string s);
        static WholeNumber fromHexString(string s);
    };

} // namespace orbmath

#endif