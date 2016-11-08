/*
 * Tracer.h
 *
 * Helper class for producing output showing how objects are created, 
 * copied, moved, and destroyed.
 */
#ifndef TRACER_H
#define TRACER_H
#include <iostream>
#include <utility>

template<typename T>
struct Tracer
{
public:
   Tracer() : value() {
      if (trace) cout << "TRACE: default ctor for new Tracer[" << this << "]\n";
   }

   Tracer(const T& init) : value(init) {
      if (trace) cout << "TRACE: T ctor for new Tracer[" << this << "](" << value << ")\n";
   }

   Tracer(const Tracer& t) : value(t.value) {
      if (trace) cout << "TRACE: copy ctor for new Tracer[" << this << "](" << &t << ")\n";
   }

   Tracer(Tracer&& t) : value(std::move(t.value)) {
      if (trace) cout << "TRACE: move ctor for new Tracer[" << this << "](" << &t << ")\n";
   }

   ~Tracer() {
      if (trace) cout << "TRACE: destructor for disappearing Tracer[" << this << "]\n";
   }

   Tracer& operator=(const Tracer& t) {
      value = t.value;
      if (trace) cout << "TRACE: copy assignment for Tracer[" << this << "] = " << &t << "\n";
      return *this;
   }

   Tracer& operator=(Tracer&& t) {
      value = std::move(t.value);
      if (trace) cout << "TRACE: move assignment for Tracer[" << this << "] = " << &t << "\n";
      return *this;
   }

   static void on()  { trace = true; }
   static void off() { trace = false; }
   static bool trace;      

   T value;
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const Tracer<T>& t) {
   return os << t.value;
}

template<typename T>
bool Tracer<T>::trace(true);

#endif
