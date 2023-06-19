#include <iostream>

#include "geometry/point.h"

int main(void) {
    Point p1 = new_Point(1, 2);
    std::cout << p1.toString() << '\n';

    Point p2 = { .x = 3, .y = 4 };
    std::cout << p2.toString() << '\n';

    return 0;
}