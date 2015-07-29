#include <assert.h>

/* declare the prototypes of functions used here */
double root_quadratic_equation(double a, double b, double c);
double naive_root_quadratic_equation(double a, double b, double c);


int main()
{
	double root;

    assert(root_quadratic_equation(0, 0, 0) == 0);
    
    root = root_quadratic_equation(2, 4, 0);          /* root = -2.0 */
    assert( (2 * root * root + 4 * root + 0) == 0);

    root = root_quadratic_equation(2, 2, -4);         /* root = -2.0 */
    assert( (2 * root * root + 2 * root - 4) == 0);

    root = root_quadratic_equation(0.25, .5, 0.25);   /* root = -1.0 */
    assert( (0.25 * root * root + 0.5 * root + 0.25) == 0);

    root = root_quadratic_equation(0, 3.37, 4.2337);  /* root = -1.256291 */
    assert( (3.37 * root + 4.2337) == 0);

    root = root_quadratic_equation(0.0003572, 3.37, 0.0003561);  /* root = -1.256291 */
    assert( (0.0003572 * root * root + 3.37 * root + 0.0003561) < 0.00001);

/*************************************************************************/
 
    root = naive_root_quadratic_equation(2, 4, 0);   /* root = 0.0 */
    assert( (2 * root * root + 4 * root + 0) == 0); 

    root = naive_root_quadratic_equation(2, 2, -4);  /* root == 1 */
    assert( (2 * root * root + 2 * root - 4) == 0);

    root = naive_root_quadratic_equation(0.25, .5, 0.25); /* root = -1.0 */
    assert( (0.25 * root * root + 0.5 * root + 0.25) == 0);

    root = naive_root_quadratic_equation(0, 3.37, 4.2337); /* root = 0 */
    //assert( (3.37 * root + 4.2337) == 0);                /* FAILS!!! */

    return 0;
}
