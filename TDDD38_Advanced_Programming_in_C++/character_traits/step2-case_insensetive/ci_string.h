#ifndef CI_STRING_INC
#define CI_STRING_INC

#include <string>
#include <iostream>
#include <iomanip>
#include "ci_char_traits.h"

typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream& operator<<(std::ostream& os, const ci_string& s)
{
   return os << s.c_str();
}

std::istream& operator>>(std::istream& is, ci_string& s)
{
   char buf[256];
   is >> std::setw(255) >> buf;
   s = buf;
   return is;
}

#endif
