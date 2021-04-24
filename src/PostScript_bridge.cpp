// FNAM: PostScript_bridge.cpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//       Cody Abad
//       Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 2.0

#include "../include/PostScript_bridge.hpp"

auto header() -> string { return "%!\n\n"; }

auto newpath() -> string { return "newpath\n"; }

auto stroke() -> string { return "stroke\n"; }

auto gsave() -> string { return "gsave\n"; }

auto grestore() -> string { return "grestore\n"; }

auto center() -> string { return moveto(CenterX, CenterY); }

auto currentpoint() -> string { return "currentpoint\n"; }

auto closepath() -> string { return "closepath\n"; }

auto showpage() -> string { return "showpage\n"; }

auto makeString() -> string { return ""; }

// const string point(const int &x, const int &y) { return makeString(x, y); }
//
// const string moveto(const int &x, const int &y) { return makeString(x, y) +
// "moveto\n"; }
//
// const string rmoveto(const int &x, const int &y) {
//    return makeString(x, y) + "rmoveto\n";
//}
//
// const string lineto(const int &x, const int &y) {
//    return makeString(x, y) + "lineto\n";
//}
//
// const string rlineto(const int &x, const int &y) {
//    return makeString(x, y) + "rlineto\n";
//}
//
// const string arc(const double &r, const int &s, const int &f) {
//    return makeString(r, s, f) + "arc\n";
//}
//
//// angle is clockwise
// const string rotate(const int &angle) { return makeString(angle) +
// "rotate\n"; }

auto translate() -> string { return "translate\n"; }

// const string translate(const int &x, const int &y) {
//    return makeString(x, y) + "translate\n";
//}
//
// const string scale(const double &fx, const double &fy) {
//    return makeString(fx, fy) + "scale\n";
//}
//
// const string setrgbcolor(const double &r, const double &g, const double &b) {
//    return makeString(r, g, b) + "setrgbcolor\n";
//}

auto fill() -> string { return "fill\n"; }
