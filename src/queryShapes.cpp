//#include "../include/makeShapes_helper.h"
//
// shape_ptr queryShape();
//
// shape_ptr queryPolygon() {
//    int sides(0);
//    double sideLength(0.0);
//    cout << "How many sides?\n" << endl;
//    cin >> sides;
//    cout << endl;
//    cout << "Side length:" << endl;
//    cin >> sideLength;
//    return make_unique<Polygon>(Polygon(sides, sideLength));
//}
//
// shape_ptr queryCircle() {
//    double radius(0.0);
//    cout << "Enter radius:";
//    cin >> radius;
//    cout << endl;
//    return make_unique<Circle>(Circle(radius));
//}
//
// shape_ptr queryRotated() {
//    auto temp = queryShape();
//    int choice(0);
//    cout << "what angle to rotate?" << endl;
//    cout << "1. NONE (0)" << endl;
//    cout << "2. QUARTER (90)" << endl;
//    cout << "3. HALF (180)" << endl;
//    cout << "4. THREE_QUARTERS (270)" << endl;
//    cin >> choice;
//    switch (choice) {
//    case (1):
//        return make_unique<RotatedShape>(RotatedShape(move(temp), NONE));
//    case (2):
//        return make_unique<RotatedShape>(RotatedShape(move(temp), QUARTER));
//    case (3):
//        return make_unique<RotatedShape>(RotatedShape(move(temp), HALF));
//    case (4):
//        return make_unique<RotatedShape>(
//            RotatedShape(move(temp), THREE_QUARTERS));
//    }
//}
//
// shape_ptr queryHorizontal() {
//    int shapeCount(0);
//
//    vector<unique_ptr<Shape>> shapes;
//    for (int i = 0; i < 3; i++) {
//        shapes.push_back(makeShape());
//    }
//    return make_unique<HorizontalShape>(move(shapes[0]), move(shapes[1]),
//                                        move(shapes[2]));
//}
//
// shape_ptr queryLayered() {
//    int shapeCount(0);
//
//    vector<unique_ptr<Shape>> shapes;
//    for (int i = 0; i < 3; i++) {
//        shapes.push_back(makeShape());
//    }
//    return make_unique<LayeredShape>(move(shapes[0]), move(shapes[1]),
//                                     move(shapes[2]));
//}
//
// shape_ptr queryScaled() {
//    auto temp = makeShape();
//    int xscale(0);
//    int yscale(0);
//    cout << "Enter x scale factor:";
//    cin >> xscale;
//    cout << endl;
//    cout << "Enter y scale factor:";
//    cin >> yscale;
//    return make_unique<ScaledShape>(ScaledShape(move(temp), xscale, yscale));
//}
//
// shape_ptr queryVertical() {
//    int shapeCount(0);
//
//    vector<unique_ptr<Shape>> shapes;
//    for (int i = 0; i < 3; i++) {
//        shapes.push_back(makeShape());
//    }
//    return makeVerticalShape(move(shapes[0]), move(shapes[1]),
//    move(shapes[2]));
//}
//
// shape_ptr queryCat() {
//    double radius(0.0);
//    cout << "Enter radius";
//    cin >> radius;
//    return makeCat();
//}
//
// shape_ptr queryShape() {
//
//    int choice(0);
//
//    cout << "What kind of shape?\n" << endl;
//    cout << "1. Polygon" << endl;
//    cout << "2. Circle" << endl;
//    cout << "3. Rotated" << endl;
//    cout << "4. Scaled" << endl;
//    cout << "5. Layered" << endl;
//    cout << "6. Horizontal" << endl;
//    cout << "7. Vertical" << endl;
//    cout << "8. Cat" << endl;
//
//    cin >> choice;
//    switch (choice) {
//    case (1):
//        return queryPolygon();
//    case (2):
//        return queryCircle();
//    case (3):
//        return queryRotated();
//    case (4):
//        return queryScaled();
//    case (5):
//        return queryLayered();
//    case (6):
//        return queryHorizontal();
//    case (7):
//        return queryVertical();
//    case (8):
//        return queryCat();
//    default:
//        cout << "Invalid option" << endl;
//    }
//}
