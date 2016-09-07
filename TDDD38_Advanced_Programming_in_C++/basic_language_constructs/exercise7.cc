#include <iostream>

int main()
{
  char msg[]{ "Hello, World" };
  std::string smsg{ "Hello, World" };

  std::cout << sizeof msg << std::endl;
  std::cout << sizeof smsg << std::endl;
  return 0;
}
