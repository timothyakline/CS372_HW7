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

auto header() -> string;
auto newpath() -> string;
auto currentpoint() -> string;
auto stroke() -> string;
auto closepath() -> string;
auto showpage() -> string;

auto moveto(const int &x, const int &y) -> string;
auto rmoveto(const int &x, const int &y) -> string;
auto lineto(const int &x, const int &y) -> string;
auto rlineto(const int &x, const int &y) -> string;
auto gsave() -> string;
auto grestore() -> string;

auto point(const int &x, const int &y) -> string;
auto arc(const double &r, const int &s, const int &f) -> string;
auto center() -> string;
auto translate() -> string;
auto translate(const int &x, const int &y) -> string;
auto rotate(const int &angle) -> string;
auto scale(const double &fx, const double &fy) -> string;

auto setrgbcolor(const double &r, const double &g, const double &b) -> string;
auto fill() -> string;

#endif