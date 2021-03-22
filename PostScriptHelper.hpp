// FNAM: PostScripthelper.hpp
// DESC: C++ to PostScript functions
// AUTH: Timothy Albert Kline
//       Jacob Jakiemiec
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: N/A
// VERS: 1.0

#ifndef POST_SCRIPT_HELPER
#define POST_SCRIPT_HELPER

#include <fstream>
#include <string>
using std::fstream;
using std::ofstream;
using std::to_string;
using std::string;

string moveTo(int x, int y);
string RMoveTo(int x, int y);
string lineTo(int x, int y);
string RLineTo(int x, int y);
string rotate(int angle);
string stroke();


#endif