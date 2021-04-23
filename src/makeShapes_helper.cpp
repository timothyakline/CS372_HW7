#include "../include/makeShapes_helper.hpp"

shape_ptr makeCircle(double radius) { return std::make_shared<Circle>(radius); }

shape_ptr makeRectangle(width_type width, height_type height) {
    return std::make_shared<Rectangle>(width, height);
}

shape_ptr makeSpacer(width_type width, height_type height) {
    return std::make_shared<Spacer>(width, height);
}

shape_ptr makePolygon(int numSides, length_type sideLength) {
    return std::make_shared<Polygon>(numSides, sideLength);
}

shape_ptr makeSquare(length_type sideLength) {
    return std::make_shared<Square>(sideLength);
}

shape_ptr makeTriangle(length_type sideLength) {
    return std::make_shared<Triangle>(sideLength);
}

shape_ptr makeScaledShape(shape_ptr shape, scale_precision_type xScale,
                          scale_precision_type yScale) {
    return std::make_shared<ScaledShape>(shape, xScale, yScale);
}

shape_ptr makeRotatedShape(shape_ptr shape, Rotation_Angle rotation) {
    return std::make_shared<RotatedShape>(shape, rotation);
}

