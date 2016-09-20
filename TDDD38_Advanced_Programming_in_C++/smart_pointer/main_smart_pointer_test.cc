#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace Smart_Pointer;

void basic_tests();
void compare_tests();

int main()
{
  basic_tests();

  compare_tests();

  cout << "Just a little pointer test here:" << endl;
  int in{ 345 };
  int* poi{ &in };
  cout << "poi: " << poi << endl;
  cout << "&poi: " << &poi << endl;
  cout << "*poi: " << *poi << endl;
  cout << "&in: " << &in << endl;
  return 0;
}

void basic_tests()
{
cout << "Default constructor initialize to null pointer:\n";
  cout << "smart_pointer sp0\n\n";
  smart_pointer sp0;
  
  cout << "Using operator-> with ordinary member function call syntax:\n";
  cout << " sp0.operator->(): " << sp0.operator->() << "\n\n";

  // operator* applies the built-in operator* on the raw pointer ptr_, which
  // gives execution error for sp0, since ptr_ is a raw null pointer.
  // cout << "sp0.operator*(): " << sp0.operator*() << "\n\n";

  cout << "Constructor initializing with pointer to int object:\n";
  cout << "smart_pointer sp1{ new int{ 33 } };\n\n";
  smart_pointer sp1{ new int{ 33 } };

  cout << "Using operator-> with ordinary member function call syntax:\n";
  cout << "sp1.operator->(): " << sp1.operator->() << "\n\n";

  cout << "Using operator* with ordinary member function call syntax:\n";
  cout << "sp1.operator*(): " << sp1.operator*() << "\n\n";

  cout << "operator* applies the ordinary way (dereferencing)\n";
  cout << "*sp1: " << *sp1 << "\n\n";

  *sp1 = 11147;
  cout << "*sp1 = 11147 done:\n*sp1: " << *sp1 << "\n\n";

  cout << "Copy constructor used:\nsmart_pointer sp2{ sp1 };\n";
  smart_pointer sp2{ sp1 };
  cout << "*sp2: " << *sp2 << "\n\n";

  cout << "Copy assignment operator used:\nsp0 = sp2;\n";
  sp0 = sp2;
  cout << "*sp0: " << *sp0 << "\n\n";

  cout << "Move constructor used:\nsmart_pointer sp3{ std::move(sp2) };\n";
  smart_pointer sp3{ std::move(sp2) };
  cout << "*sp3: " << *sp3 << "\n\n";
  // Is supposed to work, but not with current implementation
  // cout << "*sp2: " << *sp2 << "\n\n";

  cout << "Move assignment operator used:\nsp2 = std::move(sp3);\n";
  sp2 = std::move(sp3);
  cout << "*sp2: " << *sp2 << "\n\n";
  // Is supposed to work, but not with current implementation
  // cout << "*sp3: " << *sp3 << "\n\n";

  cout << "Declaring and initializing a raw pointer:\n";
  cout << "int* px = new int{ 2 };\n";
  int* px = new int{ 2 };
  cout << "Assigning raw pointer:\nsp2 = px;\n";
  sp2 = px;
  cout << "*sp2: " << *sp2 << "\n\n";
  

  cout << "Declaring const smart_pointer:\n";
  cout << "const smart_pointer csp{ new int{ 0xc1 } };\n";
  const smart_pointer csp{ new int { 0xc1 } };
  // Shall be possible, but not with the current implementation:
  // cout << "*csp: " << *csp << "\n\n";

  // Shall not be possible, and is not with the current implementation:
  // csp = sp0;
  // *csp = nullptr;

  cout << "Copy assignment operator used:\nsp0 = csp;\n";
  sp0 = csp;
  cout << "*sp0: " << *sp0 << "\n\n";
}

void compare_tests()
{
  cout << "Declaring two smart_pointer, sp1 and sp2:\n";
  cout << "smart_pointer sp1{ new int{ 1 } };\n";
  cout << "smart_pointer sp2{ new int{ 2 } };\n";
  smart_pointer sp1{ new int{ 1 } };
  smart_pointer sp2{ new int{ 2 } };

  cout << "\nComparing two smart pointer using == and !=\n";
  if (sp1 == sp1) cout << "sp1 == sp1: true\n"; else cout << "sp1 == sp1: false\n";
  if (sp1 == sp2) cout << "sp1 == sp2: true\n"; else cout << "sp1 == sp2: false\n";
  if (sp1 != sp1) cout << "sp1 != sp1: true\n"; else cout << "sp1 != sp1: false\n";
  if (sp1 != sp2) cout << "sp1 != sp2: true\n"; else cout << "sp1 != sp2: false\n";

  cout << "Declaring a raw pointer:\n";
  cout << "int* p = new int{ 3 };\n";
  int* p = new int{ 3 };

  cout << "\nComparing smart pointers with raw pointer using == and !=\n";
  

}
