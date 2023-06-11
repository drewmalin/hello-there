#include "foo/foo.h"

struct foo {
    int n;
};

Foo* new_Foo(int n) {
    Foo* f = (Foo*)malloc(sizeof(Foo));
    f->n = n;
    return f;
}

int Foo_get_n(const Foo* f) {
    return f->n;
}

void free_Foo(Foo* f) {
    free(f);
}
