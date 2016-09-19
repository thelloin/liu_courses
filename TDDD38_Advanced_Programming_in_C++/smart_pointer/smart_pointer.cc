#include "smart_pointer.h"

#include <iostream>
#include <utility>

namespace Smart_Pointer
{
  smart_pointer::smart_pointer(int* p) : ptr_{p} { }

  // Copy constructor
  smart_pointer::smart_pointer(const smart_pointer& other)
  {
    copy(other);
  }

  // Move constructor
  smart_pointer::smart_pointer(smart_pointer&& other) noexcept
  {
    swap(other);
  }

  smart_pointer::~smart_pointer()
  {
    delete ptr_;
  }

  // Copy assignment operator
  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs) &
  {
    smart_pointer{ rhs }.swap(*this);
    return *this;
  }

  // Move assignment operator
  smart_pointer& smart_pointer::operator=(smart_pointer&& rhs) & noexcept
  {
    if (this != &rhs)
      {
	clear();
	swap(rhs);
      }
    return *this;
  }

  smart_pointer& smart_pointer::operator=(int* rhs)
  {
    smart_pointer{ rhs }.swap(*this);
    return *this;
  }

  int& smart_pointer::operator*()
  {
    return *ptr_;
  }

  int* smart_pointer::operator->()
  {
    return ptr_;
  }

  void smart_pointer::copy(const smart_pointer& p)
  {
    ptr_ = (p.ptr_ != nullptr) ? new int{ *p.ptr_ } : nullptr;
  }

  void smart_pointer::swap(smart_pointer& other)
  {
    std::swap(ptr_, other.ptr_);
  }

  void smart_pointer::clear()
  {
    std::cout << "In smart_pointer::clear()" << std::endl;
    delete ptr_;
    ptr_ = nullptr;
  }

}
