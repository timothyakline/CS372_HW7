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

struct TransformShape {
    shape_ptr shape_;
};

// Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees.
class RotatedShape : public Shape<RotatedShape>, private TransformShape {
  public:
    RotatedShape(shape_ptr shape, const Rotation_Angle &rotationAngle = NONE);
    void doPostScript(std::ostream &os) const override;

  private:
    Rotation_Angle rotation_;
};

// Takes a shape, a horizontal scaling factor `fx`, and a vertical scaling
// factor `fy`. Creates a version of the shape that is scaled horizontally and
// vertically by the given scaling factors.
class ScaledShape : public Shape<ScaledShape>, private TransformShape {
  public:
    ScaledShape(shape_ptr shape, const scale_precision_type &fx,
                const scale_precision_type &fy);
    void doPostScript(std::ostream &os) const override;

  private:
    scale_precision_type fx_;
    scale_precision_type fy_;
};


// Base template class for complex/multi-shape shapes
class ComplexShape : public Shape<ComplexShape> {
  protected:
    explicit ComplexShape();

    template <typename... TShape> explicit ComplexShape(TShape &&...shapes);

  protected:
    // Defined manually for each
    virtual void setHeight(){};
    // Defined manually for each
    virtual void setWidth(){};

    // Shared default algorithm for updating dimensions
    void updateDimensions();

  public:
    template <class TShape> void addShapes(TShape shape);
    template <class... TShape> void addShapes(TShape &&...shapes);

  protected:
    shape_container_type shapes_{};
};

// https://stackoverflow.com/questions/33747131/variadic-construction-for-initialising-vector-of-unique-ptr-to-base-type
//[PRECOND] `TShape` must be a std::shared_ptr<IShape>
template <typename... TShape>
inline ComplexShape::ComplexShape(TShape &&...shapes) : Shape{0, 0} {
    shape_ptr shapeArray[] = {(std::move(shapes))...};
    shapes_ =
        Shape_Container_Type{std::make_move_iterator(std::begin(shapeArray)),
                             std::make_move_iterator(std::end(shapeArray))};
};

template <class TShape> inline void ComplexShape::addShapes(TShape shape) {}

template <class... TShape>
inline void ComplexShape::addShapes(TShape &&...shape) {}

// Given a collection of shapes,
// creates a new shape consisting of all the shapes drawn with their bounding
// boxes centered around the current point. The height and width of a layered
// shape is the maximum of the heights and widths of the component shapes.
class LayeredShape : public ComplexShape {
  public:
    // https://stackoverflow.com/questions/33747131/variadic-construction-for-initialising-vector-of-unique-ptr-to-base-type
    //[PRECOND] `SHAPE_TYPE` must be a shared_ptr<Shape>
    template <typename... TShape> LayeredShape(TShape &&...shapes) : Shape{} {
        shape_ptr shapeArray[] = {(std::move(shapes))...};
        shapes_ = Shape_Container_Type{
            std::make_move_iterator(std::begin(shapeArray)),
            std::make_move_iterator(std::end(shapeArray))};

        for (const auto &s : shapes_) {
            _height = std::max(_height, s->getHeight());
            _width = std::max(_width, s->getWidth());
        }
    }

    void doPostScript(std::ostream &os) const override;
};

class VerticalShape : public ComplexShape {
  public:
    //[PRECOND] `SHAPE_TYPE` must be a unique_ptr<Shape>
    template <typename... TShape> VerticalShape(TShape &&...shapes) : Shape{} {
        for (const auto &s : shapes_) {
            _height = _height + s->getHeight();
            _width = std::max(_width, s->getWidth());
        }
    }

    void doPostScript(std::ostream &os) const override;
};

class HorizontalShape : public ComplexShape {
  public:
    //[PRECOND] `SHAPE_TYPE` must be a unique_ptr<Shape>
    template <typename... TShape>
    HorizontalShape(TShape &&...shapes) : Shape{} {
        shape_ptr shapeArray[] = {(std::move(shapes))...};
        shapes_ = Shape_Container_Type{
            std::make_move_iterator(std::begin(shapeArray)),
            std::make_move_iterator(std::end(shapeArray))};

        for (const auto &s : shapes_) {
            _height = std::max(_height, s->getHeight());
            _width = _width + s->getWidth();
        }
    }

    void doPostScript(std::ostream &os) const override;
};

#endif // !COMPOUNDSHAPES_HPP
