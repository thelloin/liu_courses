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
    Container(const Container&);                    // n
    Container(Container&&) noexcept;                // n

    ~Container();

    Container& operator=(const Container&) &;       // n
    Container& operator=(Container&&) & noexcept;   // n

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
    T* allocate_and_copy_(const Container&);        // n
};

#include "Container.tcc"

#endif /* CONTAINER_H */
