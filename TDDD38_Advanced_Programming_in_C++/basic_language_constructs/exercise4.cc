#include <iostream>

using unsigned_char               = unsigned char;
using const_unsigned_char          = const unsigned_char;
using ptr_to_int                  = int*;
using ptr_to_ptr_to_char          = char**;
using ptr_to_arr_of_char          = char*;
using arr_of_10_ptr_to_int        = ptr_to_int[10];
using ptr_to_arr_of_10_ptr_to_int = arr_of_10_ptr_to_int*;
using arr_20_arr_10_of_ptr_to_int = ptr_to_int[20][10];


int main()
{
  unsigned_char uc{};
  const_unsigned_char cuc{ 'A' };
  ptr_to_int pi{ new int(4711) };

  char c{ 'X' };
  char* pc{ &c };
  ptr_to_ptr_to_char ppc{ &pc };

  char a[]{ "foobar" };
  ptr_to_arr_of_char pac{ a };

  arr_of_10_ptr_to_int a10pi{ pi };             // The rest is zero initialized
  ptr_to_arr_of_10_ptr_to_int pa10pi{ &a10pi };
  arr_20_arr_10_of_ptr_to_int a20a10pi{ pi };   // The rest is zero initialized

  std::cout << uc              << '\n';
  std::cout << cuc             << '\n';
  std::cout << *pi             << '\n';
  std::cout << **ppc           << '\n';
  std::cout << pac             << '\n';
  std::cout << pac[0]          << '\n';
  std::cout << *(a10pi[0])     << '\n';
  std::cout << ***pa10pi       << '\n';
  std::cout << *a20a10pi[0][0] << '\n';

  return 0;
}
