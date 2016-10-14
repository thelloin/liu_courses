#ifndef CHAR_TRAITS_H
#define CHAR_TRAITS_H

#include <cstddef> // for size_t
#include <cstring> // for memmove, memset, memchr, strlen
#include <iosfwd>  // for streampos
#include <stdio.h> // for EOF
/*
 * char_traits specialization for char
 *
 * NOTE: This is not to be used since there already exists a
 * specialization for char defined in <string> so it is not
 * possible to use this in combination with std::string.
 */

// Original declaration is in <string>
template <typename charT> struct char_traits;

// Standard library specialization is in <string>
template <> struct char_traits<char>
{
   typedef char             char_type;
   typedef int              int_type;
   typedef std::streampos   pos_type;
   typedef std::streamoff   off_type;
   typedef std::mbstate_t   state_type;

   static void assign(char& c1, const char& c2)
   {
      c1 = c2;
   }

   static bool eq(const char& c1, const char& c2)
   {
      return c1 == c2;
   }

   static bool lt(const char& c1, const char& c2)
   {
      return c1 < c2;
   }

   static int compare(const char* s1, const char* s2, size_t n)
   {
      return memcmp(s1, s2, n);
   }

   static size_t length(const char* s)
   {
      size_t i {0};
      while (!eq(s[i], char()))
	 ++i;
      return i;
      //return strlen(s);
   }

   static const char* find(const char* s, size_t n, const char& a)
   {
      for (size_t i{0}; i < n; ++i)
      {
	 if (eq(s[i], a))
	    return s + i; // return s[i] not const???;
      }
      return 0;
      //return static_cast<const char*>(memchr(s, a, n);
   }

   static char* move(char* s1, const char* s2, size_t n)
   {
      return static_cast<char*>(memmove(s1, s2, n));
   }

   static char* copy(char* s1, const char* s2, size_t n)
   {
      return static_cast<char*>(memcpy(s1, s2, n));
   }

   static char* assign(char* s, size_t n, char a)
   {
      return static_cast<char*>(memset(s, a, n));
   }

   static char to_char_type(const int& c)
   {
      return static_cast<char>(c);
   }

   static int to_int_type(const char& c)
   {
      return static_cast<int>(static_cast<unsigned char>(c));
   }

   static bool eq_int_type(const int& c1, const int& c2)
   {
      return c1 == c2;
   }

   static int eof()
   {
      return static_cast<int>(EOF);
   }

   static int not_eof(const int& c)
   {
      return (c == eof()) ? 0 : c;
   }
};

#endif
