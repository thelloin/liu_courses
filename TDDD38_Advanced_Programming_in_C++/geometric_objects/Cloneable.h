#ifndef CLONEABLE_H
#define CLONEABLE_H

struct Cloneable
{
  virtual ~Cloneable() = default;
  virtual Cloneable* clone() const = 0;
};

#endif
