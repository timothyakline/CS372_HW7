#include "../include/CompoundShape.hpp"

//CompoundShape::CompoundShape() : Shape{0, 0} {}

// double CompoundShape::getMaximum(double &num) {
//    for (const auto &s : shapes_) {
//        num = std::max(num, s->getHeight());
//    }
//    return num;
//}
//
// double CompoundShape::increment(double &num) {
//    for (const auto &s : shapes_) {
//        num += s->getHeight();
//    }
//    return num;
//}

void CompoundShape::setWidth(const width_type &wid)
{
    width_ = std::max(width_, wid);
}

void CompoundShape::setHeight(const height_type &hgt) {
    height_ = std::max(height_, hgt);
}

void CompoundShape::initDimensions() {
    for (const auto &s : shapes_) {
        setWidth(s->getWidth());
        setHeight(s->getHeight());
    }
}

void CompoundShape::updateDimensions(const width_type &wid,
                                     const height_type &hgt) {
    setWidth(wid);
    setHeight(hgt);
}

/// addShapes [TERMINAL/VOID/NULL CASE]
// Recursive Variadic Template functions
// To add shapes to an existing CompoundShape object
void CompoundShape::addShapes(){};

shape_container CompoundShape::getShapes() const { return shapes_; }
