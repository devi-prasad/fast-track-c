
#include <assert.h>


int main()
{
	unsigned int a;

    assert(absolute(0) == 0);
    a = -1;
    assert(a == 0xFFFFFFFF);
    assert(absolute(-1) == 1);
    assert(absolute(1) == 1);

    /* nested expression */
    assert(absolute(absolute(-100)) == 100);
    
    return 0;
}