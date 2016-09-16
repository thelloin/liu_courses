/*
 * The type conversion constructor Integer(int) in combination with
 * declaring the binary operators as free functions will allow all
 * variants of mixed expressions with arithmetic types. Declaring the
 * constructor 'explicit' would eliminate those possibilities, and
 * require explicit overloading for such mixed cases.
 */
#include <iostream>
using namespace std;

class Integer
{
public:
  Integer(int i) : i_(i) {}
  Integer(const Integer& value) : i_(value.i_) {}

  /* Compiler generated copy assignment and destruction is fine. */

  Integer operator+(); // Unary +
  Integer operator-(); // Unary -

  friend Integer operator+(const Integer& lhs, const Integer& rhs);
  friend Integer operator-(const Integer& lhs, const Integer& rhs);
  friend Integer operator*(const Integer& lhs, const Integer& rhs);
  friend Integer operator/(const Integer& lhs, const Integer& rhs);
  friend Integer operator%(const Integer& lhs, const Integer& rhs);

  Integer& operator++();
  Integer operator++(int); // postfix ++
  Integer& operator--();
  Integer operator--(int); // postfix --

  friend std::ostream& operator<<(ostream& os, const Integer& i);
  friend std::istream& operator>>(istream& is, Integer& i);

private:
  int i_;
};

/*
 * Unary + and - for Integer objects.
 */
Integer Integer::operator+()
{
  return Integer(i_);
}

/*
 * Binary +, -, *, /, and % for Integer objects.
 */
Integer Integer::operator-()
{
  return Integer(i_);
}

Integer operator+(const Integer& lhs, const Integer& rhs)
{
  return Integer(lhs.i_ + rhs.i_);
}

Integer operator-(const Integer& lhs, const Integer& rhs)
{
  return Integer(lhs.i_ - rhs.i_);
}

Integer operator*(const Integer& lhs, const Integer& rhs)
{
  return Integer(lhs.i_ * rhs.i_);
}

Integer operator/(const Integer& lhs, const Integer& rhs)
{
  return Integer(lhs.i_ / rhs.i_);
}

Integer operator%(const Integer& lhs, const Integer& rhs)
{
  return Integer(lhs.i_ % rhs.i_);
}

Integer& Integer::operator++() // prefix
{
  ++i_;
  return *this;
}

Integer Integer::operator++(int) // postfix
{
  Integer tmp(i_);
  ++i_;
  return tmp;
}

Integer& Integer::operator--() // prefix
{
  --i_;
  return *this;
}

Integer Integer::operator--(int) // postfix
{
  Integer tmp(i_);
  --i_;
  return tmp;
}

/*
 * Formatted I/O for Integer.
 */
// std::ostream?
std::ostream& operator<<(ostream& os, const Integer& i) // Integer& för att göra den tillgänglig?
{
  return os << i.i_;
}

std::istream& operator>>(istream& is, Integer& i)
{
  return is >> i.i_;
}

int main()
{
  Integer i(10);

  cout << "i   == " << i   << endl << endl;
  cout << "i++ == " << i++ << endl;
  cout << "i   == " << i   << endl;
  cout << "i-- == " << i-- << endl;
  cout << "i   == " << i   << endl << endl;

  cout << "++i == " << ++i << endl;
  cout << "i   == " << i   << endl;
  cout << "--i == " << --i << endl;
  cout << "i   == " << i   << endl << endl;

  cout << "+i == " << +i << endl;
  cout << "-i == " << -i << endl << endl;

  cout << "i + i == " << i + i << endl;
  cout << "i - i == " << i - i << endl;
  cout << "i * i == " << i * i << endl;
  cout << "i / i == " << i / i << endl;
  cout << "i % i == " << i % i << endl << endl;

  cout << "i + 5 == " << i + 5 << endl;
  cout << "5 + i == " << 5 + i << endl;

  cout << "i - 5 == " << i - 5 << endl;
  cout << "5 - i == " << 5 - i << endl << endl;

  cout << "i + 'A' == " << i + 'A' << endl;
  // cout << "i + 3.5 == " << i + 3.5 << endl;

  return 0;
}
