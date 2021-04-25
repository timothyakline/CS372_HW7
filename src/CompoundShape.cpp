// FNAM: CompoundShape.cpp
// DESC: CompoundShape base class function definitions
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 22 March 2021
// UPDT: 23 April 2021
// VERS: 1.0
#include "../include/CompoundShape.hpp"

void CompoundShape::initWidth(const width_type &wid) {
    setWidth(std::max(getWidth(), wid));
}

void CompoundShape::initHeight(const height_type &hgt) {
    setHeight(std::max(getHeight(), hgt));
}

void CompoundShape::initDimensions() const {
    for (const auto &s : shapes_) {
        initWidth(s->getWidth());
        initHeight(s->getHeight());
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
auto CompoundShape::calculateOffset(const double &lhs, const double &rhs)
    -> double {
    return (lhs / 2 + rhs / 2);
}

auto CompoundShape::getPostScript() const -> std::string {
    std::string result = gsave();
    for (auto index = 0L; index < getShapes().size(); ++index) {
        result += moveToPositionForShape(index);
        result += generatePostScriptForShape(index);
    }
    return result;
}
