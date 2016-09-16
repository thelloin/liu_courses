#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Person
{
public:
  Person() {}
  Person(const string& first_name,
	 const string& last_name,
	 const string& street,
	 const string& post_code,
	 const string& city);

  void set_first_name(const string& first_name);
  void set_last_name(const string& last_name);
  void set_street(const string& street);
  void set_post_code(const string& post_code);
  void set_city(const string& vity);

  string get_first_name() const;
  string get_last_name() const;
  string get_street() const;
  string get_post_code() const;
  string get_city() const;

  friend istream& operator>>(istream&, Person&);
  friend ostream& operator<<(ostream&, const Person&);

private:
  string first_name_;
  string last_name_;
  string street_;
  string post_code_;
  string city_;
};

Person::Person(const string& first_name,
	       const string& last_name,
	       const string& street,
	       const string& post_code,
	       const string& city) :
  first_name_(first_name),
  last_name_(last_name),
  street_(street),
  post_code_(post_code),
  city_(city)
{ }

void Person::set_first_name(const string& first_name)
{
  first_name_ = first_name;
}

void Person::set_last_name(const string& last_name)
{
  last_name_ = last_name;
}

void Person::set_street(const string& street)
{
  street_ = street;
}

void Person::set_post_code(const string& post_code)
{
  post_code_ = post_code;
}

void Person::set_city(const string& city)
{
  city_ = city;
}

istream& operator>>(istream& is, Person& p)
{
  is >> p.first_name_ >> p.last_name_ >> ws;
  getline(is, p.street_);
  getline(is, p.post_code_);
  getline(is, p.city_);
  return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
   os << p.first_name_ << ' ' << p.last_name_ << '\n';
   os << p.street_ << '\n';
   os << p.post_code_ << '\n';
   os << p.city_ << '\n';
   return os;
}

int main(int argc __attribute__((unused)), char* argv[])
{
  Person p;

  fstream ifs (argv[1]);
  ifs >> p;

  cout << p;
  return 0;
}
