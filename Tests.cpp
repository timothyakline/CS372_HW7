// FNAM: Tests.cpp
// DESC: Our TDD file. Uses Catch2
// AUTH: Jacob Jakiemiec
//		 Timothy Albert Kline
//       Cody Abad
//       {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 21 March 2021
// UPDT: 22 March 2021
// VERS: 1.0
#include "catch.hpp"
#include "Shape.hpp"
#include "BasicShapes.hpp"
#include "CompoundShapes.hpp"

#include <fstream>
using std::fstream;
using std::make_unique;

const auto RADIUS_DBL = 7.0;
const auto RADIUS_INT = 7;
const auto TEST_SIDES = 5;
const auto TEST_LENGTH = 4.5;
const auto TEST_WIDTH = 3.7;
const auto TEST_HEIGHT = 8.5;
const auto PI = 3.14159274101257324219;

TEST_CASE("Shape base class construction", "[baseclass]")
{
	const auto TEST_HEIGHT = 8;
	const auto TEST_WIDTH = 5;
	Shape defaultShape;
	Shape sizedShape(TEST_WIDTH, TEST_HEIGHT);

	SECTION("Default Shape") {
		REQUIRE( defaultShape.getHeight() == 0 );
		REQUIRE( defaultShape.getWidth() == 0 );
	}

	SECTION("Defined Shape") {
		REQUIRE( sizedShape.getWidth() == TEST_WIDTH );
		REQUIRE( sizedShape.getHeight() == TEST_HEIGHT );
	}
}

TEST_CASE("Basic shapes inheritance", "[baseclass][basic]")
{
	Circle defaultCircle;
	Circle sizedIntCircle(RADIUS_INT);
	Circle sizedDblCircle(RADIUS_DBL);

	Polygon defaultPoly;
	Polygon sizedPoly(TEST_SIDES, TEST_LENGTH);

	Rectangle defaultRectangle;
	Rectangle sizedRectangle(TEST_WIDTH, TEST_HEIGHT);

	Spacer defaultSpacer;
	Spacer sizedSpacer(TEST_WIDTH, TEST_HEIGHT);

	Square defaultSquare;
	Square sizedSquare(TEST_LENGTH);

	Triangle defaultTriangle;
	Triangle sizedTriangle(TEST_LENGTH);
	
	auto tri1 = make_unique<Triangle>(TEST_LENGTH);
	RotatedShape rotateTriangle(move(tri1), QUARTER);

	SECTION("Shape") {
		SECTION("Default Base class init") {
			REQUIRE ( defaultCircle.getHeight() == 0 );
			REQUIRE ( defaultCircle.getWidth() == 0 );
			REQUIRE ( defaultPoly.getHeight() ==  0.0 * (1 + cos(PI / 3)) / (2 * sin(PI / 3)) );
			REQUIRE ( defaultPoly.getWidth() ==  (0.0 * sin(PI * (3 - 1) / (2 * 3))) / sin(PI / 3) );
		}
	}

	SECTION("Circle") {
		SECTION("Defined Base class init") {
			REQUIRE ( sizedIntCircle.getHeight() == RADIUS_INT * 2);
			REQUIRE ( sizedIntCircle.getWidth() == RADIUS_INT * 2);
			REQUIRE ( sizedDblCircle.getHeight() == RADIUS_DBL * 2);
			REQUIRE ( sizedDblCircle.getWidth() == RADIUS_DBL * 2);
		}
	}

	SECTION("Polygon") {
		SECTION("Defined Base class init") {

		}
	}
}

TEST_CASE("Complex shape inheritance", "[baseclass][complex]")
{
	auto tri1 = make_unique<Triangle>(TEST_LENGTH);
	RotatedShape rotateTriangle(move(tri1), QUARTER);

	Triangle tri(4);
	Rectangle rect(3);
	Circle cir(3.3);
	std::vector<Shape> shapes { tri, rect, cir };

	LayeredShape triRectCir(shapes);

}

TEST_CASE("Post script helper functinos") {
	SECTION("Basic commands") {
		int x = 90;
		int y = 50;
		int r = 5;
		int angle = 45;
		REQUIRE(moveto(x, y) == "90 50 moveto\n");
		REQUIRE(rmoveto(x, y) == "90 50 rmoveto\n");
		REQUIRE(lineto(x, y) == "90 50 lineto\n");
		REQUIRE(rlineto(x, y) == "90 50 rlineto\n");
		REQUIRE(arc(r, angle, angle) == "5 45 45 arc\n");
		REQUIRE(rotate(angle) == "45 rotate\n");
		REQUIRE(stroke() == "stroke\n");
		REQUIRE(header() == "%!\n\n");
		REQUIRE(showpage() == "showpage\n");
		REQUIRE(gsave() == "gsave\n");
		REQUIRE(grestore() == "grestore\n");
		REQUIRE(center() == to_string(CenterX) + " " + to_string(CenterY) + " moveto\n");
	}
	SECTION("Compound commands") {
		REQUIRE(header() + moveto(30, 50) + rlineto(90, 90) + stroke() + showpage() == "%!\n\n30 50 moveto\n90 90 rlineto\nstroke\nshowpage\n");
	}
}

TEST_CASE("Check doPostScript functions") {
	ofstream fs;
	fs.open("yoot.ps");
	fs << "500 500 moveto\n";
	//Rectangle yeet(50, 10);
	//yeet.doPostScript(fs);


	Triangle tri(40);
	Rectangle rect(30);
	Circle cir(10.3);
	std::vector<Shape> shapes { tri, rect, cir };

	LayeredShape triRectCir(shapes);
	triRectCir.doPostScript(fs);
	fs << showpage();
	fs.close();
	//REQUIRE(fs == "help");
}

TEST_CASE("Check helper functions visually with a postscript editor"){
	//set require to 0 until it works properly
	//set require to 1 when it works
	//DOUBLECHECK
	REQUIRE(0);
}
