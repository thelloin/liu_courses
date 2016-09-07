#include <iostream>
#include <cstring>

int main()
{
  char str1[100]{ "String" }; // Will have size 100
  std::cout << sizeof str1 << std::endl;
  std::cout << std::strlen(str1) << std::endl;

  char str2[]{ "String" }; // Will have size 7, "String" + \0
  std::cout << sizeof str2 << std::endl;
  std::cout << std::strlen(str2) << std::endl;

  const char* str3{ "String" }; // Will have size of pointer, 8 on a 64-bit machine
  std::cout << sizeof str3 << std::endl;

  std::string str4{ "String" };
  std::cout << sizeof str4 << std::endl;
  std::cout << str4.size() << std::endl;

  return 0;
}
