// FNAM: types.hpp
// DESC: Contains all modifiable data type aliases
// AUTH: Timothy Albert Kline

// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 22 March 2021
// UPDT: 22 April 2021
// VERS: 1.0
#ifndef TYPES_H
#define TYPES_H

#include <memory>
#include <vector>

using width_type = double;
using height_type = double;
using length_type = double;
using scale_precision_type = double;

// Forward declare
class IShape;

// handle for smart pointer type
using shape_ptr = std::shared_ptr<IShape>;
// handle for container of the smart pointer type for shapes
using shape_container = std::vector<shape_ptr>;

// Enum for select rotation angles
enum Rot_Angle {
    NONE = 0,
    QUARTER = 90,
    HALF = 180,
    THREE_QTRS = 270,
    TAU = 360
};

#endif // !TYPES_H
