/*
 * container-test.cc    Container Step 3
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
#include <utility>
using namespace std;

using Trace = Tracer<string>;

int main()
{
   Trace::on();
   cout << boolalpha;

   cout << "Container<Trace> c1;\n";
   Container<Trace> c1;
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "c1.empty()    = " << c1.empty()    << "\n\n";

   cout << "Trace one{ \"one\" };\nc1.push_back(one)\n";
   Trace one{ "one" };
   c1.push_back(one);
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "c1.empty()    = " << c1.empty()    << "\n\n";

   cout << "c1.push_back(Trace(\"two\"))\n";
   c1.push_back(Trace("two"));
   cout << "c1.push_back(Trace(\"three\"))\n";
   c1.push_back(Trace("three"));
   cout << "c1.push_back(Trace(\"four\"))\n";
   c1.push_back(Trace("four"));
   cout << "c1.push_back(Trace(\"five\"))\n";
   c1.push_back(Trace("five"));
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "Making a const copy of c1 in c2 (shrink-to-fit)\n";
   const Container<Trace> c2{ c1 };
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";

   while (! c1.empty())
   {
      try
      {
	 cout << "c1.back() = " << c1.back() << '\n';
	 cout << "Removing last element\n";
	 c1.pop_back();
      }
      catch (const exception& e)
      {
	 cout << "Exception caught: " << e.what() << '\n';
      }
      catch (...)
      {
	 cout << "Unknown exception caught:\n";
      }
   }

   cout << "\nProgram ends.\n";

   return 0;
}
