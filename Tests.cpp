/*

#include "catch.hpp"
#include "PostScriptHelper.hpp"

TEST_CASE("Post script helper functinos") {
	SECTION("Basic commands") {
		int x = 90;
		int y = 50;
		int angle = 45;
		REQUIRE(moveTo(x, y) == "90 50 moveto\n");
		REQUIRE(RMoveTo(x, y) == "90 50 rmoveto\n");
		REQUIRE(lineTo(x, y) == "90 50 lineto\n");
		REQUIRE(RLineTo(x, y) == "90 50 rlineto\n");
		REQUIRE(rotate(angle) == "45 rotate\n");
		REQUIRE(stroke() == "stroke\n");
		REQUIRE(header() == "%!\n\n");
		REQUIRE(showpage() == "showpage\n");
	}
	SECTION("Compound commands") {
		REQUIRE(header() + moveTo(30, 50) + RLineTo(90, 90) + stroke() + showpage() == "%!\n\n30 50 moveto\n90 90 rlineto\nstroke\nshowpage\n");
	}
}
TEST_CASE("Check helper functions visually with a postscript editor"){
	//set require to 0 until it works properly
	//set require to 1 when it works
	//DOUBLECHECK
	REQUIRE(0);
}
*/