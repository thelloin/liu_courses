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
    using value_type        = T;                    // 5
    using pointer           = value_type*;          // 5
    using const_pointer     = const value_type*;    // 5
    using reference         = value_type&;          // 5
    using const_reference   = const value_type&;    // 5
    using size_type         = std::size_t;

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

    void push_back(const_reference);                // 4, mod 5
    reference back();                               // 4, mod 5
    const_reference back() const;                   // 4, mod 5
    void pop_back() noexcept;                       // 4

    void swap(Container&) noexcept;                 // 3

private:
    pointer start_{ nullptr };                      // mod 5
    pointer finish_{ nullptr };                     // mod 5
    pointer end_of_storage_{ nullptr };             // mod 5

    size_type compute_capacity_() const;            // 4

    pointer allocate_(size_type);                   // 1, mod 5
    void deallocate_(pointer);                      // 1, mod 5
    pointer allocate_and_copy_(const Container&);   // 2, mod 5

    void resize_(const_reference);                  // 4, mod 5
};

template <typename T>
void swap(Container<T>&, Container<T>&) noexcept;   // 3

#include "Container.tcc"

#endif /* CONTAINER_H */
