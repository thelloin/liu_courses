
#include <iostream>

using namespace std;

struct callback
{
  virtual ~callback() noexcept = default;
  virtual void operator()() const = 0;
};

template<void (*fp)()>
struct callback_function : public callback
{
  virtual void operator()() const { fp(); }
};

template<typename T, void (T::*pmf)()>
class callback_member_function : public callback
{
public:
  explicit callback_member_function(T& obj) : obj_ref(&obj) {}
  virtual void operator()() const { (obj_ref->*pmf)(); }
private:
  T* obj_ref;
};

void hello()
{
  cout << "Hello!" << endl;
}

struct S
{
  void hello() { cout << "Hello, there!" << endl; }
};

void greet(callback const& cb)
{
  cb();
}

int main()
{
  greet(callback_function<hello>());
  S s;
  greet(callback_member_function<S, &S::hello>(s));

  return 0;
}
