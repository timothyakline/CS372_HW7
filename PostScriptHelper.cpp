// FNAM: PostScriptHelper.cpp
// DESC: C++ to PostScript functions
// AUTH: Timothy Albert Kline
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: N/A
// VERS: 1.0

#include "PostScriptHelper.hpp"

string moveTo( int x, int y) {
	return to_string(x) + " " + to_string(y) + " moveto\n";
}

string RMoveTo(int x, int y) {
	return to_string(x) + " " + to_string(y) + " rmoveto\n";
}

string lineTo(int x, int y) {
	return to_string(x) + " " + to_string(y) + " lineto\n";
}

string RLineTo(int x, int y) {
	return to_string(x) + " " + to_string(y) + " rlineto\n";
}

//angle is clockwise
string rotate(int angle) {
	return to_string(angle) + " rotate\n";
}

string stroke() {
	return "stroke\n";
}

string header() {
	return "%!\n\n";
}

string showpage() {
	return "showpage\n";
}