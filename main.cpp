<<<<<<< HEAD
=======

>>>>>>> dc307ee42c913b0a3405d73b6d917d43407401fb
// FNAM: main.cpp
// DESC: C++ to PostScript functions
// AUTH: Jacob Jakiemiec
//       Cody Abad
//		 {ADD YOUR NAME IF YOU CHANGE ANYTHING HERE}
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 07 March 2021
// UPDT: 24 March 2021
// VERS: 1.0

#include "BasicShapes.hpp"
#include "CompoundShapes.hpp"
#include "PostScriptHelper.hpp"

using std::make_unique;
using std::unique_ptr;
<<<<<<< HEAD

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>

#include <string>
using std::string;

#include <map>
using std::map;

#include <vector>
using std::vector;

unique_ptr<Shape> makeShape();

unique_ptr<Polygon> makePolygon() {
	int sides(0);
	double sideLength(0.0);
	cout << "How many sides?\n" << endl;
	cin >> sides;
	cout << endl;
	cout << "Side length:" << endl;
	cin >> sideLength;
	return make_unique<Polygon>(Polygon(sides, sideLength));
}

unique_ptr<Circle> makeCircle() {
	double radius(0.0);
	cout << "Enter radius:";
	cin >> radius;
	cout << endl;
	return make_unique<Circle>(Circle(radius));
}

unique_ptr<RotatedShape> makeRotated() {
	auto temp = makeShape();
	int choice(0);
	cout << "what angle to rotate?" << endl;
	cout << "1. NONE (0)" << endl;
	cout << "2. QUARTER (90)" << endl;
	cout << "3. HALF (180)" << endl;
	cout << "4. THREE_QUARTERS (270)" << endl;
	cin >> choice;
	switch (choice) {
	case(1):
		return make_unique<RotatedShape>(RotatedShape(move(temp), NONE));
	case(2):
		return make_unique<RotatedShape>(RotatedShape(move(temp), QUARTER));
	case(3):
		return make_unique<RotatedShape>(RotatedShape(move(temp), HALF));
	case(4):
		return make_unique<RotatedShape>(RotatedShape(move(temp), THREE_QUARTERS));
	}
}

unique_ptr<HorizontalShape> makeHorizontal() {
	int shapeCount(0);
	cout << "How many shapes?" << endl;
	cin >> shapeCount;
	vector<unique_ptr<Shape>> shapes;
	for (int i = 0; i < 3; i++) {
		shapes.push_back(makeShape());
	} 
	
	return make_unique<HorizontalShape>(move(shapes[0]),move(shapes[1]),move(shapes[2]));
}

unique_ptr<LayeredShape> makeLayered() {
	auto temp = makeShape();
	int shapeCount(0);
	return make_unique<LayeredShape>(LayeredShape(move(temp)));
}

unique_ptr<ScaledShape> makeScaled() {
	auto temp = makeShape();
	int xscale(0);
	int yscale(0);
	cout << "Enter x scale factor:";
	cin >> xscale;
	cout << endl;
	cout << "Enter y scale factor:";
	cin >> yscale;
	return make_unique<ScaledShape>(ScaledShape(move(temp), xscale, yscale));
}

unique_ptr<VerticalShape> makeVertical() {
	auto temp = makeShape();
	int shapeCount(0);
	return make_unique<VerticalShape>(VerticalShape(move(temp)));
}

unique_ptr<Shape> makeShape() {
	
	int choice(0);

	cout << "What kind of shape?\n" << endl;
	cout << "1. Polygon" << endl;
	cout << "2. Circle" << endl;
	cout << "3. Rotated" << endl;
	cout << "4. Scaled" << endl;
	cout << "5. Layered" << endl;
	cout << "6. Horizontal" << endl;
	cout << "7. Vertical" << endl;

	cin >> choice;
	switch (choice) {
	case(1):
		return makePolygon();
	case(2):
		return makeCircle();
	case(3):
		return makeRotated();
	case(4):
		return makeScaled();
	case(5):
		return makeLayered();
	case(6):
		return makeHorizontal();
	case(7):
		return makeVertical();
	default:
		cout << "Invalid option" << endl;
	}
}

