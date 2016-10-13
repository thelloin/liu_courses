#include <iostream>
#include <string>
#include <type_traits>

template <typename ...Args>
void print_common(Args...);

void print()
{
   // Empty
}

template <typename ...Args>
void print(char first, Args... tail)
{
   std::cout << "'" << first << "'";
   print_common(tail...);
}

template <typename ...Args>
void print(std::string const & first, Args... tail)
{
   print(first.c_str(), tail...);
}

template <typename ...Args>
void print(char const * first, Args... tail)
{
   std::cout << '"' << first << '"';
   print_common(tail...);
}

template <typename Container, typename ...Args>
auto print(Container const & c, Args... tail)
   -> decltype(begin(c), c.size(), void())
{
   auto is_vector = std::is_same<std::vector<typename Container::value_type,
					     typename Container::allocator_type>,
				 Container>::value;

   if (is_vector)
      std::cout << '[';
   else
      std::cout << '{';
   auto sz = c.size() - 1;
   auto i = decltype(sz){0}; // Does the same: decltype(sz) i{};
   for (auto const & elem : c)
   {
      print(elem);
      if (i++ < sz)
	 std::cout << ", ";
   }
   if (is_vector)
      std::cout << ']';
   else
      std::cout << '}';
   print_common(tail...);
}

template <typename T, typename ...Args>
auto print(T const & first, Args... tail)
   -> decltype(std::cout << first, void())
{
   std::cout << first;
   print_common(tail...);
}


template <typename ...Args>
void print_common(Args... args)
{
   if (sizeof...(args) != 0) std::cout << ", ";
   print(args...);
}
