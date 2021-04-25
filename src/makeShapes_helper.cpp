#include "../include/makeShapes_helper.hpp"

auto makeCircle(double radius) -> shape_ptr {
    return std::make_shared<Circle>(radius);
}

auto makeRectangle(width_type width, height_type height) -> shape_ptr {
    return std::make_shared<Rectangle>(width, height);
}

auto makeSpacer(width_type width, height_type height) -> shape_ptr {
    return std::make_shared<Spacer>(width, height);
}

auto makePolygon(int numSides, length_type sideLength) -> shape_ptr {
    return std::make_shared<Polygon>(numSides, sideLength);
}

auto makeSquare(length_type sideLength) -> shape_ptr {
    return std::make_shared<Square>(sideLength);
}

auto makeTriangle(length_type sideLength) -> shape_ptr {
    return std::make_shared<Triangle>(sideLength);
}

auto makeScaledShape(shape_ptr shape, scale_precision_type xScale,
                     scale_precision_type yScale) -> shape_ptr {
    return std::make_shared<ScaledShape>(shape, xScale, yScale);
}

auto makeRotatedShape(shape_ptr shape, Rot_Angle rotation) -> shape_ptr {
    return std::make_shared<RotatedShape>(shape, rotation);
}
