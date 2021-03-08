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

#include "Shape.hpp"

using shape_ptr = std::unique_ptr<Shape>; //TIM: For later?


//Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees.
class RotatedShape : public Shape {
///MEMBER TYPES
public:
    //TIM: Kinda iffy on the enum...
    enum RotationAngle {NONE = 0,
                        QUARTER = 90,
                        HALF = 180,
                        THREE_QUARTERS = 270,
                        TAU = 360 //not needed, but why not >:D
                        };
///CONSTRUCTOR
public:
    RotatedShape(const Shape &shape, RotationAngle rotationAngle);
};

//Takes a shape, a horizontal scaling factor `fx`, and a vertical scaling factor `fy`.
//Creates a version of the shape that is scaled horizontally
//and vertically by the given scaling factors.
class ScaledShape : public Shape {
public:
    ScaledShape(const Shape &shape, double fx, double fy);
};

//Given a collection of shapes,
//creates a new shape consisting of all the shapes drawn with their bounding boxes centered around the current point.
//The height and width of a layered shape is the maximum of the heights and widths of the component shapes.
class LayeredShape : public Shape {
public:
    //BASE CASE
    //[PRECOND] `S` must be a `Shape` class type
    //template<typename S>
    LayeredShape(const Shape &shape);
    //TIM:              ^^^ Hardcode `Shape`, or no?

    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    LayeredShape(const Shape &shape, const ARGS &...theOtherShapes)
    //TIM:              ^^^ Hardcode `Shape`, or no?
    {
        LayeredShape oneLayer(shape);
        LayeredShape otherLayers(theOtherShapes...);
    }
};


class VerticalShape : public Shape {
public:
    //BASE CASE
    //[PRECOND] `S` must be a `Shape` class type
    //template<class S>
    VerticalShape(const Shape &shape);
    //TIM:               ^^^ Hardcode `Shape`, or no?
    
    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    VerticalShape(const Shape &shape, const ARGS &...theOtherShapes)
    //TIM:               ^^^ Hardcode `Shape`, or no?
    {
        VerticalShape oneShape(shape);
        VerticalShape nextShapes(theOtherShapes...);
    }
};


class HorizontalShape : public Shape {
public:
    //BASE CASE
    //[PRECOND] `S` must be a `Shape` class type
    //template<class S>
    HorizontalShape(const Shape &shape);
    //TIM:                 ^^^ Hardcode `Shape`, or no?
    
    //RECURSIVE CASE
    //[PRECOND] `ARGS` must be a `Shape` class type
    template<class ...ARGS>
    HorizontalShape(const Shape &firstShape, const ARGS &...theOtherShapes)
    //TIM:                 ^^^ Hardcode `Shape`, or no?    
    {
        HorizontalShape oneShape(firstShape);
        HorizontalShape nextShapes(theOtherShapes...);
    }
};

#endif // !COMPOUNDSHAPES_HPP