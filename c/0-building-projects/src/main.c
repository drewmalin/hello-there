#include <stdio.h>
#include <stdlib.h>

#include "geometry/point.h"

int main(void) {
    Point* p = new_Point(1, 2);
    
    char* buf;
    Point_toString(&buf, p);
    puts(buf);

    Point_free(p);

    return 0;
}
