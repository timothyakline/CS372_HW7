// FNAM: CompoundShapes.cpp
// DESC: Compound shape class functions
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       Cody Abad
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 1.0
#include "CompoundShapes.hpp"
#include <algorithm>

RotatedShape::RotatedShape(Shape_Ptr shape, const RotationAngle &rotationAngle)
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

ScaledShape::ScaledShape(Shape_Ptr shape, const double &fx, const double &fy)
    : Shape{shape->getWidth(), shape->getHeight()}, _shape(move(shape)),
      _fx(fx), _fy(fy) {
  _width = _width * fx;
  _height = _height * fy;
}

void ScaledShape::doPostScript(std::ostream &os) const {
  os << gsave() << scale(_fx, _fy);
  _shape->doPostScript(os);
  os << grestore();
}

void LayeredShape::doPostScript(std::ostream &os) const {
  os << gsave();
  for (auto &&s : _shapes)
    s->doPostScript(os);
  os << grestore();
}

void VerticalShape::doPostScript(std::ostream &os) const {
  _shapes[0]->doPostScript(os);

  for (int i = 1; i < _shapes.size(); ++i) {
    Height_Type offset =
        (_shapes[i - 1]->getHeight() / 2) + (_shapes[i]->getHeight() / 2);
    os << rmoveto(0, offset);
    _shapes[i]->doPostScript(os);
  }
  os << rmoveto(0, _shapes.back()->getHeight() / 2)
     << rmoveto(0, _height / (-2));
}

void HorizontalShape::doPostScript(std::ostream &os) const {
  _shapes[0]->doPostScript(os);

  for (int i = 1; i < _shapes.size(); ++i) {
    Width_Type offset =
        (_shapes[i - 1]->getWidth() / 2) + (_shapes[i]->getWidth() / 2);
    os << rmoveto(offset, 0);
    _shapes[i]->doPostScript(os);
  }
  os << rmoveto(_shapes.back()->getWidth() / 2, 0) << rmoveto(_width / (-2), 0);
}