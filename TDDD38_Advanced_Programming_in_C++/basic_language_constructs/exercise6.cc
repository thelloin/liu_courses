#include <iostream>

using x = int(&)(int, int); // x is a reference to a function taking to ints, returning int

int foo(int, int);

int main()
{
  x y{ foo };

  std::cout << y(1, 2) << std::endl;

  return 0;
}

int foo(int i, int j)
{
  return i + j;
}
