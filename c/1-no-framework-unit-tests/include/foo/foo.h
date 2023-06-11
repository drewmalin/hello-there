#include <stdlib.h>

typedef struct foo Foo;

extern Foo* new_Foo(int n);

extern int Foo_get_n(const Foo* f);

extern void free_Foo(Foo* f);
