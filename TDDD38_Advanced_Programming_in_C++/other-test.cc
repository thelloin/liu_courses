#include <iostream>
#include <initializer_list>
#include <string>

void fun1(std::initializer_list<int> il)
{
  for (auto x : il)
    std::cout << x << ' ';
  std::cout << '\n';
}

std::initializer_list<int> fun2()
{
  return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
}

struct S
{
  S(std::initializer_list<int> il)
  {
    for (auto x : il)
      std::cout << x << ' ';
    std::cout << '\n';
  }
};

int main()
{
  std::cout << "c) situations where std::initializer_list is involved, instead of array.\n";
  std::cout << "\n3) as function argument, parameter is std::initializer_list:\n";
  fun1({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

  std::cout << " \n4) in a return statement, destination is std::initializer_list:\n";
  auto il = fun2();
  fun1(il); // check result

  std::cout << "\n8) argument to a constructor invocation, parameter is std::initializer_list:\n";
  S s({ 0, 1, 2, 3, 4, 5 });

  return 0;
}
