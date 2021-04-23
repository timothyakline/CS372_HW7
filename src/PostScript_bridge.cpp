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

string header() { return "%!\n\n"; }

string newpath() { return "newpath\n"; }

string stroke() { return "stroke\n"; }

string gsave() { return "gsave\n"; }

string grestore() { return "grestore\n"; }

string center() { return moveto(CenterX, CenterY); }

string currentpoint() { return "currentpoint\n"; }

string closepath() { return "closepath\n"; }

string showpage() { return "showpage\n"; }

string makeString() { return ""; }
template <typename T> string makeString(const T &val) {
    return to_string(val) + " ";
}
template <typename T, typename... Ts>
string makeString(const T &val, const Ts &...vals) {
    string result;
    result += makeString(val);
    result += makeString(vals...);
    return result;
}

string point(const int &x, const int &y) { return makeString(x, y); }

string moveto(const int &x, const int &y) { return point(x, y) + "moveto\n"; }

string rmoveto(const int &x, const int &y) {
    return point(x, y) + "rmoveto\n ";
}

string lineto(const int &x, const int &y) { return point(x, y) + "lineto\n"; }

string rlineto(const int &x, const int &y) { return point(x, y) + "rlineto\n"; }

string arc(const double &r, const int &s, const int &f) {
    return makeString(r, s, f) + "arc\n";
}

// angle is clockwise
string rotate(const int &angle) { return to_string(angle) + " rotate\n"; }

string translate() { return "translate\n"; }

string translate(const int &x, const int &y) {
    return point(x, y) + "translate\n";
}

string scale(const double &fx, const double &fy) {
    return makeString(fx, fy) + "scale\n";
}

string setrgbcolor(const double &r, const double &g, const double &b) {
    return makeString(r, g, b) + "setrgbcolor\n";
}

string fill() { return "fill\n"; }
