

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
	}
}