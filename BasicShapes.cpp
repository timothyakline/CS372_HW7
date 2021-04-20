// FNAM: BasicShapes.cpp
// DESC: Basic shape class functions
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 19 April 2021
// VERS: 1.0

#include "BasicShapes.hpp"

Circle::Circle(double radius)
    : Shape(radius * 2, radius * 2), _radius(radius) {}

void Circle::doPostScript(std::ostream &os) const {
  os << gsave() << currentpoint() << rmoveto(getWidth() / 2, 0)
     << arc(_radius, 0, 360) << stroke() << grestore();
}

Polygon::Polygon(int numSides, Length_Type sideLength)
    : _numSides(numSides), _sideLength(sideLength) {
  setWidth();
  setHeight();
  setInteriorAngle();
}

// From the Reference Solution
void Polygon::setHeight() {
  if (_numSides % 2 == 0)
    _height = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
  else
    _height =
        _sideLength * (1 + cos(PI / _numSides)) / (2 * sin(PI / _numSides));
}

// From the Reference Solution
void Polygon::setWidth() {
  if (_numSides % 4 == 0)
    _width = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
  else if (_numSides % 2 == 0)
    _width = _sideLength / sin(PI / _numSides);
  else
    _width = _sideLength * sin(PI * (_numSides - 1) / (2 * _numSides)) /
             sin(PI / _numSides);
}

void Polygon::setInteriorAngle() {
  _interiorAngle = 180 - (((_numSides - 2) * 180) / _numSides);
}

void Polygon::doPostScript(std::ostream &os) const {
  os << gsave() << rmoveto(_sideLength / -2, getHeight() / -2) << "1 1 "
     << _numSides << " {\n"
     << rlineto(_sideLength, 0) << rotate(_interiorAngle) << "}  for\n"
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

void Spacer::doPostScript(std::ostream &os) const {}

Square::Square(Length_Type sideLength) : Polygon(4, sideLength) {}

Triangle::Triangle(Length_Type sideLength) : Polygon(3, sideLength) {}
/*
Cat::Cat(Width_Type radius) : Shape{ radius * 2, radius * 2 }, _radius(radius){

}

void Cat::doPostScript(std::ostream& os) const {
        os << currentpoint() << "/y exch def\n/x exch def\n"
                << newpath() << gsave()
                << setrgbcolor(1, .67, .0) << "x y " << arc(_radius, 0, 360) <<
fill() << stroke()
                << setrgbcolor(0, 0, 1) << "x " << _radius << " 2 div sub y " <<
_radius << " 10 div 3 mul add " << _radius << " 10 div 0 360 arc\n"
                << fill() << stroke() << "x " << _radius << " 2 div add y " <<
_radius << " 10 div 3 mul add " << _radius << " 10 div 0 360 arc\n"
                << fill() << stroke()
                << "/radius " << _radius << " 5 div def\n" << newpath() <<
setrgbcolor(1, .67, 1) << "x y radius 80 100 arc\nx y radius 200 220 arc\nx y
radius 320 340 arc\n"
                << closepath() << fill() << stroke()
                << setrgbcolor(0, 0, 0) << "x " << _radius << " 5 div sub y " <<
_radius << " 10 div sub radius 230 360 arc\n" << stroke()
                << "x " << _radius << " 5 div add y " << _radius << " 10 div sub
radius 180 320 arc\n" << stroke()
                << setrgbcolor(.9, .9, .9) << "/rightwhisker {radius 50 cos mul
30 cos mul x add radius 50 cos mul 30 sin mul y add} def\n"
                << "rightwhisker moveto\n" << _radius << " 5 div " << _radius <<
" 10 div rlineto\n"
                << "rightwhisker moveto\n" << _radius << " 5 div 0 rlineto\n"
                << "rightwhisker moveto\n" << _radius << " 5 div -1 " << _radius
<< " 10 div mul rlineto\n" << stroke()
                << "/leftwhisker {-1 radius mul 50 cos mul 30 cos mul x add
radius 50 cos mul 30 sin mul y add} def\n"
                << "leftwhisker moveto\n-1 " << _radius << " 5 div mul " <<
_radius << " 10 div rlineto\n"
                << "leftwhisker moveto\n-1 " << _radius << " 5 div mul 0
rlineto\n"
                << "leftwhisker moveto\n-1 " << _radius << " 5 div mul -1 " <<
_radius << " 10 div mul rlineto\n" << stroke()
                << setrgbcolor(1, .5, 0) << "x y " << arc(_radius, 60, 60) << "x
" << _radius << " add y " << _radius << " add lineto\n"
                << "x y " << arc(_radius, 30, 60) << fill() << stroke()
                << "x y " << arc(_radius, 150, 150) << "x " << _radius << " sub
y " << _radius << " add lineto\n"
                << "x y " << arc(_radius, 120, 150) << fill() << stroke()
                << setrgbcolor(1, .67, 1) << "x y " << arc(_radius, 55, 55)
                << "x " << _radius << " 10 div 9 mul add y " << _radius << " 10
div 9 mul add lineto\n"
                << "x y " << arc(_radius, 35, 55) << fill() << stroke()
                << "x y " << arc(_radius, 145, 145)
                << "x " << _radius << " 10 div 9 mul sub y " << _radius << " 10
div 9 mul add lineto\n"
                << "x y " << arc(_radius, 125, 145) << fill() << stroke()
                << grestore();

}*/