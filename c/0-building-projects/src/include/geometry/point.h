/*
 * A Point is a pairing of two ints.
 */
typedef struct point Point;

/**
 * Returns a pointer to a new Point, constructed as a pairing
 * between the "from" and "to" int arguments.
 */
extern Point* new_Point(int x, int y);

/**
 * Frees the allocated memory backing the provided Point.
 */
extern void Point_free(Point* p);

/**
 * Returns the value of the provided Point's "x" field.
 */
extern int Point_getX(const Point* p);

/**
 * Returns the value of the provided Point's "y" field.
 */
extern int Point_getY(const Point* p);

/**
 * Populates the provided buffer with a String representation
 * of this Point. Returns an int representing the length of the
 * data pointed to by the buffer.
 */
int Point_toString(char** buffer, const Point* p);
