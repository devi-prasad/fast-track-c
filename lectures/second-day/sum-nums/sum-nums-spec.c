#include <assert.h>

int sum(int, unsigned int);

int main()
{
    assert(sum(0, 0) == 0);
    assert(sum(10, 0) == 0);
    assert(sum(10, 0) == 0);
    assert(sum(0, 1) == 0);
    assert(sum(1, 1) == 1);

    assert(sum(1, 3) == sum(0, 4));
    assert(sum(2, 3) == sum(-1, 6));

    assert(sum(-10, 0) == 0);

    return 0;
}