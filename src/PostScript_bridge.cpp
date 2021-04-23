// FNAM: PostScript_bridge.cpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0

#include "../include/PostScript_bridge.hpp"

string moveto(int x, int y) {
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

string arc(int r, int s, int f) {
    return to_string(r) + " " + to_string(s) + " " + to_string(f) + " arc\n";
}

// angle is clockwise
string rotate(int angle) { return to_string(angle) + " rotate\n"; }

string translate(int x, int y) {
    return "translate " + to_string(x) + " " + to_string(y);
}

string scale(double fx, double fy) {
    return to_string(fx) + " " + to_string(fy) + " " + "scale\n";
}

string newpath() { return "newpath\n"; }

string stroke() { return "stroke\n"; }

string header() { return "%!\n\n"; }

string showpage() { return "showpage\n"; }

string gsave() { return "gsave\n"; }

string grestore() { return "grestore\n"; }

string center() { return moveto(CenterX, CenterY); }

string currentpoint() { return "currentpoint\n"; }

string closepath() { return "closepath\n"; }

string setrgbcolor(double r, double g, double b) {
    return to_string(r) + " " + to_string(g) + " " + to_string(b) +
           " setrgbcolor\n";
}
string fill() { return "fill\n"; }
