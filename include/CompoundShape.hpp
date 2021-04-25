// FNAM: CompoundShape.hpp
// DESC: A CompoundShape base class
//       Inherits from the base Shape class
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 22 March 2021
// UPDT: 23 April 2021
// VERS: 1.0
#ifndef COMPOUND_SHAPE_HPP
#define COMPOUND_SHAPE_HPP

#include "Shape.hpp"
#include <array>

// Base template class for multi-shape shapes
class CompoundShape : public Shape<CompoundShape> {
  protected:
    explicit CompoundShape() : Shape{0, 0} {};
    template <typename TShape> explicit CompoundShape(TShape &&shape);
    template <typename... TShape> explicit CompoundShape(TShape &&...shapes);

    virtual void initWidth(const width_type &wid);
    virtual void initHeight(const height_type &hgt);
    [[nodiscard]] virtual auto moveToPositionForShape(const long &index) const
        -> std::string = 0;
    void initDimensions() const;
    void updateDimensions(const width_type &wid, const height_type &hgt);

    [[nodiscard]] auto getShapes() const -> shape_container const &;
    [[nodiscard]] static auto calculateOffset(const double &lhs,
                                              const double &rhs) -> double;

    /// addShapes [TERMINAL/VOID/NULL CASE]
    // Recursive Variadic Template functions
    // To add shapes to an existing CompoundShape object
    void addShapes() const {
        /*in-case of misuse*/
    };

  public:
    /// addShapes [BASE CASE]
    // Recursive Variadic Template functions
    // To add shapes to an existing CompoundShape object
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename TShape> void addShapes(TShape &&shape) {
        shapes_.push_back(shape);
        updateDimensions(shape->getWidth(), shape->getHeight());
    }

    /// addShapes [RECURSIVE CASE]
    // Recursive Variadic Template function
    // To add shapes to an existing CompoundShape object
    //[PRECOND] `TShape` must be a std::shared_ptr<IShape>
    template <typename TShape, typename... TSs>
    void addShapes(TShape &&shape, TSs &&...shapes) {
        addShapes(shape);
        addShapes(shapes...);
    };

    [[nodiscard]] auto getPostScript() const -> std::string override;
    [[nodiscard]] auto generatePostScriptForShape(const int &index) const
        -> std::string;

  private:
    shape_container shapes_{};
};

template <typename TShape>
inline CompoundShape::CompoundShape(TShape &&shape) : Shape{0, 0} {
    addShapes(shape);
}

// https://stackoverflow.com/questions/33747131/variadic-construction-for-initialising-vector-of-unique-ptr-to-base-type
//[PRECOND] `TShape` must be a std::shared_ptr<IShape>
template <typename... TShape>
inline CompoundShape::CompoundShape(TShape &&...shapes) : Shape{0, 0} {
    std::array<shape_ptr, sizeof...(shapes)> tempArray = {shapes...};
    shapes_ = shape_container{std::make_move_iterator(std::begin(tempArray)),
                              std::make_move_iterator(std::end(tempArray))};
}

#endif // !COMPOUND_SHAPE_HPP
