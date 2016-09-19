#include <iostream>


int main()
{
  std::string s10[10]{ "hel" };

  char* char_ptr{ new char{ 'C' } };
  int int_arr[10]{ 1, 2, 3, 4, 5 };
  int (&int_ref)[10]{ int_arr };
  std::string (*s_ptr)[10]{ &s10 };
  char** c{ &char_ptr };
  const int ci{ 43 };
  const int* cip = &ci;
  int* const icp{ int_arr };

  std::cout << "*char_ptr  : " << *char_ptr << std::endl;
  for (int i = 0; i < 10; ++i)
    {
      std::cout << "int_arr[" << i << "] : " << int_arr[i] << std::endl;;
    }
  std::cout << "int_ref[0] : " << int_ref[0] << std::endl;
  std::cout << "*s_ptr[0]  : " << *s_ptr[0] << std::endl;
  std::cout << "**c        : " << **c << std::endl;
  std::cout << "ci         : " << ci << std::endl;
  std::cout << "*cip       : " << *cip << std::endl;
  std::cout << "*icp       : " << *icp << std::endl;
  
}
