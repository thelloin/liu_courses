#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const char* s)
{
  //std::cout << "Initialization\n" << string(s) << "Cleanup\n";
  return os << string("Initialization\n") << string(s) << string("Cleanup\n");
}

// Explicitly call the standard library version for const char*:
/*ostream& operator<<(ostream& os, const char* s)
{
  std::operator<<(os, "Initialization\n");
  std::operator<<(os, s);
  std::operator<<(os, "Cleanup\n");
  return os;
  }*/

int main()
{
  cout << "Hello!\n";
}
