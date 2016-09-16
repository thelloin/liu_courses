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


  // Rewritten using while
  space_count = 0;
  int i{ 0 };
  while (i < length)
    {
      if (line[i] == ' ')
	++space_count;
      ++i;
    }
  std::cout << "Number of space using while-loop: " << space_count << std::endl;

  return 0;
}
