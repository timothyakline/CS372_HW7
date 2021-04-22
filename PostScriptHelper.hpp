// FNAM: PostScripthelper.hpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//		 Riley Maranville
//       Cody Abad
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 22 March 2021
// VERS: 1.0

#ifndef POST_SCRIPT_HELPER
#define POST_SCRIPT_HELPER

#include <fstream>
#include <string>
using std::fstream;
using std::ofstream;
using std::string;
using std::to_string;

#define CenterX 306
#define CenterY 396

string moveto(int x, int y);
string rmoveto(int x, int y);
string lineto(int x, int y);
string rlineto(int x, int y);
string arc(int r, int s, int f);
string rotate(int angle);
string translate(int x, int y);
string scale(double fx, double fy);
string newpath();
string stroke();
string showpage();
string header();
string gsave();
string grestore();
string center();
string currentpoint();
string closepath();
string setrgbcolor(double r, double g, double b);
string fill();

#endif
