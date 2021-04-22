// FNAM: CompoundShapes.cpp
// DESC: Compound shape class functions
// AUTH: Timothy Albert Kline
//       Riley Maranville
//       Cody Abad
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 1.0
#include "CompoundShapes.hpp"
#include <algorithm>

RotatedShape::RotatedShape(shape_ptr shape, const Rotation_Angle &rotationAngle)
    : Shape{shape->getWidth(), shape->getHeight()},
      rotation_(rotationAngle) {
    shape_ = std::move(shape);
    switch (rotationAngle) {
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

ScaledShape::ScaledShape(shape_ptr shape, const scale_precision_type &fx, const scale_precision_type &fy)
    : Shape{(shape->getWidth())*fx, (shape->getHeight())*fy},
      fx_(fx), fy_(fy)
{
    shape_ = std::move(shape);
}

void ScaledShape::doPostScript(std::ostream &os) const {
    os << gsave() << scale(fx_, fy_);
    shape_->doPostScript(os);
    os << grestore();
}

ComplexShape::ComplexShape() : Shape{ 0,0 } {}

void ComplexShape::updateDimensions(){};


void LayeredShape::doPostScript(std::ostream &os) const {
    os << gsave();
    for (auto &&s : shapes_)
        s->doPostScript(os);
    os << grestore();
}

void VerticalShape::doPostScript(std::ostream &os) const {
    shapes_[0]->doPostScript(os);

    for (int i = 1; i < shapes_.size(); ++i) {
        height_type offset =
            (shapes_[i - 1]->getHeight() / 2) + (shapes_[i]->getHeight() / 2);
        os << rmoveto(0, offset);
        shapes_[i]->doPostScript(os);
    }
    os << rmoveto(0, shapes_.back()->getHeight() / 2)
       << rmoveto(0, height_ / (-2));
}

void HorizontalShape::doPostScript(std::ostream &os) const {
    shapes_[0]->doPostScript(os);

    for (int i = 1; i < shapes_.size(); ++i) {
        width_type offset =
            (shapes_[i - 1]->getWidth() / 2) + (shapes_[i]->getWidth() / 2);
        os << rmoveto(offset, 0);
        shapes_[i]->doPostScript(os);
    }
    os << rmoveto(shapes_.back()->getWidth() / 2, 0)
       << rmoveto(width_ / (-2), 0);
}