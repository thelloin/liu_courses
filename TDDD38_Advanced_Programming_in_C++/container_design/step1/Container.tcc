/*
 * Container.tcc   Step 1. Initializing and destroying container objects.
 */
#ifndef CONTAINER_TCC
#define CONTAINER_TCC

#include "Container.h"
#include <cassert>
#include <stdexcept>

using namespace std;

/*
 * allocate_(n) [Step 1]
 * Allocates memory for n objects of type T using array new. All elements
 * will be value-initialized (default initialized if T is a class type).
 */
template <typename T>
T*
Container<T>::allocate_(size_type n)
{
   if (n > max_size())
      throw std::bad_alloc();

   if (n > 0)
      return new T[n];
   else
      return nullptr;
}

/*
 * deallocate_(T*) [Step 1]
 * Deallocates memory using array delete. All elements will be destroyed.
 */
template <typename T>
void
Container<T>::deallocate_(T* start)
{
   delete[] start;
}

/*
 * Constructor, initializes to size n [Step 1]
 * If n < 1 the container is initialized to empty (n cannot be negative), else
 * storage is allocated for n elements, all objects will be value-initialized.
 */
template <typename T>
Container<T>::Container(const size_type n)
{
   if (n > 0)
   {
      start_ = allocate_(n);
      finish_ = start_ + n;
      end_of_storage_ = finish_;
   }
}

/*
 * Destructor [Step 1]
 * Deallocates storage, all elements are destroyed before that.
 */
template <typename T>
Container<T>::~Container()
{
   deallocate_(start_);
}

/*
 * size() [Step 1]
 */
template <typename T>
typename Container<T>::size_type
Container<T>::size() const noexcept
{
   return size_type(finish_ - start_);
}

/*
 * max_size() [Step 1]
 * Largest chunk of memory, in bytes, is equal to the largest value for size_type.
 * Note: size_type(-1) is the same value as std::numeric_limits<size_type>::max().
 */
template <typename T>
typename Container<T>::size_type
Container<T>::max_size() const noexcept
{
   return size_type(-1) / sizeof(T);
}

/*
 * capacity() [Step 1]
 */
template <typename T>
typename Container<T>::size_type
Container<T>::capacity() const noexcept
{
   return size_type(end_of_storage_ - start_);
}

/*
 * empty() [Step 1]
 */
template <typename T>
bool
Container<T>::empty() const noexcept
{
   return start_ == finish_;
}

#endif /* CONTAINER_TCC */
