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


  // Rewritten as a statement using range based for statement
  space_count = 0;
  for( auto p : line)
    {
      if (p == ' ')
	++space_count;
    }  

  std::cout << "Number of spaces using range based for statement: " << space_count << std::endl;

  return 0;
}
