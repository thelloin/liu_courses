#ifndef CI_CHAR_TRAITS_INC
#define CI_CHAR_TRAITS_INC

#include <string>
#include <cstring>

/*
 * Case-insensetive traits for char
 */

struct ci_char_traits : public std::char_traits<char>
{
   static bool eq(char c1, char c2)
   {
      return tolower(c1) == tolower(c2);
   }

   static bool lt(char c1, char c2)
   {
      return tolower(c1) < tolower(c2);
   }

   static int compare(const char* s1, const char* s2, size_t n)
   {
      return strncasecmp(s1, s2, n);
   }

   static const char* find(const char* s, int n, char a)
   {
      while (n-- > 0 && tolower(*s) != tolower(a))
	 ++s;
      return s;
   }
};

#endif
