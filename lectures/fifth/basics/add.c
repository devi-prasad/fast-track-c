#include <assert.h>

int addto(int *x, int d)
{
    int r = *x;
    *x += d;

    return r;
}

int increment(int *x)
{
    return addto(x, 1);
}

int decrement(int *x)
{
    return addto(x, -1);
}

int main()
{
    int a, b, c;

    a = 10;
    b = 20;

    assert(addto(&a, b)  == 10 && a == 30);
    assert(addto(&a, -b) == 30 && a == 10);

    assert((increment(&b), decrement(&b), b == 20));
    assert(!(10, 20, 30, 0));

    return 0;
}