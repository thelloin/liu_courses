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

    Container() noexcept = default;                 // 1
    explicit Container(const size_type n);          // 1
    Container(const Container&);                    // 2
    Container(Container&&) noexcept;                // 2

    ~Container();                                   // 1

    Container& operator=(const Container&) &;       // 2
    Container& operator=(Container&&) & noexcept;   // 2

    size_type size() const noexcept;                // 1
    size_type max_size() const noexcept;            // 1
    size_type capacity() const noexcept;            // 1
    bool empty() const noexcept;                    // 1
    void clear() noexcept;                          // 3
    void swap(Container&) noexcept;                 // 3

private:
    T* start_{ nullptr };
    T* finish_{ nullptr };
    T* end_of_storage_{ nullptr };

    T* allocate_(size_type);                        // 1
    void deallocate_(T*);                           // 1
    T* allocate_and_copy_(const Container&);        // 2
};

template <typename T>
void swap(Container<T>&, Container<T>&) noexcept;   // 3

#include "Container.tcc"

#endif /* CONTAINER_H */
