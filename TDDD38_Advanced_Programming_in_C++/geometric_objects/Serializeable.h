/*
 * Implements the NVI pattern
 */
#ifndef SERIALIZEABLE_H
#define SERIALIZEABLE_H
#include <string>

class Serializeable
{
 public:
  virtual ~Serializeable() = default;

  std::string str() const { return to_str(); };
 private:
  virtual std::string to_str() const = 0;
};

#endif
