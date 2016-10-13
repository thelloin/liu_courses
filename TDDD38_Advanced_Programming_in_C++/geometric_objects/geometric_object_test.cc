#include "Geometric_Object.h"
#include <vector>
#include <iostream>
#include <typeinfo>
#include <algorithm>

int main()
{
   std::vector<Geometric_Object*> objects
   {
      new Point{ 1.0, 1.0 },
	 new Line{ -1.0, -1.0, 1.0, 1.0 },
	    new Circle{ 2.0 },
	       new Circular_Cylinder{ 2.0, 10.0 },
		  new Rectangle{ 1.0, 2.0 }
   };

   for (auto obj : objects)
   {
      Cloneable* copy{ obj->clone() };
      if (copy != nullptr)
      {
	 std::cout << std::endl << "Type......: " << typeid(*copy).name() << std::endl;

	 Line* line{ dynamic_cast<Line*>(copy) };
	 if (line)
	 {
	    std::cout << "Length: " << line->get_length() << std::endl;
	 }

	 Plane* plane{ dynamic_cast<Plane*>(copy) };
	 if (plane)
	 {
	    std::cout << "Area: " << plane->get_area() << std::endl;
	    std::cout << "Profile: " << plane->get_profile() << std::endl;
	 }

	 Solid* solid{ dynamic_cast<Solid*>(copy) };
	 if (solid)
	 {
	    std::cout << "Volume: " << solid->get_volume() << std::endl;
	 }

	 Serializeable* serializeable{ dynamic_cast<Serializeable*>(copy) };
	 if (serializeable != nullptr)
	 {
	    std::cout << "Serialized: " << serializeable->str() << std::endl;
	 }

	 // Delete the copy
	 delete copy;
      }
   }
   std::cout << std::endl;

   // Two way of freeing allocated memory
   std::transform(begin(objects), end(objects), begin(objects),
		  [](Geometric_Object* p){ delete p; return nullptr; });

   for_each(begin(objects), end(objects),
	    [](Geometric_Object*& p){ delete p; return nullptr; });
   return 0;
}
