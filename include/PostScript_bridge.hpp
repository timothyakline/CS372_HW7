// FNAM: PostScript_bridge.hpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0

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

auto moveto(int x, int y) -> string;
auto rmoveto(int x, int y) -> string;
auto lineto(int x, int y) -> string;
auto rlineto(int x, int y) -> string;
auto arc(int r, int s, int f) -> string;
auto rotate(int angle) -> string;
auto translate(int x, int y) -> string;
auto scale(double fx, double fy) -> string;
auto newpath() -> string;
auto stroke() -> string;
auto showpage() -> string;
auto header() -> string;
auto gsave() -> string;
auto grestore() -> string;
auto center() -> string;
auto currentpoint() -> string;
auto closepath() -> string;
auto setrgbcolor(double r, double g, double b) -> string;
auto fill() -> string;

#endif
