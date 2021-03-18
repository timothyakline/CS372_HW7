// FNAM: BasicShapes.cpp
// DESC: Basic shape class functions
// AUTH: Timothy Albert Kline
//       {ADD YOUR NAMES HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: N/A
// VERS: 1.0

#include "BasicShapes.hpp"

Circle::Circle(double radius){
	_height = radius * 2;
	_width = radius * 2;
}

Polygon::Polygon(int numSides, double sideLength): _numSides(numSides), _sideLength(sideLength){
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

//FIX?
//I forgot how to use initializer lists for the base class member variables, so rectangle and spacer just have those member variable initializations inside the function
Rectangle::Rectangle(double width, double height){
	_width = width;
	_height = height;
}

Spacer::Spacer(double width, double height){
	_width = width;
	_height = height;
}

Square::Square(double sideLength): Polygon(4, sideLength){}

Triangle::Triangle(double sideLength) : Polygon(3, sideLength) {}