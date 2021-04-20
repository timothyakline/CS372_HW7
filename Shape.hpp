// FNAM: Shape.hpp
// DESC: A Shape factory base class
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 19 April 2021
// VERS: 1.0
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "PostScriptHelper.hpp"
#include <math.h>
#include <memory>

using Width_Type = double;
using Height_Type = double;

class IShape {
public:
  virtual ~IShape() = default;

  virtual Width_Type getWidth() const = 0;
  virtual Height_Type getHeight() const = 0;
};

template <class DerivedShape> class Shape : public IShape {
protected:
  Shape(Width_Type width = 0, Height_Type height = 0)
      : _width(width), _height(height){};
  Shape(const Shape &) = default;
  Shape(Shape &&) = default;

public:
  inline Height_Type getHeight() const override {
    return (static_cast<DerivedShape const *>(this)->_height);
  }
  inline Width_Type getWidth() const override {
    return (static_cast<DerivedShape const *>(this)->_width);
  }

  virtual void doPostScript(std::ostream &os) const = 0;

protected:
  static constexpr double PI = 3.14159274101257324219;
  Width_Type _width;
  Height_Type _height;
};

#endif // !SHAPE_HPP