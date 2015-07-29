
/*
 *  Compute the square of an integer. Illustrates the use of "assert"
 *  statement as a powerful means of specifying expected behaviors. 
 */
#include <assert.h>

int main()
{
    int a;

    a = 10;
    assert(a * a == 100);  /* check your expectations! */
    
    return 0;
}
