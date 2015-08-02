
#include <assert.h>

unsigned int absolute(int x);

int main()
{
    assert(absolute(0) == 0);
    assert(absolute(-1) == 1);
    assert(absolute(1) == 1);

    /* nested expression */
    assert(absolute(absolute(-100)) == 100);
    
    return 0;
}