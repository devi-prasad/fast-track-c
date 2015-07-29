#include <assert.h>

unsigned int fib(unsigned int n);

int main()
{
    assert(fib(0) == 1);
    assert(fib(1) == 1);
    assert(fib(2) == 2);

    assert(fib(5) == fib(4) + fib(3));
    assert(fib(20) == fib(19) + fib(18));
    assert(fib(30) == fib(29) + fib(28));
    assert(fib(40) == fib(39) + fib(38));
    assert(fib(44) == fib(43) + fib(42));
	
    //printf("%u\n", fib(200));
	return 0;
}