// FNAM: Shape.hpp
// DESC: A Shape base class
// AUTH: Timothy Albert Kline
//		 Jacob Jakiemiec
//		 Riley Maranville
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 April 2021
// VERS: 2.0
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "../include/PostScript_bridge.hpp"
#include <cmath>

#include "types.h"

// IShape
// Abstract interface for the Shape class
// Purely virtual
class IShape {
  public:
    virtual ~IShape() = default;

    [[nodiscard]] virtual auto getWidth() const -> width_type = 0;
    [[nodiscard]] virtual auto getHeight() const -> height_type = 0;
    // virtual void setWidth(const width_type &wid){};
    // virtual void setHeight(const height_type &hgt){};
    virtual void doPostScript(std::ostream &os) const = 0;
};

// CRTPHelper
// Helper class for the static_cast calls
// https://www.fluentcpp.com/2017/05/19/crtp-helper/
template <typename T> struct CRTPHelper {
    // By reference
    [[nodiscard]] auto underlying() -> T & { return static_cast<T &>(*this); }
    // By const reference
    [[nodiscard]] auto underlying() const -> T const & {
        return static_cast<T const &>(*this);
    }
};

// Shape
// CRTP Base Class
// Overrides pure virtual functions from interface IShape
// for "SomeShape" to point to it's own implementations.
template <class TShape> class Shape : public IShape, public CRTPHelper<TShape> {
  protected:
    Shape(width_type width = 0, height_type height = 0);
    Shape(const Shape &) = default;
    Shape(Shape &&) = default;

  public:
    [[nodiscard]] auto getWidth() const -> width_type override;
    [[nodiscard]] auto getHeight() const -> height_type override;
    /*void setWidth(const width_type &wid) override;
    void setHeight(const height_type &hgt) override;*/
    void doPostScript(std::ostream &os) const override;

  protected:
    width_type width_;
    height_type height_;

  public:
    static constexpr double PI = 3.14159274101257324219;
    static constexpr int INTERIOR_ANGLE_MIN = 60;
    static constexpr int NUM_SIDES_MIN = 3;
};

// Default/Parameterized Constructor
template <class TShape>
inline Shape<TShape>::Shape(width_type width, height_type height)
    : width_(width), height_(height){};

/// Inline static polymorphic functions

template <class TShape>
inline auto Shape<TShape>::getHeight() const -> height_type {
    return this->underlying().height_;
};

template <class TShape>
inline auto Shape<TShape>::getWidth() const -> width_type {
    return this->underlying().width_;
};

template <class TShape>
inline void Shape<TShape>::doPostScript(std::ostream &os) const {
    this->underlying().doPostScript(os);
};

#endif // !SHAPE_HPP
