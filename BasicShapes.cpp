// FNAM: BasicShapes.cpp
// DESC: Basic shape class functions
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 1.0

#include "BasicShapes.hpp"

Circle::Circle(double radius)
    : Shape{radius * 2, radius * 2}, _radius(radius) {}

void Circle::doPostScript(std::ostream &os) const {
  os << gsave() << currentpoint() << rmoveto(getWidth() / 2, 0)
     << arc(_radius, 0, 360) << stroke() << grestore();
}

Polygon::Polygon(int numSides, Length_Type sideLength)
    : _numSides(numSides), _sideLength(sideLength) {
  setHeightAndWidth();
}

void Polygon::setHeightAndWidth() {
  if (_numSides % 2 == 1) {
    _height =
        _sideLength * (1 + cos(PI / _numSides)) / (2 * sin(PI / _numSides));
    _width = (_sideLength * sin(PI * (_numSides - 1) / (2 * _numSides))) /
             sin(PI / _numSides);
  } else if (_numSides % 4 == 0) {
    _height = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
    _width = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
  } else {
    _height = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
    _width = _sideLength / sin(PI / _numSides);
  }
}

void Polygon::doPostScript(std::ostream &os) const {
  int _angle = 180 - (((_numSides - 2) * 180) / _numSides);
  os << gsave() << rmoveto(_sideLength / -2, getHeight() / -2) << "1 1 "
     << _numSides << " {\n"
     << rlineto(_sideLength, 0) << rotate(_angle) << "}  for\n"
     << closepath() << stroke() << grestore();
}

Rectangle::Rectangle(Width_Type width, Height_Type height)
    : Shape{width, height} {}

void Rectangle::doPostScript(std::ostream &os) const {
  os << gsave() << rmoveto(getWidth() / -2, getHeight() / -2)
     << rlineto(0, getHeight()) << rlineto(getWidth(), 0)
     << rlineto(0, -1 * getHeight()) << rlineto(-1 * getWidth(), 0)
     << closepath() << stroke() << grestore();
}

Spacer::Spacer(Width_Type width, Height_Type height) : Shape{width, height} {}

void Spacer::doPostScript(std::ostream &os) const {
  // Not used
}

Square::Square(Length_Type sideLength) : Polygon(4, sideLength) {}

Triangle::Triangle(Length_Type sideLength) : Polygon(3, sideLength) {}
