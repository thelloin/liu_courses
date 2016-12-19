#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

/*
 * vector-08.cc
 */

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(begin(v), end(v), ostream_iterator<T>{cout, " "});
    return os;
}

template <int size, typename T = string>
struct longer_than
{
    bool operator()(const T& arg)
	{
	    return size < arg.size();
	}
};

const vector<string> remove_word { "a", "and", "but", "do", "if", "in", "is", "its", "not", "of", "or", "that", "the", "to" };

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
	cout << "usage: " << argv[0] << "<filename>\n";
	return 1;
    }

    ifstream input{ argv[1] };

    if (!input)
    {
	cout << argv[1] << " : could not open.\n";
	return 2;
    }

    //vector<string> words{istream_iterator<string>{input}, istream_iterator<string>() };
    vector<string> words;
    copy(istream_iterator<string>{input}, istream_iterator<string>{},
	 back_inserter(words));
    // Sort the words
    sort(begin(words), end(words));
    cout << "Words read:\n" << words << "\n\n";

    // Remove duplicates
    words.erase(unique(begin(words), end(words)), end(words));
    cout << "After removing duplicates:\n" << words << "\n\n";

    // Sort with respect to word length and keep alphabetic order
    stable_sort(begin(words), end(words), [](const string& l, const string& r)
		{ return l.length() < r.length(); });
    cout << "After sorting by word length:\n" << words << "\n\n";

    // Count # of words longer than 5
    auto n = count_if(begin(words), end(words), longer_than<5>());
    cout << "Number of words longer than 5 letters are:\n" << n << ".\nPercentage: " << ((float)n/(float)words.size())*100.0 << "\n\n";

    // Remove common words
    for ( const auto& word : remove_word )
    {
	words.erase( remove(begin(words), end(words), word ), end(words) );
    }
    cout << "After removing common words:\n" << words << "\n\n";

    return 0;
}
