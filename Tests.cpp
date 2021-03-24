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
using std::unique_ptr;
//using std::shared_ptr;
using std::make_unique;
//using std::make_shared;

const auto RADIUS_DBL = 7.0;
const auto RADIUS_INT = 7;
const auto TEST_SIDES = 5;
const auto TEST_LENGTH = 24.5;
const auto TEST_WIDTH = 13.7;
const auto TEST_HEIGHT = 28.5;
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
}

TEST_CASE("Complex shape inheritance", "[baseclass][complex]")
{
	auto tri1 = make_unique<Triangle>(TEST_LENGTH);
	RotatedShape rotateTriangle(std::move(tri1), QUARTER);
	
	auto tri = make_unique<Triangle>(4);
	auto rect = make_unique<Rectangle>(3);
	auto cir = make_unique<Circle>(3.3);

	//LayeredShape triRectCir(tri, rect, cir);
}

TEST_CASE("Post script helper functions") {
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
	fs.open("test.ps");
	fs << moveto(500,500);
	//Rectangle yeet(50, 10);
	//yeet.doPostScript(fs);


	auto tri1 = make_unique<Triangle>(TEST_LENGTH);
	auto rect1 = make_unique<Rectangle>(TEST_WIDTH, TEST_HEIGHT);
	auto cir1 = make_unique<Circle>(RADIUS_DBL);
	auto penta = make_unique<Polygon>(5, 35.7);
	auto nona = make_unique<Polygon>(9,57.2);
	auto rotatedTri = make_unique<RotatedShape>(std::unique_ptr<Triangle>(new Triangle(TEST_LENGTH)), QUARTER);
	auto scaledHexa = make_unique<ScaledShape>(std::unique_ptr<Polygon>(new Polygon(6, TEST_LENGTH)), 0.5, 2.0);
	
	tri1->doPostScript(fs);
	fs << moveto(400, 400);
	rotatedTri->doPostScript(fs);
	fs << moveto(300, 300);
	rect1->doPostScript(fs);
	fs << moveto(300, 400);
	cir1->doPostScript(fs);
	fs << moveto(400, 500);
	penta->doPostScript(fs);
	fs << moveto(400, 300);
	nona->doPostScript(fs);
	fs << moveto(300, 500);
	scaledHexa->doPostScript(fs);
	fs << moveto(200, 500);

	LayeredShape triRectCir(move(tri1), move(rect1), move(cir1));
	triRectCir.doPostScript(fs);
	fs << moveto(100, 500);
	HorizontalShape rotTriScalHexa(move(rotatedTri), move(scaledHexa));
	rotTriScalHexa.doPostScript(fs);
	fs << moveto(100, 300);
	VerticalShape nonaPentaDeca (move(nona), move(penta), std::unique_ptr<Polygon>(new Polygon(12, 46.2)));
	nonaPentaDeca.doPostScript(fs);
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
