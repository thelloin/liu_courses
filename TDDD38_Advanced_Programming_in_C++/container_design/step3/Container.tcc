/*
 * Container.tcc   Step 3. Clearing and swapping
 */
#ifndef CONTAINER_TCC
#define CONTAINER_TCC

#include "Container.h"
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <utility>

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
 * allocate_and_copy_(const Container&) [Step 2]
 * Copies the content of a constructor to new storage. If a failure is encountered
 * during copying elements from the current to the new storage, the new storage is
 * deallocated and all einitialized elements destroyed when doing that.
 */
template <typename T>
T*
Container<T>::allocate_and_copy_(const Container& c)
{
    if (c.size() == 0)
	return nullptr;

    auto new_start = allocate_(c.size());

    try
    {
	std::copy(c.start_, c.finish_, new_start);
    }
    catch (...)
    {
	deallocate_(new_start);
	throw;
    }

    return new_start;
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
 * Copy constructor [Step 2]
 */
template <typename T>
Container<T>::Container(const Container& other)
{
    if (other.size() > 0)
    {
	start_ = allocate_and_copy_(other);
	finish_ = start_ + other.size();
	end_of_storage_ = finish_;
    }
}

/*
 * Move constructor [Step 2, modified Step 3]
 * Destination container is initialized to empty, content is swapped with other,
 * other becomes empty.
 */
template <typename T>
Container<T>::Container(Container&& other) noexcept
{
    swap(other);
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
 * Copy assignment operator [Step 2, modified Step 3]
 * Makes a deep copy of other container.
 */
template <typename T>
Container<T>&
Container<T>::operator=(const Container& other) &
{
    if (this != &other)
    {
	// The idea is to create a temporary deep copy of other(Container{ other },
	// and then swap the copy with *this, resulting in deallocatin the copy
	// when it goes out of scope.
	// ???? Is there any moves involved????
	Container{ other }.swap(*this);
    }
    return *this; // safe, no copy involved
}

/*
 * Move assignment operator [Step 2]
 * Clears *this and swaps content with other
 */
template <typename T>
Container<T>&
Container<T>::operator=(Container&& other) & noexcept
{
    if (this != &other)
    {
        clear();
	swap(other);
    }
    return *this;
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

/*
 * clear() [Step 3]
 * Destroys all elements, empty() shall return true.
 */
template <typename T>
void
Container<T>::clear() noexcept
{
    deallocate_(start_);
    start_ = nullptr;
    finish_ = nullptr;
    end_of_storage_ = nullptr;
}

/*
 * swap(Container&) [Step 3]
 * Swapping pointers can't fail.
 */
template <typename T>
void
Container<T>::swap(Container& other) noexcept
{
    std::swap(start_, other.start_);
    std::swap(finish_, other.finish_);
    std::swap(end_of_storage_, other.end_of_storage_);
}

/*
 *swap(Container&, Container&) [Step 3]
 */
template <typename T>
void swap(Container<T>& a, Container<T>& b) noexcept
{
    a.swap(b);
}

#endif /* CONTAINER_TCC */
