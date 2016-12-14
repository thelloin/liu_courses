#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * vector-03.cc
 * Rewrite exercise 2. Instead of printing all the cars in the vector, use
 * a for loop to only print the cars which begins with a certain letter,
 * for example 'A'
 */

int main()
{
    vector<string> v{ istream_iterator<string>{cin}, istream_iterator<string>() };
    sort(begin(v), end(v));
    cout << "Using a ordinary for-loop:\n";
    for (size_t i = 0; i < v.size(); ++i)
    {
	if (!v.empty() && v[i][0] == 'A')
	    cout << v[i] << '\n';
    }
    cout << "\nUsing iterators:\n";
    for( auto it = v.cbegin(); it != v.cend(); ++it)
    {
	if ( (*it)[0] == 'A')
	    cout << *it << '\n';
    }

    cout << "\nUsing a ranged based for loop:\n";
    for ( const auto& car : v )
    {
	if (car[0] == 'A')
	    cout << car << '\n';
    }
    
    
    return 0;
}
