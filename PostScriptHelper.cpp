// FNAM: PostScriptHelper.cpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//		 {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0

#include "PostScriptHelper.hpp"

string moveto( int x, int y) {
	return to_string(x) + " " + to_string(y) + " moveto\n";
}

string rmoveto(int x, int y) {
	return to_string(x) + " " + to_string(y) + " rmoveto\n";
}

string lineto(int x, int y) {
	return to_string(x) + " " + to_string(y) + " lineto\n";
}

string rlineto(int x, int y) {
	return to_string(x) + " " + to_string(y) + " rlineto\n";
}

string arc(int x, int y, int r, int s, int f){
	return to_string(x) + " " + to_string(y) + " " + to_string(r) + " " + to_string(s) + " " + to_string(f) + " arc\n";
}
//angle is clockwise
string rotate(int angle) {
	return to_string(angle) + " rotate\n";
}

string newpath() {
	return "newpath\n";
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

string gsave() {
	return "gsave\n";
}

string grestore() {
	return "grestore\n";
}

string center() {;
	return moveto(CenterX, CenterY);
}