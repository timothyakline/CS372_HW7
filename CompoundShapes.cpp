// FNAM: CompoundShapes.cpp
// DESC: Compound shape class functions
// AUTH: Timothy Albert Kline
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0
#include <algorithm>
#include "CompoundShapes.hpp"

RotatedShape::RotatedShape(shape_ptr shape, const RotationAngle &rotationAngle)
    :_shape(move(shape))
{
    switch(rotationAngle)
    {
    case QUARTER:
    case THREE_QUARTERS:
        std::swap(_height,_width);
        break;
    default:
        break;
    }
}

ScaledShape::ScaledShape(shape_ptr shape, double fx, double fy)
    :_shape(move(shape))
{
    _width = _width * fx;
    _height = _height * fy;
}

shape_ptr ComplexShape::getShapes() const
{
    //[WRITE ME]
    //ITERATE THROUGH _shapes TO GET SHAPES
    //Use a coroutine?
    //Include in C++ to PostScript files instead?
}

LayeredShape::LayeredShape(shape_ptr shape)
{
    _height = std::max(_height, shape->getHeight());
    _width = std::max(_width, shape->getWidth());
    _shapes.push_back(move(shape));
}

VerticalShape::VerticalShape(shape_ptr shape)
{
    _height = std::max(_height, shape->getHeight());
    _width = _width + shape->getWidth();
    _shapes.push_back(move(shape));
}

HorizontalShape::HorizontalShape(shape_ptr shape)
{
    _height = _height + shape->getHeight();
    _width = std::max(_width, shape->getWidth());
    _shapes.push_back(move(shape));
}