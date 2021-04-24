// FNAM: CompoundShape.cpp
// DESC: CompoundShape base class function definitions
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 22 March 2021
// UPDT: 23 April 2021
// VERS: 1.0
#include "../include/CompoundShape.hpp"

void CompoundShape::setWidth(const width_type &wid) {
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

auto CompoundShape::getShapes() const -> shape_container const & {
    return shapes_;
}

auto CompoundShape::generatePostScriptForShape(const int &index) const
    -> std::string {
    return getShapes()[index]->getPostScript();
}

auto CompoundShape::getPostScript() const -> std::string {
    std::string result = gsave();
    for (auto index = 0L; index < getShapes().size(); ++index) {
        result += moveToPositionForShape(index);
        result += generatePostScriptForShape(index);
    }
    return result;
}
