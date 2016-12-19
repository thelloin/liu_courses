#include <list>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

const char letters[] { "abcdefghijklmnopqrstuvxyz" };

int main()
{

    list<char> l ( begin(letters), end(letters) );

    cout << "The list in order:\n";
    copy( begin(l), end(l), ostream_iterator<char>{cout, " "} );

    cout << "\n\nThe list in reverse order:\n";
    copy( crbegin(l), crend(l), ostream_iterator<char>{cout, " "} );
    cout << endl;
    return 0;
}
