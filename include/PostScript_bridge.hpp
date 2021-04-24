// FNAM: PostScript_bridge.hpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
//		 Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 March 2021
// VERS: 2.0

#ifndef POST_SCRIPT_BRIDGE_HPP
#define POST_SCRIPT_BRIDGE_HPP

#include <fstream>
#include <string>
using std::fstream;
using std::ofstream;
using std::string;
using std::to_string;

#define CenterX 306
#define CenterY 396

auto makeString() -> string;

template <typename T> auto makeString(const T &val) -> string {
    return to_string(val) + " ";
}
template <typename T, typename... Ts>
auto makeString(const T &val, const Ts &...vals) -> string {
    return makeString(val) + makeString(vals...);
}

auto header() -> string;
auto newpath() -> string;
auto currentpoint() -> string;
auto stroke() -> string;
auto closepath() -> string;
auto showpage() -> string;

template <typename T, typename U>
auto moveto(const T &x, const U &y) -> string {
    return makeString(x, y) + "moveto\n";
}
template <typename T, typename U>
auto rmoveto(const T &x, const U &y) -> string {
    return makeString(x, y) + "rmoveto\n";
}
template <typename T, typename U>
auto lineto(const T &x, const U &y) -> string {
    return makeString(x, y) + "lineto\n";
}
template <typename T, typename U>
auto rlineto(const T &x, const U &y) -> string {
    return makeString(x, y) + "rlineto\n";
}
auto gsave() -> string;
auto grestore() -> string;

template <typename T, typename U> auto point(const T &x, const U &y) -> string {
    return makeString(x, y);
}
template <typename T, typename U>
auto arc(const double &r, const T &s, const U &f) -> string {
    return makeString(r, s, f) + "arc\n";
}
auto center() -> string;
auto translate() -> string;
template <typename T, typename U>
auto translate(const T &x, const U &y) -> string {
    return makeString(x, y) + "translate\n";
}
template <typename T> auto rotate(const T &angle) -> string {
    return makeString(angle) + "lineto\n";
}
template <typename T> auto scale(const T &fx, const T &fy) -> string {
    return makeString(fx, fy) + "scale\n";
}

template <typename T>
auto setrgbcolor(const T &r, const T &g, const T &b) -> string {
    return makeString(r, g, b) + "setrgbcolor\n";
}
auto fill() -> string;

#endif
