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


class Shape {
public:
	Shape(int width=0, int height=0) : _width(width), _height(height) {}
    virtual ~Shape() = default;
	int getHeight() const;
	int getWidth() const;

protected:
	int _height;
	int _width;
	const double PI = 3.14159274101257324219;
};

#endif // !SHAPE_HPP