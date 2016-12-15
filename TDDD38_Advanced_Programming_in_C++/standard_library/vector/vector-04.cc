#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <functional>

using namespace std;
using namespace std::placeholders; // for _1

/*
 * vector-04.cc
 * Rewrite exercise 2. Just print those cars fulfilling a predicate. Define a binary
 * predicate, which takes two strings and checks if the first character of the first
 * string is equal to any of the characters in the second string, regardless of case.
 */

struct Func
{
    bool operator()(const string& first, const string second)
	{
	    for (auto c : second)
	    {
		if (tolower(c) == tolower(first[0]))
		    return true;
	    }
	    return false;
	}
};

int main()
{
    vector<string> cars{istream_iterator<string>{cin}, istream_iterator<string>()};

    sort(begin(cars), end(cars));

    copy_if(begin(cars), end(cars), ostream_iterator<string>{cout, "\n"},
	 bind(Func(), _1, "ABC"));
    

    return 0;
}
