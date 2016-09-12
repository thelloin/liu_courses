#include <iostream>
#include <chrono>

#include <unordered_map>
#include <vector>
#include <functional>
#include <math.h>
#include <stdio.h>
#include <utility>
#include <bitset>

#include "Key.h"

using namespace std;

/*******************************************
 * Dom ändringar som gjorts:
 *     - Lagt till ett antar couts
 *     - Ändrat bitset storlek på 3 ställen: (N + 1)
 *           rad 55
 *           rad 192
 *           rad 206
 ******************************************/

class key_hash
{
  public:
    long operator()(const Key& x) const
    {
      long hash = 0;

      for (int i{N - 1}; i >= 0; i--)
	{
	  hash +=  KEYbit(x, i) * pow(2.0, i);
	}
      return hash;
    }
};
/*
class key_equal_to
{
  public:
     bool operator()(const Key& a, const Key& b) const
     {
       for( int i{0}; i < C; ++i)
	 {
	   if( a.digit[i] != b.digit[i] )
	     return false;
	 }
        return true;
     }
};*/


void BitToString(bitset<N> b)
{
  //cout << "We are here 4" << endl;
  string BitString = b.to_string<char,string::traits_type,string::allocator_type>();
  BitString = string (BitString.rbegin(), BitString.rend());
  //cout << "Possible password: " << BitString << endl;
  Key pass = {{0}};
  for ( int i = {0}; i < C; ++i)
    {
      string asdf = BitString.substr(i*5, 5);
      bitset<5> temp (asdf);

      pass.digit[ i ] = temp.to_ulong();
    }
  cout << pass << endl;
}

/* Generates the next mask*/
int next(int mask[], int n) {
    int i;
    for (i = 0; (i < n) && mask[i]; ++i)
        mask[i] = 0;
 
    if (i < n) {
        mask[i] = 1;
        return 1;
    }
    return 0;
}



unordered_map < Key, vector< vector< int > >, key_hash > getMap(Key T[], int range, int indexToAdd) {

  int mask[range];
  for (int i = 0; i < range; ++i)
    mask[i] = 0;
  
  vector< vector <int> > permutations;

  while (next(mask, range))
  {
    vector<int> v;
    for (int i = 0; i < range; ++i)
      if (mask[i])
      {
	v.push_back(i + indexToAdd);
      }
    permutations.push_back(v);
  }

 
  unordered_map < Key, vector< vector< int > >, key_hash > temp;

  //Populate one half of the hash table
  for( int i = {0}; i < permutations.size(); ++i)
    {
      Key subSet{{0}};
      for( int j = {0}; j < permutations[i].size(); ++j)
	{
	  subSet = subSet + T[ permutations[i][j] ];
	 
	}
      unordered_map < Key, vector< vector< int > >, key_hash >::iterator it = temp.find(subSet);
      if( it != temp.end())
	{
	  temp[subSet].push_back( permutations[i] );
	}
      else {
	vector < vector < int > > temp_vec = { permutations[i] };
	temp.insert(make_pair(subSet, temp_vec));
      }     
    }

  return temp;

}
 
int
main(int argc, char* argv[])
{
  unsigned char buffer[C+1];     // temporary string buffer
  Key candidate = {{0}};         // a password candidate
  Key encrypted;                 // the encrypted password
  Key candenc;                   // the encrypted password candidate
  Key zero = {{0}};              // the all zero key
  Key T[N];                      // the table T

  if (argc != 2)
    {
      cout << "Usage:" << endl << argv[0] << " password < rand8.txt" << endl;

      return 1;
    }

  encrypted = KEYinit((unsigned char *) argv[1]);

  // read in table T
  for (int i{0}; i < N; ++i)
    {
      if( scanf("%s", buffer) != 1 )
      {
      	  cerr << stderr << "Error reading in table T." << endl;
      	}
      //scanf("%s", buffer);   
      T[i] = KEYinit(buffer);
     }

   auto begin = chrono::high_resolution_clock::now();

   unordered_map < Key, vector< vector< int > >, key_hash > first_half;
   unordered_map < Key, vector< vector< int > >, key_hash > second_half;



   int n = 0;
   int m = 0;

   if (N%2 != 0)
     {
       n = N/2;
       m = N/2+1;
     }
   else
     {
       n = N/2;
       m = N/2;
     }

   //cout << "We are here 0" << endl;
   first_half = getMap(T, n, 0);
   //cout << "We are here 1" << endl;   
   second_half = getMap(T, m, m - 1);
   //cout << "We are here 2" << endl;

   // Check if we have any passwords candidates in the first_half only
   //for( auto ff = first_half.begin(); ff != first_half.end(); ++ff )
   //  {

   //  }
   if( first_half.count(encrypted) == 1 )
     {
       cout << "We have a cand in first_half" << endl;
     }

   if( second_half.count(encrypted) == 1 )
     {
       cout << "We have a cand in second_half" << endl;
     }

   // Check if we have any pwd candidates in first and second combined
   for ( auto ff = first_half.begin(); ff != first_half.end(); ++ff )
    {

      Key temp = encrypted - ff->first;
      if ( second_half.count(temp) == 1 )
	{
	  bitset<N> b;
	  //cout << "We are here 3" << endl;
	  for(int fi = 0; fi < ff->second.size(); fi++)
	    {
	      //bitset<N> b;
	      
	      for(int fj = 0; fj < ff->second[fi].size(); fj++)
		{
		  //cout << ff->second[fi][fj] << ": ff->second" << endl;
		  b.set(ff->second[fi][fj]);
		}

	      for( int si = {0}; si < second_half[temp].size(); ++si)
		{
		  bitset<N> first_part = b;
		  for(int sj = {0}; sj < second_half[temp][si].size(); ++sj)
		    {
		      //cout << second_half[ temp ][si][sj] << ": second_half" << endl;
		      first_part.set(second_half[ temp ][si][sj] );
		    }
		  BitToString(first_part);
		}

	    }
	}

    }

  auto end = chrono::high_resolution_clock::now();
  cout << "Decryption took "
       << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
       << " seconds." << endl;
  
  return 0;
}



