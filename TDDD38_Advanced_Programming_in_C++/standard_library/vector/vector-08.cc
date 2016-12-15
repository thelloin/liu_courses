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
    cout << "Words read:\n" << words << "\n\n";

    return 0;
}
