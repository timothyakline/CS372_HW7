// FNAM: BasicShapes.cpp
// DESC: Basic shape class functions
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0

#include "BasicShapes.hpp"

Circle::Circle(double radius)
	: Shape { radius * 2, radius * 2 },
		_radius(radius)
{
	_height = radius * 2;
	_width = radius * 2;
}

void Circle::doPostScript(std::ostream& os) const {
	int x = CenterX + _radius / 2;
	int y = CenterY + _radius / 2;
	os << gsave << newpath << x << " " << y << " " << _radius << " 0 360 " << arc << stroke << grestore;
}

Polygon::Polygon(int numSides, Length_Type sideLength): _numSides(numSides), _sideLength(sideLength){
	setHeightAndWidth();
}

void Polygon::setHeightAndWidth() {
	if (_numSides % 2 == 1) {
		_height = _sideLength * (1 + cos(PI / _numSides)) / (2 * sin(PI / _numSides));
		_width = (_sideLength * sin(PI * (_numSides - 1) / (2 * _numSides))) / sin(PI / _numSides);
	}
	else if (_numSides % 4 == 0) {
		_height = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
		_width = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
	}
	else {
		_height = _sideLength * cos(PI / _numSides) / sin(PI / _numSides);
		_width = _sideLength / sin(PI / _numSides);
	}
}

void Polygon::doPostScript(std::ostream& os) const {
	int _angle = 180 - ( ( (_numSides-2) * 180) / _numSides);
	os << gsave() << "1 1" << _numSides << " { " << _sideLength << " 0 " << rlineto << " " << _angle << " " << rotate << " }  for " << stroke << grestore;
}

//FIX?
//I forgot how to use initializer lists for the base class member variables, so rectangle and spacer just have those member variable initializations inside the function
//Tim: I found this - https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
Rectangle::Rectangle(Width_Type width, Height_Type height)
	: Shape { width, height }
{
	/*
	_width = width;
	_height = height;
	*/
}

void Rectangle::doPostScript(std::ostream& os) const {
	os << "0 " << getHeight() << " " << rlineto << " " << getWidth() << " 0 " << rlineto << " 0 -" << getHeight() << " " << rlineto << " -" << getWidth() << " 0 " << rlineto << " stroke " << stroke;
}

Spacer::Spacer(Width_Type width, Height_Type height)
	: Shape { width, height }
{
	/*
	_width = width;
	_height = height;
	*/
}

void Spacer::doPostScript(std::ostream& os) const {}

Square::Square(Length_Type sideLength): Polygon(4, sideLength){}

void Square::doPostScript(std::ostream& os) const {
	Polygon _poly(_sideLength, 4);
	_poly.doPostScript(os);
}

Triangle::Triangle(Length_Type sideLength) : Polygon(3, sideLength) {}

void Triangle::doPostScript(std::ostream& os) const {
	Polygon _poly(_sideLength, 3);
	_poly.doPostScript(os);
}