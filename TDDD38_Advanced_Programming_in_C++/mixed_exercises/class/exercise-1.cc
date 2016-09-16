#include <iostream>
#include <string>
using namespace std;

class Integer
{
public:
  Integer(int i) : i_(i) {}
  operator int() const { return i_; }
private:
  int i_;
};

struct Ten
{
  operator Integer() const { return Integer(10); }
};

int main()
{
  Integer i = 10;
  const char* hex = "0123456789ABCDEF";

  char d = hex[i];
  cout << d << endl;

  Ten ten;
  //d = hex[ten]; // Error, two implicit user-defined conversions in a row
                // is not allowed

  d = hex[ten.operator Integer()]; // Integer::operator int() is then applied implicity
  d = hex[Integer(ten)]; // The same, but with conventional syntax

  cout << d << endl;

  d = hex[ten.operator Integer().operator int()]; // Both conversion functions explicity called
  d = hex[int(Integer(ten))]; // The same, but with conventional syntax

  cout << d << endl;

  return 0;
}
