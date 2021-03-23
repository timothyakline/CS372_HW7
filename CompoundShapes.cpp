// FNAM: CompoundShapes.cpp
// DESC: Compound shape class functions
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0
#include <algorithm>
#include "CompoundShapes.hpp"

RotatedShape::RotatedShape(shape_ptr shape, const RotationAngle &rotationAngle)
    :_shape(move(shape)), _rotation(rotationAngle)
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

void RotatedShape::doPostScript(std::ostream& os) const {
    os << gsave << _rotation << " " << rotate;
    _shape->doPostScript(os);
    os << grestore;
}

ScaledShape::ScaledShape(shape_ptr shape, double fx, double fy)
    :_shape(move(shape))
{
    _width = _width * fx;
    _height = _height * fy;
}

void ScaledShape::doPostScript(std::ostream& os) const {
    os << gsave << _width << " " << _height << " scale ";
    _shape->doPostScript(os);
    os << grestore;
}

shape_ptr ComplexShape::getShapes() const
{
    //[WRITE ME]
    //ITERATE THROUGH _shapes TO GET SHAPES
    //Use a coroutine?
    //Include in C++ to PostScript files instead?
}

void ComplexShape::doPostScript(std::ostream& os) const {

}

LayeredShape::LayeredShape(shape_ptr shape)
{
    _height = std::max(_height, shape->getHeight());
    _width = std::max(_width, shape->getWidth());
    _shapes.push_back(move(shape));
}

void LayeredShape::doPostScript(std::ostream& os) const {
    //Riley : TO-DO
}

VerticalShape::VerticalShape(shape_ptr shape)
{
    _height = std::max(_height, shape->getHeight());
    _width = _width + shape->getWidth();
    _shapes.push_back(move(shape));
}

void VerticalShape::doPostScript(std::ostream& os) const {
    //Riley : TO-DO
}

HorizontalShape::HorizontalShape(shape_ptr shape)
{
    _height = _height + shape->getHeight();
    _width = std::max(_width, shape->getWidth());
    _shapes.push_back(move(shape));
}

void HorizontalShape::doPostScript(std::ostream& os) const {
    //Riley : TO-DO
}