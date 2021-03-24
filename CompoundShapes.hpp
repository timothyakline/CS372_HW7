// FNAM: CompoundShapes.hpp
// DESC: Compound shape classes
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       Cody Abad
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 1.0
#ifndef COMPOUNDSHAPES_HPP
#define COMPOUNDSHAPES_HPP

#include <memory>
#include <vector>

#include "Shape.hpp"

using Shape_Ptr = std::unique_ptr<Shape>;

enum RotationAngle {
  NONE = 0,
  QUARTER = 90,
  HALF = 180,
  THREE_QUARTERS = 270,
  // TAU = 360
};

// Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees.
class RotatedShape : public Shape {
public:
  RotatedShape(Shape_Ptr shape, const RotationAngle &rotationAngle = NONE);
  void doPostScript(std::ostream &os) const override;

protected:
  Shape_Ptr _shape;
  RotationAngle _rotation;
};

// Takes a shape, a horizontal scaling factor `fx`, and a vertical scaling
// factor `fy`. Creates a version of the shape that is scaled horizontally and
// vertically by the given scaling factors.
class ScaledShape : public Shape {
public:
  ScaledShape(Shape_Ptr shape, const double &fx, const double &fy);
  void doPostScript(std::ostream &os) const override;

protected:
  Shape_Ptr _shape;
  Width_Type _fx;
  Height_Type _fy;
};

using Shape_Container_Type = std::vector<Shape_Ptr>;

// Given a collection of shapes,
// creates a new shape consisting of all the shapes drawn with their bounding
// boxes centered around the current point. The height and width of a layered
// shape is the maximum of the heights and widths of the component shapes.
class LayeredShape : public Shape {
public:
  // https://stackoverflow.com/questions/33747131/variadic-construction-for-initialising-vector-of-unique-ptr-to-base-type
  //[PRECOND] `SHAPE_TYPE` must be a unique_ptr<Shape>
  template <typename... SHAPE_TYPE>
  LayeredShape(SHAPE_TYPE &&...shapes) : Shape{} {
    Shape_Ptr shapeArray[] = {(std::move(shapes))...};
    _shapes =
        Shape_Container_Type{std::make_move_iterator(std::begin(shapeArray)),
                             std::make_move_iterator(std::end(shapeArray))};

    for (const auto &s : _shapes) {
      _height = std::max(_height, s->getHeight());
      _width = std::max(_width, s->getWidth());
    }
  }

  void doPostScript(std::ostream &os) const override;

protected:
  Shape_Container_Type _shapes{};
};

class VerticalShape : public Shape {
public:
  //[PRECOND] `SHAPE_TYPE` must be a unique_ptr<Shape>
  template <typename... SHAPE_TYPE>
  VerticalShape(SHAPE_TYPE &&...shapes) : Shape{} {
    Shape_Ptr shapeArray[] = {(std::move(shapes))...};
    _shapes =
        Shape_Container_Type{std::make_move_iterator(std::begin(shapeArray)),
                             std::make_move_iterator(std::end(shapeArray))};

    for (const auto &s : _shapes) {
      _height = _height + s->getHeight();
      _width = std::max(_width, s->getWidth());
    }
  }

  void doPostScript(std::ostream &os) const override;

protected:
  Shape_Container_Type _shapes{};
};

class HorizontalShape : public Shape {
public:
  //[PRECOND] `SHAPE_TYPE` must be a unique_ptr<Shape>
  template <typename... SHAPE_TYPE>
  HorizontalShape(SHAPE_TYPE &&...shapes) : Shape{} {
    Shape_Ptr shapeArray[] = {(std::move(shapes))...};
    _shapes =
        Shape_Container_Type{std::make_move_iterator(std::begin(shapeArray)),
                             std::make_move_iterator(std::end(shapeArray))};

    for (const auto &s : _shapes) {
      _height = std::max(_height, s->getHeight());
      _width = _width + s->getWidth();
    }
  }

  void doPostScript(std::ostream &os) const override;

protected:
  Shape_Container_Type _shapes{};
};

#endif // !COMPOUNDSHAPES_HPP