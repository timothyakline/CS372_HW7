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

void RotatedShape::doPostScript(std::ostream &os) const {
    os << gsave() << rotate(rotation_);
    shape_->doPostScript(os);
    os << grestore();
}

ScaledShape::ScaledShape(shape_ptr shape, const scale_precision_type &fx,
                         const scale_precision_type &fy)
    : Shape{(shape->getWidth()) * fx, (shape->getHeight()) * fy},
      shape_(std::move(shape)), fx_(fx), fy_(fy) {}

void ScaledShape::doPostScript(std::ostream &os) const {
    os << gsave() << scale(fx_, fy_);
    shape_->doPostScript(os);
    os << grestore();
}

void LayeredShape::doPostScript(std::ostream &os) const {
    os << gsave() << "";
    for (const auto &s : getShapes()) {
        os << "";
        s->doPostScript(os);
        os << "";
    }
    os << grestore();
}

void VerticalShape::setHeight(const height_type &hgt) { height_ += hgt; }

void VerticalShape::doPostScript(std::ostream &os) const {
    os << gsave() << rmoveto(0, -getHeight() / 2);
    for (const auto &s : getShapes()) {
        os << rmoveto(0, s->getHeight() / 2);
        s->doPostScript(os);
        os << rmoveto(0, s->getHeight() / 2);
    }
    os << grestore();

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

void HorizontalShape::doPostScript(std::ostream &os) const {
    os << gsave() << rmoveto(-getWidth() / 2, 0);

    for (const auto &s : getShapes()) {
        os << rmoveto(s->getWidth() / 2, 0);
        s->doPostScript(os);
        os << rmoveto(s->getWidth() / 2, 0);
    }
    os << grestore();
    
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
