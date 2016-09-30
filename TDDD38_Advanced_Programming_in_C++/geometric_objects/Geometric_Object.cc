#include "Geometric_Object.h"
#include <string>
#include <cmath>

/*
 * Point
 */
Point* Point::clone() const
{
  return new Point(x, y);
}

std::string Point::to_str() const
{
  return "Point@[x = " + std::to_string(x) + " ,y = " + std::to_string(y) + ']';
}

/*
 * Line
 */
Line* Line::clone() const
{
  return new Line(x1, y1, x2, y2);
}

double Line::get_length() const
{
  return std::sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

std::string Line::to_str() const
{
  return "Line@[x1 = " + std::to_string(x1) + " ,y1 = " + std::to_string(y1) +"x2 = " + std::to_string(x2) + " ,y2 = " + std::to_string(y2) + ']';
}

/*
 * Circle
 */
double Circle::get_area() const
{
  return M_PI * r_ * r_;
}

double Circle::get_profile() const
{
  return 2.0 * M_PI * r_;
}

double Circle::get_radius() const
{
  return r_;
}

Circle* Circle::clone() const
{
  return new Circle{ r_ };
}

std::string Circle::to_str() const
{
  return "Circle@[r = " + std::to_string(r_) + ']';
}

/*
 * Circular_Cylinder
 */
double Circular_Cylinder::get_area() const
{
  return 2.0 * Circle::get_area() + get_profile() * h_;
}

double Circular_Cylinder::get_volume() const
{
  return Circle::get_area() * h_;
}

double Circular_Cylinder::get_height() const
{
  return h_;
}

Circular_Cylinder* Circular_Cylinder::clone() const
{
  return new Circular_Cylinder{ r_, h_ };
}

std::string Circular_Cylinder::to_str() const
{
  return "Circular_Cylinder@[r = " + std::to_string(r_) +
    ",h = " + std::to_string(h_) + ']';
}

/*
 * Rectangle
 */
double Rectangle::get_area() const
{
  return a_ * b_;
}

double Rectangle::get_profile() const
{
  return 2.0 * a_ + 2.0 * b_;
}

double Rectangle::get_a() const
{
  return a_;
}

double Rectangle::get_b() const
{
  return b_;
}

Rectangle* Rectangle::clone() const
{
  return new Rectangle{ a_, b_ };
}

std::string Rectangle::to_str() const
{
  return "Rectangle@[a = " + std::to_string(a_) + ",b = " + std::to_string(b_) + ']';
}
