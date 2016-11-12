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

   cout << "c1 is default initialized.\n";
   Container<Trace> c1;  // default constructor
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "c2 is initialized to size 5 (elements are default initialized).\n";
   Container<Trace> c2{ 5 };
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";

   cout << "c3 is copy initialized with c2.\n";
   Container<Trace> c3{ c2 };  // copy constructor
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << '\n';   
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";
   
   cout << "c3 = c2;\n";
   c3 = c2;  // copy assignment operator
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << '\n';   
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << "\n\n";
   
   cout << "c3 = c1;\n";
   c3 = c1;  // copy assignment operator
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << '\n';   
   cout << "c1.size()     = " << c1.size() << '\n';
   cout << "c1.capacity() = " << c1.capacity() << "\n\n";

   cout << "c2.swap(c3);\n";
   c3.swap(c2);
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";   

   cout << "swap(c2, c3);\n";
   swap(c2, c3);
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';
   cout << "c3.size()     = " << c3.size() << '\n';
   cout << "c3.capacity() = " << c3.capacity() << "\n\n";   

   cout << "c2.clear();\n";
   c2.clear();
   cout << "c2.size()     = " << c2.size() << '\n';
   cout << "c2.capacity() = " << c2.capacity() << '\n';   

   cout << "\nProgram ends.\n";
   return 0;
}
