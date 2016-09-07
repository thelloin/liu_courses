#include <iostream>
#include <string>

struct Person
{
  std::string name;
  unsigned age;
  float length;
};

void print_person(const Person& p);

void fun1(Person p)
{
  print_person(p);
}

Person fun2()
{
  return { "Halle", 30, 1.57 };
}

struct S
{
  Person p1{ "Salle", 45, 1.90 };

  S() : p2{ "Xalle", 222, 0.99 } {}
  S(const Person& p) : p3(p) {}
  Person p2, p3;
};

void print_person(const Person& p)
{
  std::cout << p.name << ", " << p.age << ", " << p.length << std::endl;
}

int main()
{
  std::cout << "b) struct aggregates.\n";

  std::cout << "\n1) initializer in a struct definition:\n";
  Person p{ "Kalle", 20, 1.80 };
  print_person(p);

  std::cout << "\n2) struct initializer in a new expression:\n";
  Person* p2 = new Person{ "Palle", 56, 1.89};
  print_person(*p2);

  std::cout << "\n3) as function argument, parameter is a struct:\n";
  fun1( { "Nalle", 3, 0.43 } );

  std::cout << "\n4) in a return statement, destination is a struct:\n";
  Person p3 = fun2();
  print_person(p3);

  std::cout << "\n5 initializer for non-static struct data member:\n";
  S s1;
  print_person(s1.p1);

  std::cout << "\n6) in a struct member initializer:\n";
  print_person(s1.p2);

  std::cout << "\n7) right-hand side of an assignment to struct:\n";
  p = { "Bjarne Stroustrup", 62, 1.79 };
  print_person(p);

  std::cout << "\n8) argument to a constructor invocation (struct parameter):\n";
  S s2({ "Galle", 10, 10 });
  print_person(s2.p3);
  std::cout << '\n';

  return 0;
}
