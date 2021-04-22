// FNAM: Shape.hpp
// DESC: A Shape factory base class
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 April 2021
// VERS: 1.0
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "PostScriptHelper.hpp"
#include <cmath>
#include <memory>

//Type Aliases / Handles on data types
using Width_Type = double;
using Height_Type = double;

//IShape
//Abstract interface for the Shape class
//Purely virtual
class IShape {
public:
  virtual ~IShape() = default;

  virtual Width_Type getWidth() const = 0;
  virtual Height_Type getHeight() const = 0;
  virtual void doPostScript(std::ostream &os) const {}
};

//Shape
//Utilizes the CRTP
template <class DerivedShape>
class Shape : public IShape {
protected:
  Shape(Width_Type width = 0, Height_Type height = 0);
  Shape(const Shape &) = default;
  Shape(Shape &&) = default;

public:
    Height_Type getHeight() const override;
    Width_Type getWidth() const override;

    void doPostScript(std::ostream& os) const override;

protected:
  static constexpr double PI = 3.14159274101257324219;
  Width_Type _width;
  Height_Type _height;
};

template<class DerivedShape>
inline Shape<DerivedShape>::Shape(Width_Type width, Height_Type height)
    : _width(width), _height(height)
{};

template <class DerivedShape>
inline Height_Type Shape<DerivedShape>::getHeight() const {
	return (static_cast<DerivedShape const*>(this)->_height);
}

template<class DerivedShape>
inline Width_Type Shape<DerivedShape>::getWidth() const {
	return (static_cast<DerivedShape const*>(this)->_width);
}

template<class DerivedShape>
inline void Shape<DerivedShape>::doPostScript(std::ostream& os) const {
    return (static_cast<DerivedShape const*>(this)->doPostScript(os);
}

#endif // !SHAPE_HPP