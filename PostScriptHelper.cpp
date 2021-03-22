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
	return to_string(x) + " " + to_string(y) + "moveTo\n";
}

string RMoveTo(int x, int y) {
	return to_string(x) + " " + to_string(y) + "rmoveTo\n";
}
string lineTo(int x, int y) {
	return "S";
}
string RLineTo(int x, int y) {
	return "s";
}
string rotate(int angle) {
	return "s";
}
string stroke() {
	return "s";
}