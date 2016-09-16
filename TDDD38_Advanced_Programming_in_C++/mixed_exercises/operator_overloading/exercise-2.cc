#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdexcept>
using namespace std;

class ifcharstream
{
public:
  ifcharstream(const string& filename) noexcept(false);
  ~ifcharstream() { file_.close(); }

  char operator[](streampos pos) const;

  void close();

private:
  ifcharstream(const ifcharstream&) = delete;
  ifcharstream& operator=(const ifcharstream&) = delete;
  // ifcharstream() is not generated
  // ifcharstream(ifcharstream&&) is not generated
  // ifcharstream(operator=(ifcharstream&&) is not generated

  mutable ifstream file_;
  bool open_{ false };
};

ifcharstream::ifcharstream(const string& filename)
{
  file_.open(filename.c_str(), ios::in | ios::binary);

  if (!file_)
    {
      throw invalid_argument("Kunde inte öppna filen " + filename);
    }
  open_ = true;
}

void ifcharstream::close()
{
  file_.close();
  open_ = false;
}

char ifcharstream::operator[](streampos pos) const
{
  if (!open_) return '\0';
  char c;
  file_.seekg(pos);
  file_.read(&c, sizeof(char));
  return c;
}

int main()
{
  // Create a temporary file in the working directory
  ofstream output{ "TMP.TXT", ios::binary };

  char data[]{ "0123456789ABCDEF" };
  constexpr unsigned n_char{ sizeof(data) - 1 };

  for (auto it = begin(data); it != end(data); ++it)
    output.write(it, sizeof(char));
  output.close();

  ifcharstream input{ "TMP.TXT" };
  unsigned pos;

  do
    {
      cout << "Give a position between 0 and " << n_char - 1 << " (else exit): ";
      cin >> pos;
      if (pos < n_char)
	{
	  cout << "At position " << pos << " the character '" << input[pos] << "' is found\n";
	}
      else
	{
	  cout << pos << " is not a valid position, exit!\n";
	}
    }
  while (pos < n_char);

  input .close();
  remove("TMP.TXT");

  return 0;
}
