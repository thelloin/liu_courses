#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class up : public std::logic_error
{
public:
  explicit up(const string& what_arg) : std::logic_error{ what_arg } {}
  explicit up(const char* what_arg) : std::logic_error{ what_arg } {}
};

void fun(unsigned depth)
{
  static unsigned current_depth{ 0 };

  try
    {
      if (++current_depth == depth)
	{
	  cout << "Oops! ";
	  throw up("exception thrown at call depth " + std::to_string(depth));
	}
      fun(depth);
    }
  catch (...)
    {
      cout << current_depth << '-';
      current_depth--;
      throw;
    }
}

int main(int argc, char* argv[])
{
  if (argc != 2)
    {
      cout << "Usage: " << argv[0] << " <depth>" << endl;
      return 1;
    }

  unsigned depth = std::stoi(argv[1]);

  try
    {
      fun(depth);
    }
  catch (const exception& e)
    {
      cout << e.what() << endl;
    }

  return 0;
}
