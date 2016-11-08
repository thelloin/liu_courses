/*
 * Container.h
 */
#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstdlib>

template <typename T>
class Container
{
public:
   using size_type = std::size_t;

   Container() noexcept = default;
   explicit Container(const size_type n);

   ~Container();

   size_type size() const noexcept;
   size_type max_size() const noexcept;
   size_type capacity() const noexcept;
   bool empty() const noexcept;

private:
   T* start_{ nullptr };
   T* finish_{ nullptr };
   T* end_of_storage_{ nullptr };

   T* allocate_(size_type);
   void deallocate_(T*);
};

#include "Container.tcc"

#endif /* CONTAINER_H */
