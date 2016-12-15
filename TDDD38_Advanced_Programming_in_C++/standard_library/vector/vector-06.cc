#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * vector-06.cc
 * Implement heapsort on a vector using standard functions such as make_heap, pop_heap
 * and push_heap.
 */

int main()
{
    vector<int> v{5, 3, 1, 7, 6, 9, 2, 8, 4};
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
    cout << endl;
    make_heap(begin(v), end(v));
    cout << "after make_heap:\n";
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
    cout << endl;
    for (auto it = v.end(); it != v.begin(); --it)
    {
	pop_heap(begin(v), it);
    }
    copy(begin(v), end(v), ostream_iterator<int>{cout, " "});
    cout << endl;
    return 0;
}
