/*
 * Container.tcc   Step 7. Storage management redesigned.
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
 * compute_capacity_() [STEP 4]
 * Computes the next capacity according to allocation sceme.
 * Note: size_type(-1) is instead for std::numeric_limits<size_type>::max().
 */
template <typename T>
typename Container<T>::size_type
Container<T>::
compute_capacity_() const
{
   if (capacity() == size_type(-1))
      throw std::length_error{ "Container capacity is exhausted" };
   else if (capacity() >= size_type(-1) / 2)
      return size_type(-1);
   return capacity() == 0 ? 1 : 2 * capacity();
}

/*
 * allocate_(size_type) [STEP 1, modified STEP 7]
 * Allocates memory for n objects of type T using the global memory allocation 
 * function ::operator new() with the required size for n objects of type T.
 * Alignment will be fine for any T. No initialization will take place.
 */
template <typename T>
typename Container<T>::pointer 
Container<T>::
allocate_(size_type n)
{
   if (n > max_size())
      throw std::bad_alloc();

   if (n > 0)
      return static_cast<pointer>(::operator new(n * sizeof(T)));
   else
      return nullptr;
}

/*
 * deallocate_(pointer) [STEP 1, modified STEP 7]
 * Deallocates memory using the global memory deallocation function ::operator 
 * delete(). No destruction will take place.
 */
template <typename T>
void
Container<T>::
deallocate_(pointer p)
{
   ::operator delete(p);
}

/*
 * construct_(pointer, const_reference) [STEP 7]
 * Creates a T object at a given location p, using placement new and the copy 
 * constructor for T.
 */
template <typename T>
void
Container<T>::
construct_(pointer p, const_reference x)
{
   new(p) T(x);
}

/*
 * destroy_(pointer) [STEP 7]
 * Destroys a T object at a given location p, by explicitly calling the T
 * destructor.
 */
template <typename T>
void
Container<T>::
destroy_(pointer p)
{
   p->~T();
}

/*
 * destroy_(pointer, pointer) [STEP 7]
 * Destroys a range of T object, by explicitly calling the destructor for T on
 * each object in the range.
 */
template <typename T>
void
Container<T>::
destroy_(pointer start, pointer finish)
{
   for (pointer p = start; p != finish; ++p)
      p->~T();
}

/*
 * allocate_and_copy_(const Container&) [STEP 2, modified STEP 7]
 * Copies the content of a container to new storage. If a failure is encountered
 * during copying elements from current to the new storage, the then allready 
 * copied objects must be destroyed before the new storage is deallocated.
 */
template <typename T>
typename Container<T>::pointer
Container<T>::
allocate_and_copy_(const Container& c)
{
   if (c.size() == 0)
      return nullptr;

   pointer new_start = allocate_(c.size());
   pointer finish = new_start;

   try
   {
      // finish keeps track of the last successfully copied element, in case of
      // failure.
      for (auto p = c.begin(); p != c.end(); ++p, ++finish)
         construct_(finish, *p);
   }
   catch (...)
   {
      // destroy the elements which have been copied to new storage and deallocate
      // new storage.
      destroy_(new_start, finish);  // can't fail
      deallocate_(new_start);       // can't fail
      throw;
   }

   return new_start;
}

/*
 * resize_(const_reference) [STEP 4, modified STEP 7]
 * Resizes storage according to capacity scheme, insert x, and copy excisting 
 * elements to the new storage.
 */
template <typename T>
void
Container<T>::
resize_(const_reference x)
{
   const size_type old_size = size();
   const size_type new_capacity = compute_capacity_();

   pointer new_start = allocate_(new_capacity);
   pointer finish = new_start;

   try
   {
      construct_(new_start + old_size, x);
      // copy elements from current storage to new storage, finish keeps track
      // of last successfully copied element.
      for (auto p = begin(); p != end(); ++p, ++finish)
         construct_(finish, *p);
   }
   catch (...)
   {
      // destroy any copied elements and deallocate new storage
      destroy_(new_start, finish);  // can't fail
      deallocate_(new_start);       // can't fail
      throw;
   }
   // destroy elements in old storage and replace old storage with new
   destroy_(begin(), end());   // can't fail
   delete[] start_;            // can't fail
   start_ = new_start;
   finish_ = finish;
   end_of_storage_ = start_ + new_capacity;
}

/*
 * Constructor initializing to size n [STEP 1, modified STEP 7]
 * Allocates storage for n elements of type T and initializes all elements.
 */
template <typename T>
Container<T>::
Container(const size_type n)
{
   if (n > 0)
   {
      start_ = allocate_(n);
      finish_ = start_;
      end_of_storage_ = start_ + n;

      try
      {
	 const T x;
	 for (; finish_ != end_of_storage_; ++finish_)
	    construct_(finish_, x);
      }
      catch (...)
      {
	 // finish_ points past last successfully initialized element
	 destroy_(start_, end());
	 deallocate(start_);
	 throw;
      }
   }
}

/*
 * Copy constructor [STEP 2, modified STEP 7]
 * Allocates storage (shrink-to-fit).
 */
template <typename T>
Container<T>::
Container(const Container& other)
{
   if (other.size() > 0)
   {
      start_ = allocate_and_copy_(other);
      finish_ = start_ + other.size();
      end_of_storage_ = finish_;
   }
}

/*
 * Move constructor [STEP 2]
 * Destination container is initialized to empty, then content is swapped,
 * source container becomes empty.
 */
template <typename T>
Container<T>::
Container(Container&& other) noexcept
{
   swap(other);
}

