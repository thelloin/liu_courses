#include <iostream>

// The following three declarations declares the same function

int a(int i);
int a(int);       // Parameter name omitted
int a(int (i));   // Redundant parenthesis around parameter name

// As do these four

int a(int (*b)()); // a takes a function with no parameters returning int
int a(int (*)());  // Parameter function name omitted
int a(int b());    // Parameter b is implicity a function pointer
int a(int ());     // Parameter function name omitted

int foo();

int main()
{
  std::cout << a(2) << std::endl;

  std::cout << a(foo) << std::endl;

  return 0;
}

int a(int i)
{
  return i * 2;
}

int a(int b())
{
  return b();
}

int foo()
{
  return 4711;
}
