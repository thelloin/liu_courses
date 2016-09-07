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
typedef std::vector<double> data; // Declaration
using char_ptr = char*;           // Declaration
struct Node;                      // Declaration
enum Season { Spring, Summer, Autumn, Winter }; // Declaration


int main()
{
  return 0;
}
