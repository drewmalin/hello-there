#include <iostream>

#include "geometry/point.h"

int main(void) {
    Point p = new_Point(1, 2);
    std::cout << p.toString();

    return 0;
}