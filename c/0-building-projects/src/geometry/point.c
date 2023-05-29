#include <stdio.h>
#include <stdlib.h>

#include "geometry/point.h"

struct point {
    int x;
    int y;
};

Point* new_Point(int x, int y) {
    Point* p = (struct point*)malloc(sizeof(struct point));
    if (p == NULL) {
        exit(1);
    }

    p->x = x;
    p->y = y;
    return p;
}

void Point_free(Point* p) {
    free(p);
    p = NULL;
}

int Point_getX(const Point* p) {
    if (p == NULL) {
        printf("Point_getX cannot be invoked on a null Point");
        return 0;
    }
    return p->x;
}

int Point_getY(const Point* p) {
    if (p == NULL) {
        printf("Point_getX cannot be invoked on a null Point");
        return 0;
    }
    return p->y;
}

int Point_toString(char** buffer, const Point* p) {
    int char_count = 0;
    char_count = asprintf(buffer, "Point{x:%d,y:%d}", Point_getX(p), Point_getY(p));
    return char_count;
}
