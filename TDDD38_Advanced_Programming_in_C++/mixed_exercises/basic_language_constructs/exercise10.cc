#include <iostream>

// Function declaration for the specified function
void f(char*, int&);

// Alias declarations
using pf = void(*)(char*, int&);  // Pointer to a function like f above
using f2 = void(pf);              // Function taking such a pointer a argument
using f3 = pf();                  // Function returning such a pointer

// Corresponding typedefs:
//typedef void(*pf)(char*, int&);
//typedef void f2(pf);
//typedef pf f3();

void g(pf);
pf h();

int main()
{
  int i = 4711;
  char s[]{ "C++" };

  pf fp{ f };
  fp(s, i);

  g(f);

  h()(s, i);

  return 0;
}

void f(char* s, int& r)
{
  std::cout << s << ", " << r << std::endl;
}

void g(pf f)
{
  int i { 11147 };
  char s[]{ "C" };
  f(s, i);
}

pf h()
{
  return f;
}
