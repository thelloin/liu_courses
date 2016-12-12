/*
 * given.cc
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Give alias declarations for pair<string, int> and vector<pair<string, int>>.
using pair_si = pair<string, int>;
using vector_psi = vector<pair_si>;

// Declare overloading a function insert(string, vector<pair_si> for inserting a
// string into a verctor, in a copy and a move version regarding the string.
void insert(const string& s, vector_psi& vector);
void insert(string&& s, vector_psi& vector);

// Declare overloadings operator<< for pair and vector (beware of ADL).
namespace std
{
    ostream& operator<<(ostream&, const pair_si&);
    ostream& operator<<(ostream&, const vector_psi&);
}

int main()
{
   vector<pair<string, int>> v;  // replace with alias
   string s;

   while (cin >> s)
   {
      insert(s, v);  // test copy and move version!
   }

   // Print the content of the vector, with each entry on a line of its own.
   cout << v << endl;

   return 0;
}

// Define the overloadings of insert()

// Define the overloadings of operator<<
