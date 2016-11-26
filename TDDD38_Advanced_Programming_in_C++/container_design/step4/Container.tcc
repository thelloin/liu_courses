/*
 * Container.tcc   Step 4. Inserting and removing elements.
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
 * compute_capacity_() [Step 4]
 * Computes the next capacity according to allocation scheme.
 * Note: size_type(-1) is instead of std::numeric_limit<size_type>::max().
 */
template <typename T>
typename Container<T>::size_type
Container<T>::compute_capacity_() const
{
    if (capacity() == size_type(-1))
	throw std::length_error{ "Container capacity exhausted" };
    else if (capacity() >= size_type(-1) / 2)
	return size_type(-1);
    return capacity() == 0 ? 1 : 2 * capacity();
}

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
 * Copies the content of a constructor to new storage (shrink-to fit). If a failure
 * is encountered during copying elements from the current to the new storage, the
 * new storage is deallocated and all einitialized elements destroyed when doing that.
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
 * resize(const T&) [Step 4]
 * Resizes storage according to capacity scheme, insert X, and copy existing
 * elements to the new storage.
 */
template <typename T>
void
Container<T>::resize_(const T& x)
{
    size_type old_size = size();
    size_type new_capacity = compute_capacity_();
    T* start = allocate_(new_capacity);

    try
    {
	*(start + old_size) = x;
	std::copy(start_, finish_, start);
    }
    catch(...)
    {
	deallocate_(start);
	throw;
    }

    delete[] start_;
    start_ = start;
    finish_ = start_ + old_size;
    end_of_storage_ = start_ + new_capacity;
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

/*
 * push_back(const T&) [Step 4]
 */
template <typename T>
void
Container<T>::push_back(const T& x)
{
    if (size() == capacity())
	resize_(x);
    else
	*finish_ = x;
    ++finish_;
}

/*
 * back() [Step 4]
 * For non-const Container, should not throw according to standard. Imlemented
 * according to operational semantics stated in the reference manual.
 */
template <typename T>
T&
Container<T>::back()
{
    auto tmp = finish_;
    --tmp;
    return *tmp;
}

/*
 * back() [Step 4]
 * For const Container, should not throw according to standard. Implemented
 * according to operational semantics stated in the reference manual.
 */
template <typename T>
const T&
Container<T>::back() const
{
    auto tmp = finish_;
    --tmp;
    return *tmp;
}

/*
 * pop_back() [Step 4]
 * Destroys the last element. Requires empty() shall be false.
 */
template <typename T>
void
Container<T>::pop_back() noexcept
{
    --finish_;
    finish_->~T();
}

#endif /* CONTAINER_TCC */
