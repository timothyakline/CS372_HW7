

#include "BasicShapes.hpp"
#include "CompoundShapes.hpp"
#include "PostScriptHelper.hpp"



int main()
{
    Circle circle1(90);
    Rectangle rect1(30, 40);
	Polygon poly1(5, 40);
	Square square1(120);
	Triangle triangle1(180);
    //LayeredShape cir1rect1(circle1, rect1);

	ofstream fs;
	fs.open("example.ps");
	int x = 300;
	int y = 300;
	fs << header() << moveto(x, y);
	rect1.doPostScript(fs);
	poly1.doPostScript(fs);
	circle1.doPostScript(fs);
	square1.doPostScript(fs);
	triangle1.doPostScript(fs);
	fs << showpage();
	fs.close();
    return 0;
}


