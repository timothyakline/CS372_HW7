# CS372-Project-2

# Shape language
The CPS shape language relies on the following fundamental notions:
## Bounding box. 
   * Every shape has a  bounding box: an imaginary rectangle that encloses the shape.  Bounding boxes are not drawn. The  height ( width) of a shape is the height (width) of its bounding box. Bounding boxes are shown below using dotted lines.
## Current point. 
   * The  current point represents the coordinates of the current location of the cursor. In  PostScript, these coordinates are given by the command  currentpoint. A shape is drawn so that its bounding box is  centered around the current point. The center of an bounding box is shown below as a small black circle.
## Units. 
   * Postscript's basic unit of measurement is 1/72 of an inch. When referring to lengths below (e.g. radius, width or height), we are assuming this measurement system. For example, if a shape has a height of 36, that means 36 units, which is 36/72 = 1/2 inch.
CPS is based on a language of immutable shapes, that are either basic or compound.

# Basic shapes
## Basic shapes are primitive shapes that can be created without reference to any other shapes.
 1. Circle(double radius). Creates a circle with the given radius. The height and width of a circle are both 2*radius.


 2. Polygon(int numSides, double sideLength). Creates a regular polygon with the given number of sides, each of the given length, oriented so that its lowermost side is horizontal.


 3. Rectangle(double width, double height). Creates a rectangle of the given width and height.


 4. Spacer(double width, double height). Like a rectangle, but without drawn borders. A spacer is not visible on the page.
 5. Square(double sideLength). Equivalent to Polygon(4,  sideLength).
 6. Triangle(double sideLength). Equivalent to Polygon(3,  sideLength).

## Compound shapes
Compound shapes are shapes that are constructed from one or more other shapes, which may themselves be basic or compound.
* Rotated(Shape shape, RotationAngle rotationAngle). Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees. Creates a version of the shape that is rotated counterclockwise by the specified number of degrees around the origin of its bounding box. If the rotation angle is 90 or 270 degrees, the height (width) of the resulting shape is equal to the width (height) of the original shape.
* Scaled(Shape shape, double fx, double fy). Takes a shape, a horizontal scaling factor  fx, and a vertical scaling factor  fy. Creates a version of the shape that is scaled horizontally and vertically by the given scaling factors.


* Layered(Shape... shapes). Given a collection of shapes, creates a new shape consisting of all the shapes drawn with their bounding boxes centered around the current point. The height and width of a layered shape is the maximum of the heights and widths of the component shapes.


* Vertical(Shape... shapes). Takes an ordered collection of shapes, and creates a shape structured as follows:
  * Shape shapes[i+1]'s bounding box is located directly above the bounding box of shapes[i], and both bounding boxes are vertically aligned around their center.
  * The height of the resulting shape's bounding box is the sum of the heights of the component shapes.
  * The width of the resulting shape's bounding box is the maximum width of the widths of the component shapes.


* Horizontal(Shape... shapes). Takes an ordered collection of shapes, and creates a shape structured as follows:
  * Shape shapes[i+1]'s bounding box is located next to (to the right of) the bounding box of shapes[i], and both bounding boxes are horizontally aligned around their center.
  * The width of the resulting shape's bounding box is the sum of the widths of the component shapes.
  * The height of the resulting shape's bounding box is the maximum width of the heights of the component shapes.
# CPS to PostScript translator
CPS lets the user translate any shape into a sequence of  PostScript commands. The user can specify the name of the resulting file. The resulting file is a legal  PostScript file that can be previewed on screen or printed on paper.
