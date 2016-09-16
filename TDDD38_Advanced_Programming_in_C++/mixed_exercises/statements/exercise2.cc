#include <iostream>

int main()
{
  char line[]{ "Hello, World!" };
  int length { sizeof line };
  

  int space_count {0};
  for (int i{0}; i < length; ++i)
    {
      if (line[i] == ' ')
	++space_count;
    }
  std::cout << "Number of space using for-loop: " << space_count << std::endl;


  // Rewritten as a statement using pointer instead of indexing
  space_count = 0;
  for( char* p = line; p != line + length; ++p)
    {
      if (*p == ' ')
	++space_count;
    }  

  std::cout << "Number of space using for-loop with pointer: " << space_count << std::endl;

  return 0;
}
