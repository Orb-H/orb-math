#include "whole_number.h"

using namespace std;
using namespace orbmath;

WholeNumber::WholeNumber(unsigned long long l) { data.push_back(l); }

WholeNumber WholeNumber::fromULL(unsigned long long l) { return WholeNumber(l); }
