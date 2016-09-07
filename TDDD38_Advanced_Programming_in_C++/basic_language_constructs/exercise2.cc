#include <iostream>
#include <string>
#include <vector>

char c;                     // Definition
std::string s;              // Definition
auto count{1};              // Definition
const int MAX{4711};        // Definition
extern double d;            // Declaration
const char* msg{"Hello!"};  // Definition
const char* Direction[]{"up", "down", "left", "right"}; // Definition
struct Time { int h, m, s; }; // Definition
int sec(Time* p) { return p->s; } // Definition
template<typename T> T abs(T a) { return (a < 0) ? -a : a; } // Definition
namespace N { int i; }           // Definition
double sqrt(double);          // Declaration
typedef std::vector<double> data; // Definition
using char_ptr = char*;           // Definition
struct Node;                      // Declaration
enum Season { Spring, Summer, Autumn, Winter }; // Definition


int main()
{
  std::cout << "Size of char c            : " << sizeof(c) << std::endl;
  std::cout << "Size of string s          : " << sizeof(s) << std::endl;
  std::cout << "Size of auto count        : " << sizeof(count) << std::endl;
  std::cout << "Size of int MAX           : " << sizeof(MAX) << std::endl;
  std::cout << "Size of extern double d   : " << sizeof(d) << std::endl;
  std::cout << "Size of char* msg         : " << sizeof(msg) << std::endl;
  std::cout << "Size of char* Direction[] : " << sizeof(Direction) << std::endl;
  std::cout << "Size of struct Time       : " << sizeof(Time) << std::endl;
  //std::cout << "Size of int sec : " << sizeof(sec) << std::endl; // Funktionstyp
  //std::cout << "Size of abs               : " << sizeof(abs) << std::endl; // Funktionstyp
  std::cout << "Size of int N::i          : " << sizeof(N::i) << std::endl;
  //std::cout << "Size of double sqrt(double) : " << sizeof(sqrt) << std::endl; // Funktionstyp
  std::cout << "Size of data              : " << sizeof(data) << std::endl;
  std::cout << "Size of char_ptr          : " << sizeof(char_ptr) << std::endl;
  //std::cout << "Size of struct Node       : " << sizeof(Node) << std::endl; // Ofullständig typ
  std::cout << "Size of enum Season       : " << sizeof(Season) << std::endl;
  return 0;
}
