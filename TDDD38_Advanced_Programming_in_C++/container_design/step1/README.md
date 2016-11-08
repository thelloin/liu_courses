README Container Design, Step 1

The answer to the question "What might throw?" is "Any function!".
So, which functions will actually be called, including normal functions, constructors, destructors, operators and others member functions?

#### allocate_(size_type n)
If n is greater than size(), std::bad::alloc is thrown, The expression 'new T[n]' may fail for several reasons. The memory allocation may fail, and then std::bad_alloc is thrown. If memory allocation succeedes, T::T() is called for each of the n elements and might fail, throwing anything. In such case all objects that have been constructed will be destroyed and the memory allocated is guaranteed to be deallocated.

Nothing is caught, so if someone throws an exception it is propogated to the caller. It's exception-neutral.

No memory is leaked. If operator new[]() throws bad_alloc, no memory was ever allocated. If one of the T constructor calls throws, then all T object that was constructed will be destroyed and operator delete[]() will be automatically called to deallocate the memory. No objects will be in an inconsistent state, no memory leaked and no other resources are lost - strongly exception safe.

#### deallocate_(T* start)
Cannot fail

#### Container()
Pointer data members are initialized to nullptr, nothing can go bad here.

#### Container(const size_type n)
The data members will all be initialized to nullptr, which cannot cause any problems. If n is greater than 0, allocate(n) is called.
allocate(n) is exception-safe and exception-neutral, and so is then also this constructor.

#### ~Container()
Destroying the array pointed to by start_ will invoke T::~T() for each element in the array, and then memory is deallocated. None should throw here.

The other member functions cannot throw.