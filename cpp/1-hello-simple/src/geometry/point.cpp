#include <string>

#include "geometry/point.h"

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

std::string Point::toString() {
    return "Point{x=" + std::to_string(x) + ",y=" + std::to_string(y) + "}";
}

Point new_Point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
