#include <assert.h>

#include "foo/foo.h"

int case0() {
    assert(1 == 2);
    return 0;
}

int main(void) {
    case0();
    Foo* f;
    f = new_Foo(1);

    assert(Foo_get_n(f) == 2);
    assert(1 == 1);
    free_Foo(f);

}

