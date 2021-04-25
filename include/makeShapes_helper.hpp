#ifndef MAKE_SHAPES_HELPER_HPP
#define MAKE_SHAPES_HELPER_HPP

#include "BasicShapes.hpp"
#include "ComplexShapes.hpp"
#include <memory>

auto makeCircle(double radius) -> shape_ptr;
auto makeRectangle(width_type width, height_type height) -> shape_ptr;
auto makeSpacer(width_type width, height_type height) -> shape_ptr;
auto makePolygon(int numSides, length_type sideLength) -> shape_ptr;
auto makeTriangle(length_type sideLength) -> shape_ptr;
auto makeSquare(length_type sideLength) -> shape_ptr;
auto makeScaledShape(shape_ptr shape, scale_precision_type xScale,
                     scale_precision_type yScale) -> shape_ptr;
auto makeRotatedShape(shape_ptr shape, Rot_Angle rotation) -> shape_ptr;
// template <typename TS_Ptr> shape_ptr makeLayeredShape(TS_Ptr &&shapes...);
// template <typename TS_Ptr> shape_ptr makeVerticalShape(TS_Ptr &&shapes...);
// template <typename TS_Ptr> shape_ptr makeHorizontalShape(TS_Ptr &&shapes...);

// template <typename TS_Ptr>
// inline shape_ptr makeLayeredShape(TS_Ptr &&shapes...) {
//     return std::make_shared<LayeredShape>(shapes);
// }

// template <typename TS_Ptr>
// inline shape_ptr makeVerticalShape(TS_Ptr &&shapes...) {
//     return std::make_shared<VerticalShape>(shapes);
// }

// template <typename TS_Ptr>
// inline shape_ptr makeHorizontalShape(TS_Ptr &&shapes...) {
//     return std::make_shared<HorizontalShape>(shapes);
// }
#endif // !MAKE_SHAPES_HELPER_HPP
