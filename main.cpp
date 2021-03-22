

#include "BasicShapes.hpp"
#include "CompoundShapes.hpp"
#include "PostScriptHelper.hpp"



int main()
{
    Circle circle1(4);
    Rectangle rect1(3, 4);
    LayeredShape cir1rect1(circle1, rect1);

	ofstream fs;
	fs.open("example.ps");
	int x = 70;
	int y = 50;
	fs << header() << moveTo(x, y) << RLineTo(90, 90) << rotate(45) << RLineTo(90, 0) << stroke();
	fs << moveTo(500, 500) << lineTo(550, 500) << stroke() << RMoveTo(0, 50) << lineTo(500, 550) << stroke() << showpage();
	fs.close();
    return 0;
}
