#include <iostream>

struct S
{
  int a5[5]{ 1, 2, 3, 4 };

  // Constructor
  S() : a6{ 6, 6 } {}
  int a6[6];
};

// How to pass array dimensions to function
template<typename T, int N>
void print_array(T (&a)[N]) // a is a reference to array with type int[N]
{
  for (auto x : a)
    std::cout << x << ' ';
  std::cout << '\n';
}

int main()
{
  std::cout << "a) array aggregates.\n";

  std::cout << "\n1) initializer in a array definition:\n";
  int a[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  print_array(a);

  std::cout << "\n2) initializer in a new[] expression:\n";
  int* p = new int[5]{ 1, 2, 3 };

  for (auto it { p }; it != p + 5; ++it)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "\n3) as a function argument - not if parameter is array.\n";
  std::cout << "\n4) as a return statement - not if destination is array.\n";

  std::cout << "\n5 initializer for non-static array data member\n";
  S s;
  print_array(s.a5);

  std::cout << "\n6) array member initialization:\n";
  print_array(s.a6);

  std::cout << "\n7) on the right-hand side of an assignment - not if left-hand is array.\n";
  std::cout << "\n8) argument to a constructor invocation - not if parameter is array.\n";

  return 0;
}
