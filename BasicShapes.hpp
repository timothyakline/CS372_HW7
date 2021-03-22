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
    using Length_Type = double;

public:
    Polygon(int numSides=3, Length_Type sideLength=0.0);
protected:
	int _numSides;
	Length_Type _sideLength;

	void setHeightAndWidth();

};

//Creates a rectangle of the given width and height.
class Rectangle : public Shape {
public:
    Rectangle(Width_Type width=0.0, Height_Type height=0.0);
};

//Like a rectangle, but without drawn borders. A spacer is not visible on the page.
class Spacer : public Shape {
public:
    Spacer(Width_Type width=0.0, Height_Type height=0.0);
};

//Equivalent to Polygon(3,  sideLength).
class Square : public Polygon {
public:
    Square(Length_Type sideLength=0.0);
};

//Equivalant to Polygon(4, sideLength).
class Triangle : public Polygon {
public:
    Triangle(Length_Type sideLength=0.0);
};

#endif // !BASICSHAPES_HPP