// FNAM: BasicShapes.hpp
// DESC: Basic shape classes
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//       Riley Maranville
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 April 2021
// VERS: 2.0
#ifndef BASICSHAPES_HPP
#define BASICSHAPES_HPP

#include "Shape.hpp"

/// Circle
// Creates a circle with a given radius.
class Circle : public Shape<Circle> {
  public:
    explicit Circle(double radius = 0.0);

  public:
    [[nodiscard]] auto getPostScript() const -> std::string override;

  private:
    double radius_;
};

/// Rectangle
// Creates a rectangle of a given width and height.
class Rectangle : public Shape<Rectangle> {
  public:
    explicit Rectangle(width_type width = 0.0, height_type height = 0.0);

  public:
    [[nodiscard]] auto getPostScript() const -> std::string override;
};

/// Spacer
// Like a rectangle, but without drawn borders.
// A spacer is not visible on the page.
class Spacer : public Shape<Spacer> {
  public:
    explicit Spacer(width_type width = 0.0, height_type height = 0.0);

  public:
    [[nodiscard]] auto getPostScript() const -> std::string override;
};

/// Polygon
// Creates a regular polygon with a given number of sides,
// each of the given length, oriented so that its lowermost side is horizontal.
class Polygon : public Shape<Polygon> {
  public:
    explicit Polygon(int numSides = NUM_SIDES_MIN,
                     length_type sideLength = 0.0);

    // Initializers
  protected:
    void initWidth();
    void initHeight();
    void initInteriorAngle();

  public:
    [[nodiscard]] auto getPostScript() const -> std::string override;

  private:
    int numSides_;
    int interiorAngle_{INTERIOR_ANGLE_MIN};
    length_type sideLength_;
};

/// Square
// Equivalent to Polygon(4,  sideLength).
class Square : public Polygon {
  public:
    explicit Square(length_type sideLength = 0.0);
};

/// Triangle
// Equivalant to Polygon(3, sideLength).
class Triangle : public Polygon {
  public:
    explicit Triangle(length_type sideLength = 0.0);
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
