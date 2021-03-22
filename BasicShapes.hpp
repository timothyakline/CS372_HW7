// FNAM: BasicShapes.hpp
// DESC: Basic shape classes
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//       {ADD YOUR NAMES HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: N/A
// VERS: 1.0
#ifndef BASICSHAPES_HPP
#define BASICSHAPES_HPP

#include "Shape.hpp"

//Creates a circle with the given radius.
//The height and width of a circle are both 2*radius.
class Circle : public Shape {
public:
    Circle(double radius=0.0);
protected:
    double _radius;
};

//Creates a regular polygon with the given number of sides,
//each of the given length, oriented so that its lowermost side is horizontal.
class Polygon : public Shape {
public:
    Polygon(int numSides, double sideLength);
protected:
	int _numSides;
	int _sideLength;

	void setHeightAndWidth();

};

//Creates a rectangle of the given width and height.
class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
};

//Like a rectangle, but without drawn borders. A spacer is not visible on the page.
class Spacer : public Shape {
public:
    Spacer(double width, double height);
};

//Equivalent to Polygon(3,  sideLength).
class Square : public Polygon {
public:
    Square(double sideLength);
};

//Equivalant to Polygon(4, sideLength).
class Triangle : public Polygon {
public:
    Triangle(double sideLength);
};

#endif // !BASICSHAPES_HPP