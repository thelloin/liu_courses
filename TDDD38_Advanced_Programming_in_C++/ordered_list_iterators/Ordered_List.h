/*
 * Ordered_List.h    TDDD38, Exercise on list iterators.
 */
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <initializer_list>
#include <iterator>
// TO BE REMOVED WHEN ITERATORS ADDED:
#include <iostream>

/*
 * List_Node
 */
template<typename T>
struct List_Node
{
   explicit List_Node(const T& value, List_Node* next = nullptr)
      : data_{ value }, next_{ next } 
   {}
	 
   ~List_Node() { delete next_; }

   List_Node(const List_Node&) = delete;
   List_Node& operator=(const List_Node&) = delete;
	 
   T          data_;
   List_Node* next_;
};

/*
 * List iterators
 */
template <typename T>
struct Ordered_List_iterator
{
    using value_type              = T;
    using reference               = T&;
    using pointer                 = T*;
    using difference_type         = std::ptrdiff_t;
    using iterator_category       = std::forward_iterator_tag;

    using Self_ = Ordered_List_iterator<T>;

    Ordered_List_iterator() = default;
    explicit Ordered_List_iterator(List_Node<T>* node) : current_{node} {}

    // Copy constructor - could use default??
    Ordered_List_iterator(const Ordered_List_iterator& other)
	{
	    current_ = other.current_;
	}

    // Move constructor - could use default??
    Ordered_List_iterator(Ordered_List_iterator&& other) noexcept
	{
	    if (*this != other)
	    {
		current_ = other.current_;
		other.current_ = nullptr;
	    }
	}

    ~Ordered_List_iterator() = default;

    Ordered_List_iterator& operator=(const Ordered_List_iterator&) & = default;
    Ordered_List_iterator& operator=(Ordered_List_iterator&&) & noexcept = default;

    reference operator*() const { return current_->data_; }

    pointer operator->() const { return &(current_->data_); }

    Self_& operator++()
	{
	    current_ = current_->next_;
	    return *this;
	}

    Self_ operator++(int)
	{
	    Self_ tmp{ *this };
	    current_ = current_->next_;
	    return tmp;
	}

    bool operator==(const Self_& other) const
	{
	    return current_ == other.current_;
	}

    bool operator!=(const Self_& other) const
	{
	    return current_ != other.current_;
	}


    List_Node<T>* current_{ nullptr };
};

template <typename T>
struct Ordered_List_const_iterator
{
    using value_type           = T;
    using reference            = const T&;
    using pointer              = const T*;
    using difference_type      = std::ptrdiff_t;
    using iterator_category    = std::forward_iterator_tag;
};

/*
 * Ordered_List
 */

template<typename T, class Compare = std::less<T> >
class Ordered_List
{
public:
   // types
   using value_type      = T;
   using pointer         = T*;
   using const_pointer   = const T*;
   using reference       = T&;
   using const_reference = const T&;
   
   // construct/copy/destroy
   Ordered_List() : head_{ nullptr }, cmp_{ Compare() } {}
   Ordered_List(const Ordered_List& other) : head_{ copy_(other.head_) }, cmp_{ other.cmp_} {}
   Ordered_List(Ordered_List&& other) noexcept { swap(other); }
   Ordered_List(std::initializer_list<T>);

   ~Ordered_List() { delete head_; };

   Ordered_List& operator=(const Ordered_List&) &;
   Ordered_List& operator=(Ordered_List&&) & noexcept;

   // modifiers
   void insert(const T& value);
   void erase(const T& value);
   void swap(Ordered_List&);

   // capacity
   void clear();
   bool empty() const;

   // TO BE REMOVED WHEN ITERATORS ADDED:
   void print() const
   {
      for (auto p = head_; p != nullptr; p = p->next_)
	 std::cout << p->data_ << ' ';
   }

   // iterators
   // TO DO  
	 
private:
   List_Node<T>* head_{ nullptr };
   Compare       cmp_;
	 
   List_Node<T>* copy_(const List_Node<T>*) const;
   void insert_(List_Node<T>*);
};
   
template<typename T, class Compare>
void swap(Ordered_List<T, Compare>& x, Ordered_List<T, Compare>& y)
{
   x.swap(y);
}

#include "Ordered_List.tcc"

#endif
