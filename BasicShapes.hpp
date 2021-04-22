// FNAM: BasicShapes.hpp
// DESC: Basic shape classes
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//       Riley Maranville
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 19 April 2021
// VERS: 1.0
#ifndef BASICSHAPES_HPP
#define BASICSHAPES_HPP

#include "Shape.hpp"

// Creates a circle with the given radius.
// The height and width of a circle are both 2*radius.
class Circle : public Shape<Circle> {
public:
  explicit Circle(double radius = 0.0);
  void doPostScript(std::ostream &os) const override;

private:
  double _radius;
};

// Creates a regular polygon with the given number of sides,
// each of the given length, oriented so that its lowermost side is horizontal.
class Polygon : public Shape<Polygon> {
public:
  using Length_Type = double;
  const int INTERIOR_ANGLE_MIN = 60;
  static const int NUM_SIDES_MIN = 3;

public:
  explicit Polygon(int numSides = NUM_SIDES_MIN, Length_Type sideLength = 0.0);
  void doPostScript(std::ostream &os) const override;

private:
  int _numSides;
  int _interiorAngle{INTERIOR_ANGLE_MIN};
  Length_Type _sideLength;

  void setWidth();
  void setHeight();
  void setInteriorAngle();
};

// Creates a rectangle of the given width and height.
class Rectangle : public Shape<Rectangle> {
public:
  explicit Rectangle(Width_Type width = 0.0, Height_Type height = 0.0);
  void doPostScript(std::ostream &os) const override;
};

// Like a rectangle, but without drawn borders. A spacer is not visible on the
// page.
class Spacer : public Shape<Spacer> {
public:
  explicit Spacer(Width_Type width = 0.0, Height_Type height = 0.0);
  void doPostScript(std::ostream &os) const override;
};

// Equivalent to Polygon(4,  sideLength).
class Square : public Polygon {
public:
  explicit Square(Length_Type sideLength = 0.0);
};

// Equivalant to Polygon(3, sideLength).
class Triangle : public Polygon {
public:
  explicit Triangle(Length_Type sideLength = 0.0);
};

/*
//unique shape
//creates a "cat" given a radius
class Cat : public Shape {
public:
        Cat(Width_Type radius = 0.0);
        void doPostScript(std::ostream& os) const override;
private:
        Width_Type _radius;
};
*/
#endif // !BASICSHAPES_HPP