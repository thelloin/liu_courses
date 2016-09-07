#include <iostream>
#include <iomanip>

int main()
{
  unsigned u {0};
  bool b { false };
  double d { 0.0 };

  std::cout << std::endl;
  std::cout << "u = "    << u   << std::endl;
  std::cout << "u-- == " << u-- << std::endl;
  std::cout << "u = "    << u   << std::endl;
  std::cout << "++u == " << ++u << std::endl;
  std::cout << "u = "    << u   << std::endl;

  std::cout << std::endl << std::boolalpha;
  std::cout << "b = "    << b   << std::endl;
  std::cout << "b++ == " << b++ << std::endl; 
  std::cout << "b = "    << b   << std::endl;
  std::cout << "b++ == " << b++ << std::endl;
  std::cout << "b = "    << b   << std::endl;

  b = false;
  std::cout << std::endl;
  std::cout << "b = "    << b   << std::endl;
  std::cout << "++b == " << ++b << std::endl;
  std::cout << "b = "    << b   << std::endl;

  /*  b--;  Illegal! */
  /*  --b;  Illegal! */

  std::cout << std::fixed << std::setprecision(1) << std::endl;
  std::cout << "d = "    << d   << std::endl;
  std::cout << "d++ == " << d++ << std::endl;
  std::cout << "d = "    << d   << std::endl;
  std::cout << std::endl;

  return 0;
}
