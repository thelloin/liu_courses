/*
 * ordered-list-iterator-test.c
 */
#include "Ordered_List.h"
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
   cout << "New list initialized with { 1, 2, 3, 4, 5, 6, 7, 8, 9 }\n";
   Ordered_List<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   cout << "List contains (iterator, member begin() and end(), prefix operator++, operator!=, and operator* used):\n";
   for (Ordered_List<int>::iterator it = list.begin(); it != list.end(); ++it)
   {
      cout << *it << ' ';
   }
   cout << '\n';

   cout << "List contains (const_iterator, member cbegin() and cend(), postfix operator++, operator!=, and operator* used):\n";
   for (Ordered_List<int>::const_iterator it = list.cbegin(); it != list.cend(); it++)
   {
      cout << *it << ' ';
   }
   cout << '\n';

   cout << "List contains (iterator, range access begin() and end(), prefix operator++, operator!=, and operator* used):\n";
   for (auto it = begin(list); it != end(list); ++it)
   {
      cout << *it << ' ';
   }
   cout << '\n';

   cout << "List contains (range based for statement used):\n";
   for (auto x : list)
   {
      cout << x << ' ';
   }
   cout << '\n';

   cout << "List contains (algorithm copy, range access begin() and end(), and ostream_iterator used):\n";
   copy(begin(list), end(list), ostream_iterator<int>(cout, " "));
   cout << '\n';

   cout << "Multiplying all elements in list by 2 (iterator used).\n";
   for (Ordered_List<int>::iterator it = begin(list); it != end(list); ++it)
   {
      *it *= 2;
   }
   
   cout << "List contains:\n";
   copy(begin(list), end(list), ostream_iterator<int>(cout, " "));
   cout << '\n';   
 
   return 0;
}
