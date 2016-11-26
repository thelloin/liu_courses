#include <iostream>
#include "Container.h"

using namespace std;

int main()
{
    
    cout << "Declaring: Container<Trace> c1;  // default ctor\n";
    Container<string> c1;
    cout << "c1.size()     = " << c1.size()     << '\n';
    cout << "c1.capacity() = " << c1.capacity() << '\n';
    cout << "c1.empty()    = " << c1.empty()    << "\n\n";

    cout << "Declaring: Trace one{ \"one)\" };\n";
    //Trace one{ "one" };
    cout << "\nc1.push_back(one)\n";
    c1.push_back("one");
    cout << "c1.size()     = " << c1.size()     << '\n';
    cout << "c1.capacity() = " << c1.capacity() << '\n';
    cout << "c1.empty()    = " << c1.empty()    << "\n\n";

    cout << "Declaring: Trace two()\"two)\");\n";
    //Trace two{ "two" };
    cout << "\nc1.push_back(two)\n";
    c1.push_back("two");
    cout << "###############################" << endl;;
    cout << "c1.size()     = " << c1.size()     << '\n';
    cout << "c1.capacity() = " << c1.capacity() << '\n';
    cout << "\nc1.push_back(Trace(\"three\"))\n";
    c1.push_back("three");

    return 0;
}
