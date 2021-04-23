// FNAM: CompoundShape.hpp
// DESC: A CompoundShape base class
//       Inherits from the base Shape class
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 22 March 2021
// UPDT: 22 April 2021
// VERS: 1.0
#ifndef COMPOUND_SHAPE_HPP
#define COMPOUND_SHAPE_HPP

#include "Shape.hpp"
#include <array>

// Base template class for complex/multi-shape shapes
class CompoundShape : public Shape<CompoundShape> {
  public:
    explicit CompoundShape();

    template <typename... TShape>
    explicit CompoundShape(TShape &&...shapes);

  protected:
    virtual void setWidth(const width_type &wid);
    virtual void setHeight(const height_type &hgt);

  protected:
    // double getMaximum(double &num);
    // double increment(double &num);
    void initDimensions();
    void updateDimensions(const width_type &wid, const height_type &hgt);

  public:
    [[nodiscard]] shape_container getShapes() const;
    void addShapes();
    template <typename TShape> void addShapes(TShape &&shape);
    template <typename TShape, typename... TSs>
    void addShapes(TShape &&shape, TSs &&...shapes);

  private:
    shape_container shapes_{};
};

//
// https://stackoverflow.com/questions/33747131/variadic-construction-for-initialising-vector-of-unique-ptr-to-base-type
//[PRECOND] `TShape` must be a std::shared_ptr<IShape>
template <typename... TShape>
inline CompoundShape::CompoundShape(TShape &&...shapes) : Shape{0, 0} {
    std::array<shape_ptr, sizeof...(shapes)> tempArray = {
        (std::move(shapes))...};
    shapes_ = shape_container{std::make_move_iterator(std::begin(tempArray)),
                              std::make_move_iterator(std::end(tempArray))};
};

/// addShapes [BASE CASE]
// Recursive Variadic Template functions
// To add shapes to an existing CompoundShape object
//[PRECOND] `TShape` must be a std::shared_ptr<IShape>
template <typename TShape>
inline void CompoundShape::addShapes(TShape &&shape) {
    shapes_.push_back(std::move(shape));
    updateDimensions(shape->getWidth(), shape->getHeight());
}

/// addShapes [RECURSIVE CASE]
// Recursive Variadic Template function
// To add shapes to an existing CompoundShape object
//[PRECOND] `TShape` must be a std::shared_ptr<IShape>
template <typename TShape, typename... TSs>
inline void CompoundShape::addShapes(TShape &&shape, TSs &&...shapes) {
    addShapes(shape);
    addShapes(shapes...); // unpacked
}

#endif // !COMPOUND_SHAPE_HPP
