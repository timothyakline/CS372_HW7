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
#include "CompoundShapes.hpp"
#include <algorithm>


RotatedShape::RotatedShape(shape_ptr shape, const RotationAngle &rotationAngle)
    : Shape{shape->getWidth(), shape->getHeight()}, _shape(move(shape)),
      _rotation(rotationAngle) {
  switch (rotationAngle) {
  case QUARTER:
  case THREE_QUARTERS:
    std::swap(_height, _width);
    break;
  default:
    break;
  }
}

void RotatedShape::doPostScript(std::ostream &os) const {
  os << gsave() << rotate(_rotation);
  _shape->doPostScript(os);
  os << grestore();
}

ScaledShape::ScaledShape(shape_ptr shape, double fx, double fy)
    : Shape{ shape->getWidth(), shape->getHeight() }, _shape(move(shape))
    ,_fx(fx), _fy(fy) {
  _width = _width * fx;
  _height = _height * fy;
}

void ScaledShape::doPostScript(std::ostream &os) const {
  os << gsave() << _width << " " << _height << " scale ";
  _shape->doPostScript(os);
  os << " " << grestore();
}

//void ComplexShape::doPostScript(std::ostream &os) const {}

/*
LayeredShape::LayeredShape(shape_ptr shapes...) {
  _height = std::max(_height, shape->getHeight());
  _width = std::max(_width, shape->getWidth());
  _shapes.push_back(move(shape));
}*/
/*
template<class S>
LayeredShape::LayeredShape(std::vector<S> shapes)
    :ComplexShape{ shapes }
{
    for( auto s : shapes )
    {
        _height = std::max(_height, s.getHeight());
        _width = std::max(_width, s.getWidth());
    }
}*/

void LayeredShape::doPostScript(std::ostream &os) const {
  os << gsave();
  for (auto s : _shapes) s.doPostScript(os);
  os << grestore();
}

VerticalShape::VerticalShape(std::vector<Shape> shapes)
    :ComplexShape{ shapes }
{
    for( auto s : shapes )
    {
        _height = _height + s.getHeight();
        _width = std::max(_width, s.getWidth());
    }
}

/*
VerticalShape::VerticalShape(shape_ptr shape) {
  _height = _height + shape->getHeight();
  _width = std::max(_width, shape->getWidth());
  _shapes.push_back(move(shape));
}*/


void VerticalShape::doPostScript(std::ostream &os) const {
  //os << gsave();
  _shapes[0].doPostScript(os);

  for (int i = 1; i <= _shapes.size(); ++i) {
    Height_Type offset = (_shapes[i-1].getHeight()/2) + (_shapes[i].getHeight()/2);
    os << rmoveto(0,offset);
    _shapes[i].doPostScript(os);
  }
  os << rmoveto(0, _shapes.back().getHeight()/2) << rmoveto(0, _height/(-2));
  //os << grestore();
}

HorizontalShape::HorizontalShape(std::vector<Shape> shapes)
    :ComplexShape{ shapes }
{
    for( auto s : shapes )
    {
        _height = std::max(_height, s.getHeight());
        _width = _width + s.getWidth();
    }
}

/*
HorizontalShape::HorizontalShape(shape_ptr shape) {
  _height = std::max(_height, shape->getHeight());
  _width = _width + shape->getWidth();
  _shapes.push_back(move(shape));
}*/

void HorizontalShape::doPostScript(std::ostream &os) const {
  //os << gsave();
  _shapes[0].doPostScript(os);

  for (int i = 1; i <= _shapes.size(); ++i) {
    Width_Type offset = (_shapes[i-1].getWidth()/2) + (_shapes[i].getWidth()/2);
    os << rmoveto(offset,0);
    _shapes[i].doPostScript(os);
  }
  os << rmoveto(_shapes.back().getWidth()/2, 0) << rmoveto(_width/(-2), 0);
  //os << grestore();
}