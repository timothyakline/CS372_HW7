#include "BasicShapes.hpp"
#include "CompoundShapes.hpp"

int main()
{
    Circle circle1(4);
    Rectangle rect1(3, 4);
    LayeredShape cir1rect1(circle1, rect1);
    return 0;
}