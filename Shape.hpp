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

#include "types.h"

// IShape
// Abstract interface for the Shape class
// Purely virtual
class IShape {
  public:
    virtual ~IShape() = default;

    virtual width_type getWidth() const = 0;
    virtual height_type getHeight() const = 0;
    virtual void doPostScript(std::ostream &os) const {};
};

// Shape
// Utilizes the CRTP
template <class TShape> class Shape : public IShape {
  protected:
    Shape(width_type width = 0, height_type height = 0);
    Shape(const Shape &) = default;
    Shape(Shape &&) = default;

  public:
    height_type getHeight() const override;
    width_type getWidth() const override;

    void doPostScript(std::ostream &os) const override;


  protected:
    width_type width_;
    height_type height_;
  public:
    static constexpr double PI = 3.14159274101257324219;
};

//Default/Parameterized Constructor
template <class TShape>
inline Shape<TShape>::Shape(width_type width, height_type height)
    : width_(width), height_(height){
}


///Inline static polymorphic functions

template <class TShape>
inline height_type Shape<TShape>::getHeight() const {
    return (static_cast<TShape const *>(this)->height_);
}

template <class TShape>
inline width_type Shape<TShape>::getWidth() const {
    return (static_cast<TShape const *>(this)->width_);
}

template <class TShape>
inline void Shape<TShape>::doPostScript(std::ostream &os) const {
    return (static_cast<TShape const*>(this)->doPostScript(os));
}

#endif // !SHAPE_HPP
