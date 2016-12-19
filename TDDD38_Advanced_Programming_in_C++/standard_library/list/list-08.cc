#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const list<T>& l)
{
    copy(begin(l), end(l), ostream_iterator<T>{cout, " "});
    return os;
}

template <typename T>
struct by_length
{
    bool operator()(const T& l, const T& r) const
	{
	    return l.size() < r.size();
	}
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
	cout << "Usage : " << argv[0] << " <filename>\n";
	return 1;
    }

    ifstream inFile { argv[1] };
    if( !inFile )
    {
	cout << "Could not open file : " << argv[1] << '\n';
	return 2;
    }

    list<string> words;
    copy(istream_iterator<string>{inFile}, istream_iterator<string>(), back_inserter(words));
    //list<string> words { istream_iterator<string>{inFile}, istream_iterator<string>() };
    cout << "The list:\n" << words << "\n\n";

    // Sort the list
    words.sort();
    cout << "The sorted list:\n" << words << "\n\n";

    // Remove duplicates from the list
    words.unique();
    cout << "After removing duplicates:\n" << words << "\n\n";

    // Sort by size
    words.sort(by_length<string>());
    cout << "After sorting by length:\n" << words << "\n\n";

    return 0;
}
