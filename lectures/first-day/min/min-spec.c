#include <assert.h>

int main()
{
	assert(min(0, 0) == 0);                   /* min(X, X) == X */
	assert(min(-100, -100) == -100);          /* ditto */
	assert(min(100, 100) == 100);             /* ditto */

	assert(min(-1, 0) == -1);                 /* min(-X, 0) == -x */
	assert(min(0, -1) == -1);                 /* min(0, -X) == -x */

	assert(min(-1, 10) == min(10, -1));       /* min(X, Y)  == min(Y, X) */

    /* would you mind spelling out the other tests, please?
     * For instance, how would you find the min of three numbers?
     * min of four numbers?
     */
    
    return 0;
}
