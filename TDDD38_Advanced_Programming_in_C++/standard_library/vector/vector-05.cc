#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

/*
 * Rewrite exercise 2. Before printing the cars, their names are to be lower-cased.
 * Define a object class to lower the letters in a string. Use transform and such 
 * a function object to iterate over all cars.
 */

struct lower_case
{
    string operator()(string s) const
	{
	    transform(begin(s), end(s), begin(s), ::tolower);
	    return s;
	}
};

int main()
{
    vector<string> cars{istream_iterator<string>{cin}, istream_iterator<string>()};

    sort(begin(cars), end(cars));

    transform(begin(cars), end(cars), begin(cars), lower_case());
    copy(begin(cars), end(cars), ostream_iterator<string>{cout, " "});

    return 0;
}
