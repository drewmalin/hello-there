#ifndef POINT_H
#define POINT_H

#include <string>

/*
 * A Point is a pairing of two ints.
 */
struct Point {
    int x;
    int y;

    int getX();
    int getY();
    std::string toString();
};

/**
 * Returns a pointer to a new Point, constructed as a pairing
 * between the "from" and "to" int arguments.
 */
extern Point new_Point(int x, int y);

#endif