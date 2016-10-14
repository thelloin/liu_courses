#include <iostream>
#include "ci_string.h"

using namespace std;

int main()
{
   ci_string s1 = "A string Here";
   ci_string s2 = "a STRING hErE";

   cout << "s1 = " << s1 << endl;
   cout << "s2 = " << s2 << endl;

   if (s1 == s2)
      cout << s1 << " == " << s2 << endl;
   else
      cout << s1 << " != " << s2 << endl;

   cout << "Skriv in ett ord: ";
   cin >> s1;
   cout << s1 << endl;
   return 0;
}
