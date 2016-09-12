#include <iostream>
using namespace std;

int main()
{
  int n{ 20 };
  for (int i{ 0 }; i<n; --i) // Change --i to --n
    cout << 'x' << endl;
  /*
   * You could change 'x' << endl to "x\n" because it's not
   * neccessary to flush the buffer to stdout every iteration,
   * which is what endl does.
   */
  return 0;
}
