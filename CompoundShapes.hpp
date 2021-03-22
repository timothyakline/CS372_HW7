// FNAM: CompoundShapes.hpp
// DESC: Compound shape classes
// AUTH: Timothy Albert Kline
//       {ADD YOUR NAMES HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: N/A
// VERS: 1.0
#ifndef COMPOUNDSHAPES_HPP
#define COMPOUNDSHAPES_HPP

#include <memory>
#include <vector>

#include "Shape.hpp"

using shape_ptr = std::unique_ptr<Shape>;

//TIM: Kinda iffy on the enum...
enum RotationAngle {NONE = 0,
                    QUARTER = 90,
                    HALF = 180,
                    THREE_QUARTERS = 270,
                    TAU = 360 //not needed, but why not >:D
                    };

//Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees.
class RotatedShape : public Shape {
public:
    RotatedShape(shape_ptr shape, const RotationAngle &rotationAngle);
protected:
    shape_ptr _shape;
};

//Takes a shape, a horizontal scaling factor `fx`, and a vertical scaling factor `fy`.
//Creates a version of the shape that is scaled horizontally
//and vertically by the given scaling factors.
class ScaledShape : public Shape {
public:
    ScaledShape(shape_ptr shape, double fx, double fy);
protected:
    shape_ptr _shape;
};

class ComplexShape {
public:
    virtual ~ComplexShape() = default;
    shape_ptr getShapes() const;
protected:
    std::vector<shape_ptr> _shapes;
};

//Given a collection of shapes,
//creates a new shape consisting of all the shapes drawn with their bounding boxes centered around the current point.
//The height and width of a layered shape is the maximum of the heights and widths of the component shapes.
class LayeredShape : public Shape, public ComplexShape {
public:
    //BASE CASE
    LayeredShape(shape_ptr shape);

    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    LayeredShape(shape_ptr shape, const ARGS &...theOtherShapes)
    {
        LayeredShape oneLayer(shape);
        LayeredShape otherLayers(theOtherShapes...);
    }
};


class VerticalShape : public Shape, public ComplexShape {
public:
    //BASE CASE
    VerticalShape(shape_ptr shape);
    
    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    VerticalShape(shape_ptr shape, const ARGS &...theOtherShapes)
    {
        VerticalShape oneShape(shape);
        VerticalShape nextShapes(theOtherShapes...);
    }
};


class HorizontalShape : public Shape, public ComplexShape {
public:
    //BASE CASE
    HorizontalShape(shape_ptr shape);
    
    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    HorizontalShape(shape_ptr shape, const ARGS &...theOtherShapes)
    {
        HorizontalShape oneShape(shape);
        HorizontalShape nextShapes(theOtherShapes...);
    }
};

#endif // !COMPOUNDSHAPES_HPP