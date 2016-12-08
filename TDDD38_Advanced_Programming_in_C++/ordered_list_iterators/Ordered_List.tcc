/*
 * Ordered_List.tcc    TDDD38, Exercise on list iterators.
 */
#include "Ordered_List.h"
#include <algorithm>
using namespace std;

// constructor taking initializer list.
template<typename T, class Compare>
Ordered_List<T, Compare>::Ordered_List(std::initializer_list<T> il)
{
   try
   {
      for (auto it = il.end(); it != il.begin(); )
	 insert(*--it);
   }
   catch (...)
   {
      delete head_;
      throw;
   }
}

// copy assignment
template<typename T, class Compare>
Ordered_List<T, Compare>& 
Ordered_List<T, Compare>::operator=(const Ordered_List& rhs) &
{
   Ordered_List(rhs).swap(*this);
   return *this;
}

// move assignment
template<typename T, class Compare>
Ordered_List<T, Compare>& 
Ordered_List<T, Compare>::operator=(Ordered_List&& rhs) & noexcept
{
   clear();
   std::swap(head_, rhs.head_);
   return *this;
}

// clear() removes the list content and makes the list empty.
template<typename T, class Compare>
void 
Ordered_List<T, Compare>::clear()
{
   delete head_;
   head_ = nullptr;
}

// insert() inserts x in order in the list. Strongly exception safe.
template<typename T, class Compare>
void 
Ordered_List<T, Compare>::insert(const T& x)
{
   List_Node<T>* new_node = new List_Node<T>(x);

   if (head_ == nullptr || cmp_(new_node->data_, head_->data_))
   {
      new_node->next_ = head_;
      head_ = new_node;
   }
   else
   {
      List_Node<T>* prev = head_;
      List_Node<T>* curr = head_->next_;

      while (curr != nullptr && cmp_(curr->data_, new_node->data_))
      {
	 prev = curr;
	 curr = curr->next_;
      }

      new_node->next_ = curr;
      prev->next_ = new_node;
   }
}

// erase() removes the first occurrence of x from the list, if such.
template<typename T, class Compare>
void 
Ordered_List<T, Compare>::erase(const T& x)
{
   if (head_ == nullptr) 
   {
      return;
   }
   else if (!(cmp_(x, head_->data_) || cmp_(head_->data_, x)))
   {
      List_Node<T>* garbage = head_;
      head_ = head_->next_;
      garbage->next_ = nullptr;
      delete garbage;
   }
   else 
   {
      List_Node<T>* prev = head_;
      List_Node<T>* curr = head_->next_;

      while (curr != nullptr && (cmp_(x, curr->data_) || cmp_(curr->data_, x)))
      {
	 prev = curr;
	 curr = curr->next_;
      }

      if (curr != nullptr)
      {
	 List_Node<T>* garbage = curr;
	 prev->next_ = curr->next_;
	 garbage->next_ = nullptr;
	 delete garbage;
      }
   }
}

template<typename T, class Compare>
bool
Ordered_List<T, Compare>::empty() const
{
   return head_ == nullptr;
}

template<typename T, class Compare>
void
Ordered_List<T, Compare>::swap(Ordered_List& other)
{
   std::swap(head_, other.head_);
   std::swap(cmp_, other.cmp_);
}

// helper function to copy a list
template<typename T, class Compare>
List_Node<T>* 
Ordered_List<T, Compare>::copy_(const List_Node<T>* list) const
{
   if (list == nullptr)
   {
      return nullptr;
   }

   List_Node<T>* first = new List_Node<T>{list->data_};
   List_Node<T>* last = first;

   try
   {
      list = list->next_;
      while (list != nullptr)
      {
	 last->next_ = new List_Node<T>{list->data_};
	 last = last->next_;
	 list = list->next_;
      }
   }
   catch (...)
   {
      delete first;
      throw;
   }

   return first;
}
