// FNAM: BasicShapes.cpp
// DESC: Basic shape class functions
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 April 2021
// VERS: 2.0

#include "../include/BasicShapes.hpp"
#include "../include/PostScript_bridge.hpp"

Circle::Circle(double radius)
    : Shape(radius * 2, radius * 2), radius_(radius) {}

//Modified to copy the reference solution
void Circle::doPostScript(std::ostream &os) const {
    os << gsave() << currentpoint()
       << /*rmoveto(getWidth() / 2, 0)*/ translate() << newpath() << point(0,0)
       << arc(radius_, 0, Rotation_Angle::TAU)
       << closepath() << stroke() << grestore();
}

Rectangle::Rectangle(width_type width, height_type height)
    : Shape{width, height} {}

//Modified to copy the reference solution
void Rectangle::doPostScript(std::ostream &os) const {
    os << gsave() << rmoveto(-getWidth() / 2, -getHeight() / 2)
       << rlineto(getWidth(), 0) << rlineto(0, getHeight())
       << rlineto(0, getHeight()) << rlineto(-1 * getWidth(), 0)
       << closepath() << stroke() << grestore();
}

Spacer::Spacer(width_type width, height_type height) : Shape{width, height} {}

void Spacer::doPostScript(std::ostream &os) const {}

Polygon::Polygon(int numSides, length_type sideLength)
    : numSides_(numSides), sideLength_(sideLength) {
    initWidth();
    initHeight();
    initInteriorAngle();
}

// From the Reference Solution
void Polygon::initHeight() {
    if (numSides_ % 2 == 0) {
        height_ = sideLength_ * cos(PI / numSides_) / sin(PI / numSides_);
    } else {
        height_ =
            sideLength_ * (1 + cos(PI / numSides_)) / (2 * sin(PI / numSides_));
    }
}

// From the Reference Solution
void Polygon::initWidth() {
    if (numSides_ % 4 == 0) {
        width_ = sideLength_ * cos(PI / numSides_) / sin(PI / numSides_);
    } else if (numSides_ % 2 == 0) {
        width_ = sideLength_ / sin(PI / numSides_);
    } else {
        width_ = sideLength_ * sin(PI * (numSides_ - 1) / (2 * numSides_)) /
                 sin(PI / numSides_);
    }
}

void Polygon::initInteriorAngle() {
    interiorAngle_ = Rotation_Angle::HALF -
                     (((numSides_ - 2) * Rotation_Angle::HALF) / numSides_);
}

void Polygon::doPostScript(std::ostream &os) const {
    os << gsave() << rmoveto(sideLength_ / -2, getHeight() / -2) << "1 1 "
       << numSides_ << " {\n"
       << rlineto(sideLength_, 0) << rotate(interiorAngle_) << "}  for\n"
       << closepath() << stroke() << grestore();
}

Square::Square(length_type sideLength) : Polygon(4, sideLength) {}

Triangle::Triangle(length_type sideLength) : Polygon(3, sideLength) {}

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
