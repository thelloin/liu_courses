#include <string>
#include <vector>
#include <iostream>
#include <set>
#include "print.h"

using namespace std;

int main()
{
   vector<int> a {3, 5, 7};
   print(a);
   cout << endl;
   print(2, vector<int>{2,3,5,6}, "Hello", 3.4, string{"jamie"}, 'd', vector<string>{"C++", "is", "fun"}, set<float>{1.0,2.1,3.2});
   cout << endl;
   a.push_back(234);
   print(a);
   cout << endl;
   vector< vector<string> > vec {{"aaa", "bbb"}, {"ccc"}};
   print(vec);
   cout << endl;
   return 0;
}
