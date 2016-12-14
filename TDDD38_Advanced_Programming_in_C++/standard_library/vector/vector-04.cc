#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

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
	    
	}
};

int main()
{
    vector<string> cars{istream_iterator<string>{cin}, istream_iterator<string>()};

    

    return 0;
}
