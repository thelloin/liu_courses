#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include <string>
#include "Cloneable.h"
#include "Serializeable.h"

class Geometric_Object : public Cloneable, public Serializeable
{
 public:
  ~Geometric_Object() = default;
 protected:
  Geometric_Object() = default;
  Geometric_Object(const Geometric_Object&) = default;
  Geometric_Object(Geometric_Object&&) = default;
 private:
  Geometric_Object& operator=(const Geometric_Object&) = delete;
};

struct Plane
{
  virtual double get_area() const = 0;
  virtual double get_profile() const = 0;
};

struct Solid
{
  virtual double get_area() const = 0;
  virtual double get_volume() const = 0;
};

class Point final : public Geometric_Object
{
 public:
  Point() = default;
 Point(double xp, double yp) : x{ xp }, y{ yp } {}
  ~Point() = default;

  double x{ 0.0 };
  double y{ 0.0 };

  Point* clone() const override;

 protected:
  Point(const Point&) = default;
  Point(Point&&) = default;
 
 private:
  Point& operator=(const Point&) = delete;
  std::string to_str() const override;

};

class Line final : public Geometric_Object
{
 public:
  Line() = default;
 Line(double x_1, double y_1, double x_2, double y_2) 
   : x1{ x_1 }, y1{ y_1 }, x2{ x_2 }, y2{ y_2 } {}
  ~Line() = default;

  double x1{ 0.0 };
  double y1{ 0.0 };
  double x2{ 0.0 };
  double y2{ 0.0 };

  double get_length() const;

  Line* clone() const override;
 protected:
  Line(const Line&) = default;
  Line(Line&&) = default;

 private:
  Line& operator=(const Line&) = delete;

  std::string to_str() const override;
};

class Circle : public Geometric_Object, public Plane
{
 public:
  Circle() = default;
 Circle(double rr) : r_ { rr } {}
  ~Circle() = default;

  double get_area() const override;
  double get_profile() const override final;
  double get_radius() const;

  Circle* clone() const override;
 protected:
  Circle(const Circle&) = default;
  Circle(Circle&&) = default;

  double r_{ 0.0 };

 private:
  Circle& operator=(const Circle&) = delete;

  // this might have to be moved to protected...
  std::string to_str() const override;
};

class Circular_Cylinder : public Circle, public Solid
{
 public:
  Circular_Cylinder() = default;
 Circular_Cylinder(double r, double h) : Circle{ r }, h_{ h } {}
  ~Circular_Cylinder() = default;

  double get_area() const override;
  double get_volume() const override;
  double get_height() const;

  Circular_Cylinder* clone() const override;

 protected:
  Circular_Cylinder(const Circular_Cylinder&) = default;
  Circular_Cylinder(Circular_Cylinder&&) = default;

  double h_{ 1.0 };
 private:
  Circular_Cylinder& operator=(const Circular_Cylinder&) = delete;

  std::string to_str() const override;
};

#endif
