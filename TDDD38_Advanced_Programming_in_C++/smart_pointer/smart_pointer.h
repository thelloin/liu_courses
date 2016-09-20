/*
 * Given code for the exercise.
 */
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace Smart_Pointer
{

  class smart_pointer
  {
  public:
    smart_pointer() = default;
    explicit smart_pointer(int* p);
    smart_pointer(const smart_pointer& other);  // Copy constructor
    smart_pointer(smart_pointer&& other) noexcept; // Move constructor
    ~smart_pointer();
    smart_pointer& operator=(const smart_pointer& rhs) &;
    smart_pointer& operator=(smart_pointer&& rhs) & noexcept;
    smart_pointer& operator=(int* rhs);

    int& operator*();

    int* operator->();

    bool operator!() const;

    friend bool operator==(const smart_pointer& lhs, const smart_pointer& rhs);
    friend bool operator==(const smart_pointer& lhs, const int* rhs);
    friend bool operator==(const int* lhs, const smart_pointer& rhs);

    friend bool operator!=(const smart_pointer& lhs, const smart_pointer& rhs);
    friend bool operator!=(const smart_pointer& lhs, const int* rhs);
    friend bool operator!=(const int* lhs, const smart_pointer& rhs);

  private:
    int* ptr_{};

    void copy(const smart_pointer& p);

    void swap(smart_pointer& other);

    void clear();
  };

  // Is this neccessary?
  void swap(smart_pointer& x, smart_pointer& y);

  bool operator==(const smart_pointer& lhs, const smart_pointer& rhs);
  bool operator==(const smart_pointer& lhs, const int* rhs);
  bool operator==(const int* lhs, const smart_pointer& rhs);

  bool operator!=(const smart_pointer& lhs, const smart_pointer& rhs);
  bool operator!=(const smart_pointer& lhs, const int* rhs);
  bool operator!=(const int* lhs, const smart_pointer& rhs);

} // namespace smart_pointer

#endif
