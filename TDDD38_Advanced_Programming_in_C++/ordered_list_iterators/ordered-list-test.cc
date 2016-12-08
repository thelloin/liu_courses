/*
 * ordered-list-test.cc
 */
#include "Ordered_List.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>
using namespace std;

namespace std
{
   template<typename T, typename Compare>
   ostream& operator<<(ostream& os, const Ordered_List<T, Compare>& list)
   {
      copy(begin(list), end(list), ostream_iterator<T>(cout, " "));
      return os;
   }
}

int main()
{
   Ordered_List<int, std::greater<int>> list_1;
      cout << "New sorted list (list 1), with std::greater as comparer, created.\n";

   if (list_1.empty())
      cout << "List 1 is empty.\n";
   else
      cout << "List 1 is not empty.\n";

   cout << "Inserting 4, 5, 6, 3, 2, 1 in list 1.\n";
   for (auto x : { 4, 5, 6, 3, 2, 1 })
      list_1.insert(x);

   if (list_1.empty())
      cout << "List 1 is empty.\n";
   else
      cout << "List 1 is not empty.\n";

   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Erasing 4 from list 1.\n";
   list_1.erase(4);
   
   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Erasing 1 from list 1.\n";
   list_1.erase(1);
   
   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Erasing 6 from list 1.\n";
   list_1.erase(6);
   
   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Clearing list 1.\n";
   list_1.clear();

   if (list_1.empty())
      cout << "List 1 is empty.\n";
   else
      cout << "List 1 is not empty.\n";

   cout << "Inserting 1, 2, 3 in list 1.\n";
   for (auto x : { 1, 2, 3 })
      list_1.insert(x);

   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Creating a copy (list 2) of list 1.\n";
   Ordered_List<int, std::greater<int> > list_2(list_1);
   cout << "List 2 contains:\n";
   cout << list_2 << '\n';
   cout << "List 1 contains:\n";
   cout << list_1 << '\n';

   cout << "Creating a new empty list (list 3).\n";
   Ordered_List<int, std::greater<int> > list_3;
   cout << "List 3 contains:\n";
   cout << list_3 << '\n';

   cout << "Assigning list 2 to list 3.\n";
   list_3 = list_2;
   cout << "List 3 contains:\n";
   cout << list_3 << '\n';
   cout << "List 2 contains:\n";
   cout << list_2 << '\n';

   cout << "Clearing list 2.\n";
   list_2.clear();

   cout << "Move assigning list 3 to list 2.\n";
   list_2 = std::move(list_3);
   cout << "List 2 contains:\n";
   cout << list_2 << '\n';
   cout << "List 3 contains:\n";
   cout << list_3 << '\n';

   cout << "Move constructing new list (list 4) from list 2.\n";
   Ordered_List<int, std::greater<int> > list_4(std::move(list_2));

   cout << "List 4 contains:\n";
   cout << list_4 << '\n';
   cout << "List 2 contains:\n";
   cout << list_2 << '\n';

   cout << "Lists are destroyed.\n";

   return 0;
}
