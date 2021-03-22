// FNAM: Shape.hpp
// DESC: A Shape factory base class
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//       {ADD YOUR NAMES HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <math.h>

using Width_Type = double;
using Height_Type = double;

class Shape {
public:
	Shape(Width_Type width=0, Height_Type height=0) : _width(width), _height(height) {}
    virtual ~Shape() = default;
	Height_Type getHeight() const;
	Width_Type getWidth() const;

protected:
	Width_Type _width;
	Height_Type _height;
	const double PI = 3.14159274101257324219;
};

#endif // !SHAPE_HPP