#include <assert.h>
#include "complexnum.h"

int main()
{
    Complex x = complex_new(10, 20);
    Complex y = complex_new(20, 30);
 
    Complex cs = complex_add(x, y);
    assert(cs.real == 30 && cs.imag == 50);

    Complex cp = complex_mul(x, y);
    assert(cp.real == -400 && cp.imag == 700);

    return 0;
}