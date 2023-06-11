#include <assert.h>

#include "foo/foo.h"

int main(void) {

    Foo* f;
    f = new_Foo(1);

    assert(Foo_get_n(f) == 2);

    free_Foo(f);
}
