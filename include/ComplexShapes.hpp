// FNAM: ComplexShapes.hpp
// DESC: Complex shape classes
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       Cody Abad
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 2.0
#ifndef COMPLEX_SHAPES_HPP
#define COMPLEX_SHAPES_HPP

#include "CompoundShape.hpp"

// Takes a shape and a rotation angle, which is either 90, 180 or 270 degrees.
class RotatedShape : public Shape<RotatedShape> {
  public:
    RotatedShape(shape_ptr shape,
                 const Rot_Angle &rotationAngle = Rot_Angle::NONE);

    [[nodiscard]] auto getPostScript() const -> std::string override;

  private:
    shape_ptr shape_;
    Rot_Angle rotation_;
};

// Takes a shape, a horizontal scaling factor `fx`, and a vertical scaling
// factor `fy`. Creates a version of the shape that is scaled horizontally and
// vertically by the given scaling factors.
class ScaledShape : public Shape<ScaledShape> {
  public:
    ScaledShape(shape_ptr shape, const scale_precision_type &fx,
                const scale_precision_type &fy);

    [[nodiscard]] auto getPostScript() const -> std::string override;

  private:
    shape_ptr shape_;
    scale_precision_type fx_;
    scale_precision_type fy_;
};

// Given a collection of shapes,
// creates a new shape consisting of all the shapes drawn with their bounding
// boxes centered around the current point. The height and width of a layered
// shape is the maximum of the heights and widths of the component shapes.
class LayeredShape : public CompoundShape {
  public:
    explicit LayeredShape() : CompoundShape(){};
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename TShape> explicit LayeredShape(TShape &&shape);
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename... TShape> explicit LayeredShape(TShape &&...shapes);

  private:
    [[nodiscard]] auto moveToPositionForShape(const long &index) const
        -> std::string override;
};

template <typename TShape>
inline LayeredShape::LayeredShape(TShape &&shape) : CompoundShape(shape) {
    initDimensions();
}

template <typename... TShape>
inline LayeredShape::LayeredShape(TShape &&...shapes)
    : CompoundShape(shapes...) {
    initDimensions();
}

class VerticalShape : public CompoundShape {
  public:
    explicit VerticalShape() : CompoundShape(){};
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename TShape> explicit VerticalShape(TShape &&shape);
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename... TShape> explicit VerticalShape(TShape &&...shapes);

  private:
    void setHeight(const height_type &hgt) override;
    [[nodiscard]] auto moveToPositionForShape(const long &index) const
        -> std::string override;
};

template <typename TShape>
inline VerticalShape::VerticalShape(TShape &&shape) : CompoundShape(shape) {
    initDimensions();
}

template <typename... TShape>
inline VerticalShape::VerticalShape(TShape &&...shapes)
    : CompoundShape(shapes...) {
    initDimensions();
}

class HorizontalShape : public CompoundShape {
  public:
    explicit HorizontalShape() : CompoundShape(){};
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename TShape> explicit HorizontalShape(TShape &&shape);
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename... TShape> explicit HorizontalShape(TShape &&...shapes);

  private:
    void setWidth(const width_type &wid) override;
    [[nodiscard]] auto moveToPositionForShape(const long &index) const
        -> std::string override;
};

template <typename TShape>
inline HorizontalShape::HorizontalShape(TShape &&shape) : CompoundShape(shape) {
    initDimensions();
}

template <typename... TShape>
inline HorizontalShape::HorizontalShape(TShape &&...shapes)
    : CompoundShape(shapes...) {
    initDimensions();
}

#endif // !COMPLEX_SHAPES_HPP
