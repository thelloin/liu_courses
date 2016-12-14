#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * vector-02.cc
 * Create a vector<string> and read a list with names of car brands into
 * the vector. Sort the list using std::sort and print the result using 
 * std::copy. There is a given text file with car brands, named
 * cars_of_the_world.txt.
 */

int main()
{
    vector<string> v{ istream_iterator<string>{cin}, istream_iterator<string>() };
    sort(begin(v), end(v));
    cout << "The cars in sorted order:\n";
    copy(cbegin(v), cend(v), ostream_iterator<string>{cout, " "});
    cout << endl;
    
    return 0;
}
