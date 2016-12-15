#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*
 * vector-07.cc
 * Read one integer at a time from cin, and use binary_search on a vector to see if
 * the value is in the vector.
 */

int main()
{
    vector<int> v {5, 4, 3, 1, 6, 7, 8 ,9};
    sort(begin(v), end(v), greater<int>());
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
    cout << endl;

    int val;
    while (cin >> val)
    {
	if (binary_search(begin(v), end(v), val, greater<int>()))
	    cout << val << " is in the vector.\n";
    }
    return 0;
}
