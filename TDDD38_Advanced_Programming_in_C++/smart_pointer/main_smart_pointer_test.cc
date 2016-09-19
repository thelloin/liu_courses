#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace Smart_Pointer;

int main()
{
  cout << "Default constructor initialize to null pointer:\n";
  cout << "smart_pointer sp0\n\n";
  smart_pointer sp0;
  
  cout << "Using operator-> with ordinary member function call syntax:\n";
  cout << " sp0.operator->(): " << sp0.operator->() << "\n\n";

  cout << "We are here" << endl;
  return 0;
}
