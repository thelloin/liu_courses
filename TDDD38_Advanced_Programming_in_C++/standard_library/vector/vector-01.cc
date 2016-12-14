#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*
 * vector-01.cc
 * Write a program which creates a vector<char> which stores the letters a-z
 * in order. Print the elements in the vector in order and in reverse order
 * using std::copy
 */

const char letters[] { "abcdefghijklmnopqrstuvqxyz" };

int main()
{
    vector<char> v(begin(letters), end(letters));

    cout << "The elements in order:\n";
    copy(begin(v), end(v), ostream_iterator<char>{cout, " "});
    cout << "\nThe elements in reverse order:\n";
    copy(rbegin(v), rend(v), ostream_iterator<char>{cout, " "});
    cout << '\n';
    return 0;
}