int main(){

	fstream fs;
	fs.open("cps.ps", std::ofstream::out | std::ofstream::trunc);
	if (!fs) {
		cout << "ERROR!!! file not found!";
		return 0;
	}

=======

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>

#include <string>
using std::string;

#include <map>
using std::map;

#include <vector>
using std::vector;

unique_ptr<Shape> makeShape();

unique_ptr<Polygon> makePolygon() {
	int sides(0);
	double sideLength(0.0);
	cout << "How many sides?\n" << endl;
	cin >> sides;
	cout << endl;
	cout << "Side length:" << endl;
	cin >> sideLength;
	return make_unique<Polygon>(Polygon(sides, sideLength));
}

unique_ptr<Circle> makeCircle() {
	double radius(0.0);
	cout << "Enter radius:";
	cin >> radius;
	cout << endl;
	return make_unique<Circle>(Circle(radius));
}

unique_ptr<RotatedShape> makeRotated() {
	auto temp = makeShape();
	int choice(0);
	cout << "what angle to rotate?" << endl;
	cout << "1. NONE (0)" << endl;
	cout << "2. QUARTER (90)" << endl;
	cout << "3. HALF (180)" << endl;
	cout << "4. THREE_QUARTERS (270)" << endl;
	cin >> choice;
	switch (choice) {
	case(1):
		return make_unique<RotatedShape>(RotatedShape(move(temp), NONE));
	case(2):
		return make_unique<RotatedShape>(RotatedShape(move(temp), QUARTER));
	case(3):
		return make_unique<RotatedShape>(RotatedShape(move(temp), HALF));
	case(4):
		return make_unique<RotatedShape>(RotatedShape(move(temp), THREE_QUARTERS));
	}
}

unique_ptr<HorizontalShape> makeHorizontal() {
	int shapeCount(0);
	cout << "How many shapes?" << endl;
	cin >> shapeCount;
	vector<unique_ptr<Shape>> shapes;
	for (int i = 0; i < 3; i++) {
		shapes.push_back(makeShape());
	} 
	
	return make_unique<HorizontalShape>(move(shapes[0]),move(shapes[1]),move(shapes[2]));
}

unique_ptr<LayeredShape> makeLayered() {
	auto temp = makeShape();
	int shapeCount(0);
	return make_unique<LayeredShape>(LayeredShape(move(temp)));
}

unique_ptr<ScaledShape> makeScaled() {
	auto temp = makeShape();
	int xscale(0);
	int yscale(0);
	cout << "Enter x scale factor:";
	cin >> xscale;
	cout << endl;
	cout << "Enter y scale factor:";
	cin >> yscale;
	return make_unique<ScaledShape>(ScaledShape(move(temp), xscale, yscale));
}

unique_ptr<VerticalShape> makeVertical() {
	auto temp = makeShape();
	int shapeCount(0);
	return make_unique<VerticalShape>(VerticalShape(move(temp)));
}

unique_ptr<Shape> makeShape() {
	
	int choice(0);

	cout << "What kind of shape?\n" << endl;
	cout << "1. Polygon" << endl;
	cout << "2. Circle" << endl;
	cout << "3. Rotated" << endl;
	cout << "4. Scaled" << endl;
	cout << "5. Layered" << endl;
	cout << "6. Horizontal" << endl;
	cout << "7. Vertical" << endl;

	cin >> choice;
	switch (choice) {
	case(1):
		return makePolygon();
	case(2):
		return makeCircle();
	case(3):
		return makeRotated();
	case(4):
		return makeScaled();
	case(5):
		return makeLayered();
	case(6):
		return makeHorizontal();
	case(7):
		return makeVertical();
	default:
		cout << "Invalid option" << endl;
	}
}

int main(){

	fstream fs;
	fs.open("cps.ps", std::ofstream::out | std::ofstream::trunc);
	if (!fs) {
		cout << "ERROR!!! file not found!";
		return 0;
	}

>>>>>>> dc307ee42c913b0a3405d73b6d917d43407401fb
	fs << moveto(300, 300);
	makeShape()->doPostScript(fs);
	fs << showpage();
	fs.close();
	cout << "heey";
	return 0;
}


