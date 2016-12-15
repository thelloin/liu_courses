#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

/*
 * vector-06.cc
 * using templates
 */

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(begin(v), end(v), ostream_iterator<T>{cout, " "});
    return os;
}

template <typename T>
void heapsort(vector<T>& v)
{
    make_heap(begin(v), end(v));
    for (size_t i = 0; i < v.size(); ++i)
	pop_heap(begin(v), end(v) - i);
}

template <typename T, typename Compare>
void heapsort(vector<T>& v, const Compare& comp)
{
    //auto first = begin(v);
    //auto last = end(v);
    make_heap(begin(v), end(v), comp);
    /*while (last > first + 1)
	pop_heap(first, last--, comp);
    */
    for (auto it = end(v); it != begin(v); --it)
    {
	pop_heap(begin(v), it, comp);
    }
    
}

template <typename RandomAccessIterator>
void heapsort(RandomAccessIterator first, RandomAccessIterator last)
{
    make_heap(first, last);
    while (last > first + 1)
	pop_heap(first, last--);
}

template <typename RandomAccessIterator, typename Compare>
void heapsort(RandomAccessIterator first, RandomAccessIterator last, const Compare& comp)
{
    make_heap(first, last, comp);
    while (last > first + 1)
	pop_heap(first, last--, comp);
}

const int data[]{7, 4, 3, 9, 1, 5, 6, 2, 8};

int main()
{
    vector<int> v1{begin(data), end(data)};
    cout << v1 << '\n';
    heapsort(v1);
    cout << v1 << "\n\n";

    vector<int> v2{begin(data), end(data)};
    cout << v2 << '\n';
    heapsort(v2, std::greater<int>());
    cout << v2 << "\n\n";

    vector<int> v3{begin(data), end(data)};
    cout << v3 << '\n';
    heapsort(begin(v3), end(v3));
    cout << v3 << "\n\n";
       
    vector<int> v4{begin(data), end(data)};
    cout << v4 << '\n';
    heapsort(begin(v4), end(v4), std::greater<int>());
    cout << v4 << "\n\n";

    return 0;
}