/*
 * Destructor [STEP 1, modified STEP 7]
 * Destroyes stored objects and then deallocates storage.
 */
template <typename T>
Container<T>::
~Container()
{
   destroy_(begin(), end());
   deallocate_(start_);
}

/*
 * Copy assignment operator [STEP 2, modified STEP 3, modified STEP 7]
 * Makes a copy of other (shrink-to-fit), destroys current elements and
 * deallocates current storage, and then takes control over new storage.
 */
template <typename T>
Container<T>&
Container<T>::
operator=(const Container& other) &
{
   if (this != &other)
   {
      pointer new_start = allocate_and_copy_(other);
      destroy_(begin(), end());
      deallocate_(start_);
      start_ = new_start;
      finish_ = start_ + other.size();
      end_of_storage_ = finish_;
   }
   return *this;  // safe, no copy involved
}

/*
 * Move assignment operator [STEP 2, modified STEP 7]
 * Source container becomes empty.
 */
template <typename T>
Container<T>&
Container<T>::
operator=(Container&& other) & noexcept
{
   if (this != &other)
   {
      clear();
      swap(other);  // can't fail
   }
   return *this;   // safe, no copy involved
}

/*
 * size() [STEP 1, modified STEP 6]
 */
template <typename T>
typename Container<T>::size_type
Container<T>::
size() const noexcept
{
   return size_type(end() - begin());
}

/*
 * max_size() [STEP 1]
 * Largest chunk of memory, in bytes, is equal to the largest value for size_type.
 * Note: size_type(-1) is used instead of std::numeric_limits<size_type>::max().
 */
template <typename T>
typename Container<T>::size_type
Container<T>::
max_size() const noexcept
{
   return size_type(-1) / sizeof(T);
}

/*
 * capacity() [STEP 1]
 */
template <typename T>
typename Container<T>::size_type
Container<T>::
capacity() const noexcept
{
   return size_type(end_of_storage_ - start_);
}

/*
 * empty() [STEP 1, modified STEP 6]
 */
template <typename T>
bool 
Container<T>::
empty() const noexcept
{
   return begin() == end();
}

/*
 * clear() [STEP 3, modified STEP 7]
 */
template <typename T>
void 
Container<T>::
clear()
{
   destroy_(begin(), end());  // can't fail
   deallocate_(start_);
   start_ = nullptr;
   finish_ = nullptr;
   end_of_storage_ = nullptr;
}

/*
 * swap(Container&) [STEP 3]
 * Swaps the content of two Containers, swapping pointers can't fail.
 */
template <typename T>
void 
Container<T>::
swap(Container& other) noexcept
{
   std::swap(start_, other.start_);
   std::swap(finish_, other.finish_);
   std::swap(end_of_storage_, other.end_of_storage_);
}

/*
 * swap(Container&, Container&) [STEP 3]
 */
template <typename T>
void swap(Container<T>& a, Container<T>& b) noexcept
{
   a.swap(b);  // can't fail
}

/*
 * push_back(const_reference) [STEP 4]
 */
template <typename T>
void 
Container<T>::
push_back(const_reference x)
{
   if (size() == capacity())
   {
      resize_(x);
   }
   else
      construct_(finish_, x);
   ++finish_;
}

/*
 * back(), for non-const Container, should not throw according to standard. [STEP 4]
 */
template <typename T>
T& 
Container<T>::
back()
{
   return *(finish_ - size_type(1));
}

/*
 * back(), for const Container, should not throw according to standard [STEP 4]
 */
template <typename T>
typename Container<T>::const_reference
Container<T>::
back() const
{
   return *(finish_ - size_type(1));
}

/*
 * pop() [STEP 4]
 * Decrements finish_ (past last position) and destroys the last element.
 */
template <typename T>
void
Container<T>::
pop_back()
{
   if (! empty())
      destroy_(--finish_);  // can't fail
}

/*
 * Iterator functions [Step 6]
 */

template <typename T>
typename Container<T>::iterator
Container<T>::
begin() noexcept
{
   return iterator(start_);
}

template <typename T>
typename Container<T>::const_iterator
Container<T>::
begin() const noexcept
{
   return const_iterator(start_);
}

template <typename T>
typename Container<T>::iterator
Container<T>::
end() noexcept
{
   return iterator(finish_);
}

template <typename T>
typename Container<T>::const_iterator
Container<T>::
end() const noexcept
{
   return const_iterator(finish_);
}

template <typename T>
typename Container<T>::reverse_iterator
Container<T>::
rbegin() noexcept
{
   return reverse_iterator(end());
}

template <typename T>
typename Container<T>::const_reverse_iterator
Container<T>::
rbegin() const noexcept
{
   return const_reverse_iterator(end());
}

template <typename T>
typename Container<T>::reverse_iterator
Container<T>::
rend() noexcept
{
   return reverse_iterator(begin());
}

template <typename T>
typename Container<T>::const_reverse_iterator
Container<T>::
rend() const noexcept
{
   return const_reverse_iterator(begin());
}

template <typename T>
typename Container<T>::const_iterator
Container<T>::
cbegin() const noexcept
{
   return const_iterator(start_);
}

template <typename T>
typename Container<T>::const_iterator
Container<T>::
cend() const noexcept
{
   return const_iterator(finish_);
}

template <typename T>
typename Container<T>::const_reverse_iterator
Container<T>::
crbegin() const noexcept
{
   return const_reverse_iterator(end());
}

template <typename T>
typename Container<T>::const_reverse_iterator
Container<T>::
crend() const noexcept
{
   return const_reverse_iterator(begin());
}

#endif /* CONTAINER_TCC */
