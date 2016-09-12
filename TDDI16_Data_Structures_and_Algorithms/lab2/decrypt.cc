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

class key_hash
{
  public:
    long operator()(const Key& x) const
    {
      long hash = 0;

      for (int i{N - 1}; i >= 0; i--)
	{
	  hash = hash | KEYbit(x, i) << i;
	  //hash +=  KEYbit(x, i) * pow(2.0, i);
	}
      return hash;
    }
};


 
int
main(int argc, char* argv[])
{
  unsigned char buffer[C+1];     // temporary string buffer
  Key encrypted;                 // the encrypted password
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
      if ( scanf("%s", buffer) != 1  )
	{
	  cerr << "Error reading file." << endl;
	}
      T[i] = KEYinit(buffer);
     }

   auto begin = chrono::high_resolution_clock::now();


  // New code here **************************
  // ****************************************
  unordered_map < Key, vector< Key >, key_hash > first_h_keys;
  vector< Key > temp_keys;
  Key counter = {{0}};

  // Fill the first half of the hash
  while( counter.digit[C/2 - 1] == 0 ) {
    //temp_keys.push_back(counter);
    Key subset = KEYsubsetsum(counter, T);

    //Check if that subset already exists in the hash
    if (first_h_keys.count(subset) == 1) {
      first_h_keys[subset].push_back( counter );
    } else {
      vector< Key > temp = { counter };
      first_h_keys.insert( make_pair(subset, temp) );
    }
    counter++;
  }




  Key max_first_half = counter;


  // Check cands in first_half
  if( first_h_keys.count(encrypted) == 1 ) {
    //cout << "We have a cand in first_half" << endl;
    for( unsigned int i = 0; i < first_h_keys[encrypted].size(); ++i )
      {
	cout << first_h_keys[encrypted][i] << endl;
      }
  }



  Key zero = {{0}};
  do {
    Key temp = encrypted - KEYsubsetsum(counter, T);

    if ( first_h_keys.count(temp) == 1) {

      for ( unsigned int i = 0; i < first_h_keys[temp].size(); ++i ) {
	cout << counter + first_h_keys[temp][i] << endl;
      }
    }
    counter = counter + max_first_half;
  } while (counter != zero);





  auto end = chrono::high_resolution_clock::now();
  cout << "Decryption took "
       << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
       << " seconds." << endl;
  
  return 0;
}



