// FNAM: ComplexShapes.cpp
// DESC: Complex shape class functions
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       Cody Abad
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 April 2021
// VERS: 2.0
#include "../include/ComplexShapes.hpp"
#include <algorithm>

RotatedShape::RotatedShape(shape_ptr shape, const Rotation_Angle &rotationAngle)
    : Shape{shape->getWidth(), shape->getHeight()}, shape_(std::move(shape)),
      rotation_(rotationAngle) {
    switch (rotation_) {
    case QUARTER:
    case THREE_QTRS:
        std::swap(height_, width_);
        break;
    default:
        break;
    }
}

auto RotatedShape::getPostScript() const -> std::string {
    std::string result = gsave() + rotate(rotation_);
    result += rmoveto(0, 0);
    result += shape_->getPostScript();
    result += rmoveto(0, 0);
    return result += grestore();
}

ScaledShape::ScaledShape(shape_ptr shape, const scale_precision_type &fx,
                         const scale_precision_type &fy)
    : Shape{(shape->getWidth()) * fx, (shape->getHeight()) * fy},
      shape_(std::move(shape)), fx_(fx), fy_(fy) {}

auto ScaledShape::getPostScript() const -> std::string {
    std::string result = gsave() + scale(fx_, fy_);
    result += rmoveto(0, 0);
    result += shape_->getPostScript();
    result += rmoveto(0, 0);
    return result += grestore();
}

auto LayeredShape::moveToPositionForShape(const long &index) const
    -> std::string {
    return rmoveto(0, 0);
    // std::string result = gsave() + rmoveto(0, 0);
    // for (const auto &s : getShapes()) {
    //    result += rmoveto(0, 0);
    //    result += s->getPostScript();
    //    result += rmoveto(0, 0);
    //}
    // return result += grestore();
}

void VerticalShape::setHeight(const height_type &hgt) { height_ += hgt; }

auto VerticalShape::moveToPositionForShape(const long &index) const
    -> std::string {
    if (index == 0L) {
        return rmoveto(
            0, calculateOffset(getShapes()[index]->getHeight(), -getHeight()));
    }
    // if (index == getShapes().size()) {
    //    return rmoveto(0, getShapes()[index]->getHeight() / 2);
    //}
    return rmoveto(0, calculateOffset(getShapes()[index]->getHeight(),
                                      getShapes()[index - 1]->getHeight()));
    /*std::string result = gsave() + rmoveto(0, -getHeight() / 2.0);
    for (const auto &s : getShapes()) {
        result += rmoveto(0, s->getHeight() / 2);
        result += s->getPostScript();
        result += rmoveto(0, s->getHeight() / 2);
    }
    return result += grestore();*/

    /*shapes_[0]->doPostScript(os);

    for (int i = 1; i < shapes_.size(); ++i) {
        height_type offset =
            (shapes_[i - 1]->getHeight() / 2) + (shapes_[i]->getHeight() / 2);
        os << rmoveto(0, offset);
        shapes_[i]->doPostScript(os);
    }
    os << rmoveto(0, shapes_.back()->getHeight() / 2)
       << rmoveto(0, height_ / (-2));*/
}

void HorizontalShape::setWidth(const width_type &wid) { width_ += wid; }

auto HorizontalShape::moveToPositionForShape(const long &index) const
    -> std::string {
    if (index == 0L) {
        return rmoveto(
            calculateOffset(getShapes()[index]->getWidth(), -getWidth()), 0);
    }
    // if (index == getShapes().size())) {
    //    return rmoveto(getShapes()[index]->getWidth() / 2, 0);
    //}
    return rmoveto(calculateOffset(getShapes()[index]->getWidth(),
                                   getShapes()[index - 1]->getWidth()),
                   0);
    // std::string result = gsave() + rmoveto(-getWidth() / 2, 0);
    // for (const auto &s : getShapes()) {
    //    result += rmoveto(s->getWidth() / 2, 0);
    //    result += s->getPostScript();
    //    result += rmoveto(s->getWidth() / 2, 0);
    //}
    // return result += grestore();

    /*shapes_[0]->doPostScript(os);

    for (int i = 1; i < shapes_.size(); ++i) {
        width_type offset =
            (shapes_[i - 1]->getWidth() / 2) + (shapes_[i]->getWidth() / 2);
        os << rmoveto(offset, 0);
        shapes_[i]->doPostScript(os);
    }
    os << rmoveto(shapes_.back()->getWidth() / 2, 0)
       << rmoveto(width_ / (-2), 0);*/
}
