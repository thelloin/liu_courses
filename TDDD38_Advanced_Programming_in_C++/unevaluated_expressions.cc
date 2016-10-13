#include <iostream>
#include <typeinfo>
#include <typeindex>

int foo(); // no definition to be found

struct widget
{
   virtual ~widget();
   static widget& get_instance(); // no definition to be found
};

int main()
{
   std::type_index ti1 = std::type_index(typeid( foo() ));
   std::cout << ti1.name() << std::endl;

   // does not work, this dynamic type is determined by looking at the VPTR at run-time
   //std::type_index ti2 = std::type_index(typeid( widget::get_instance() ));

   std::cout << "Size of foo(): " << sizeof( foo() ) << std::endl;
   std::cout << "Size of widget::get_instance(): " << sizeof( widget::get_instance() ) << std::endl;

   std::cout << "foo() throws exceptions: " << noexcept(foo()) << std::endl;
   std::cout << "widget::get_instance(): throws exceptions: " << noexcept( widget::get_instance() ) << std::endl;

   std::cout << "decltype(foo()): " << typeid(decltype(foo())).name() << std::endl;
   int x {5};
   std::cout << typeid(decltype(x)).name() << std::endl;

   return 0;
}
