/*
 * container-test.cc    Container Step 7, Storage management redesigned.
 *
 * Tracer helper class is used to trace use of operations on Tracer objects,
 * i.e. to find out the requirements Container puts on the contained objects.
 * To not get misleading traces, the test program as such must no require any
 * temporary objects of type Tracer.
 */
#include <iostream>
#include <string>
#include "Container.h"
#include "Tracer.h"
using namespace std;

typedef Tracer<string> Trace;

int main()
{
   Trace::on();
   cout << boolalpha;

   cout << "Declaring: Container<Trace> c1;  // default ctor\n";
   Container<Trace> c1;
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "c1.empty()    = " << c1.empty()    << "\n\n";

   cout << "Declaring: Trace one{ \"one)\" };\n";
   Trace one{ "one" };
   cout << "\nc1.push_back(one)\n";
   c1.push_back(one);
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "c1.empty()    = " << c1.empty()    << "\n\n";

   cout << "Declaring: Trace two()\"two)\");\n";
   Trace two{ "two" };
   cout << "\nc1.push_back(two)\n";
   c1.push_back(two);
   cout << "###############################" << endl;;
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "\nc1.push_back(Trace(\"three\"))\n";
   c1.push_back(Trace("three"));
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "\nc1.push_back(Trace(\"four\"))\n";
   c1.push_back(Trace("four"));
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << '\n';
   cout << "\nc1.push_back(Trace(\"five\"))\n";
   c1.push_back(Trace("five"));
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "Declaring: Container<Trace> c2{ c1 }; // copy ctor, shrink-to-fit\n";
   Container<Trace> c2{ c1 };
   cout << "c2.size()     = " << c2.size()     << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "c1.push_back(Trace(\"six\"));\n";
   c1.push_back(Trace("six"));
   cout << "c1.size()     = " << c1.size()     << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";
   

   cout << "Clearing: c2.clear();\n";
   c2.clear();
   cout << "c2.size()     = " << c2.size()     << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";

   cout << "Assigning: c2 = c1; // copy assignment, shrink-to-fit\n";
   c2 = c1;
   cout << "c2.size()     = " << c2.size()     << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";

   cout << "Declaring: Container<Trace> c3{ std::move(c2) };  // move ctor\n";
   Container<Trace> c3{ std::move(c2) };
   cout << "c2.size()     = " << c2.size()     << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';
   cout << "c3.size()     = " << c3.size()     << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";

   cout << "c3.push_back(Trace(\"seven\"));\n";
   c3.push_back(Trace("seven"));
   cout << "c3.size()     = " << c3.size()     << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";


   cout << "Assigning: c2 = std::move(c3));  // move assign optor\n";
   c2 = std::move(c3);
   cout << "c2.size()     = " << c2.size()     << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';
   cout << "c3.size()     = " << c3.size()     << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";

   cout << "Removing elements from c1, until empty:\n";
   cout << "  c1.size() = " << c1.size()     << '\n';
   while (! c1.empty())
   {
      try
      {
	 cout << "  c1.back() = " << c1.back() << '\n';
	 cout << "  Removing last element\n";
	 c1.pop_back();
	 cout << "  c1.size() = " << c1.size() << '\n';
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
