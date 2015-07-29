
/*
 *  Compute the square of an integer. Illustrates the use of "assert"
 *  statement as a powerful means of specifying expected behaviors. 
 */
#include <assert.h>

/*
 * square is a function defined over the domain of integers.
 * Its codomain is the set of integers.
 * Its range includes natural numbers.
 * 
 * square: Integer -> Natural
 * Math Tip: notice the domain and range of this function.
 */
int square(int x)
{
    return (x * x);
}

int main()
{
    int square;
    
    assert(square(0) == 0);
    assert(square(-3) == 9);  /* check your expectations! */
    assert(square(16) == 256);

    assert(square(-335) == square(335));
    assert(square(-3) + square(3) == 18);
    assert(square(3) + square(4) == square(5));

    /* Nested expressions.
     * This is exactly like the normal high-school math notation: f(f(x).
     * Math Tip: convince yourself that these expressions are sensible.
     */
    assert(square(square(-3)) == 80);
    assert(square(square(-3)) == square(9));
    
    return 0;
}
