// FNAM: main.cpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//       Cody Abad
//		 Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 23 April 2021
// VERS: 2.0

#include "include/BasicShapes.hpp"
#include "include/ComplexShapes.hpp"
#include "include/PostScript_bridge.hpp"
#include "include/makeShapes_helper.hpp"

#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::endl;

//#include <fstream>
//
//#include <string>
// using std::string;
//
//#include <map>
// using std::map;
//
//#include <vector>
// using std::vector;

auto main() -> int {

    /*
            fstream fs;
            fs.open("cps.ps", std::ofstream::out | std::ofstream::trunc);
            if (!fs) {
                    cout << "ERROR!!! file not found!";
                    return 0;
            }

            fs << moveto(300, 300);
            makeShape()->doPostScript(fs);
            fs << showpage();
            fs.close();
            */
    auto myCircle = makeCircle(5.7);
    auto myTriangle = makeCircle(8.9);
    auto mySquare = makeCircle(2.3);
    // std::cout << myCircle->getHeight() << std::endl;
    // auto myLS = makeLayeredShape(myCircle, mySquare, myTriangle);
    auto myLS2 = std::make_shared<LayeredShape>(std::make_shared<Circle>(38.7),
                                                myTriangle, mySquare);
    std::cout << myLS2->getHeight() << ", " << myLS2->getWidth();
    std::cout << std::endl;
    auto myVS = std::make_shared<VerticalShape>(std::make_shared<Circle>(38.7),
                                                myTriangle, mySquare);
    std::cout << myVS->getHeight() << ", " << myVS->getWidth();
    std::cout << std::endl;    
    auto myHS = std::make_shared<HorizontalShape>(
        std::make_shared<Circle>(38.7), myTriangle, mySquare);
    std::cout << myHS->getHeight() << ", " << myHS->getWidth();
    // std::cout << myLS->getHeight() << std::endl << myLS->getWidth();
    std::cout << std::endl;

    myHS->addShapes(mySquare);
    std::cout << myHS->getHeight() << ", " << myHS->getWidth();
    std::cout << std::endl;
    return 0;
}
