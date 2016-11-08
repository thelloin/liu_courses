/*
 * container-test.cc  Container Step 1, initializing and destroying container objects.
 *
 * Tracer helper class is used to trace use of operations on Tracer objects,
 * i.e. to find out the requirements Container puts on the contained objects.
 * To not get misleading traces, the test program as such must no require any
 * temporary objects of type Tracer.
 */
#include "Container.h"
#include "Tracer.h"
#include <iostream>
#include <string>

using namespace std;

using Trace = Tracer<string>;

int main()
{
   Trace::on();
   cout << boolalpha;

   cout << "c1 is default initialized.\n";
   Container<Trace> c1;
   cout << "c1.size()      = " << c1.size()        << '\n';
   cout << "c1.max_size()  = " << c1.max_size()    << '\n';
   cout << "c1.capacity()  = " << c1.capacity()    << '\n';
   cout << "c1.empty()     = " << c1.empty()       << '\n';

   cout << "c2 is initialized to size 5 (elements are default initialized).\n";
   Container<Trace> c2{ 5 };
   cout << "c2.size()      = " << c2.size()        << '\n';
   cout << "c2.max_size()  = " << c2.max_size()    << '\n';
   cout << "c2.capacity()  = " << c2.capacity()    << '\n';
   cout << "c2.empty()     = " << c2.empty()       << '\n';

   cout << "Program ends.\n";

   return 0;
}
