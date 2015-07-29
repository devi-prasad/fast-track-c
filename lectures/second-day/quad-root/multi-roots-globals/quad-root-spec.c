#include <math.h>
#include <stdio.h>
#include <assert.h>

/*
 * Alright, we have rehashed the original solution to compute two roots.
 * However, we now have a situation: two global variables!
 * You should be careful with global variables:
 *    code should initialize them on each invocation of the function.
 *    they may get cobbled up in weird ways!
 *
 * TODO: how can a function indicate that it hasn't computed the actual
 *       roots when the arguments have unsuitable values?
 * 
 */

double g_first_root, g_second_root;

void root_quadratic_equation(double a, double b, double c)
{
    double q;
    int sign = b >= 0 ? 1 : -1;

    if (a == 0 && c == 0) {
        g_first_root = g_second_root = 0;
        return;
    }

    q = -(b + sign * sqrt(b*b - 4*a*c))/2;

    g_first_root = (a != 0) ? q/a : 0;
    g_second_root = c/q;

    fprintf(stderr, "first_root: %f, second_root: %f\n", g_first_root, g_second_root);
}

void naive_root_quadratic_equation(double a, double b, double c)
{
    if (a == 0) {
        g_first_root = g_second_root = 0;
        return;
    }

    double part = sqrt(b*b - 4*a*c);
    g_first_root = (-b - part)/(2 * a);
    g_second_root = (-b + part)/(2 * a);

    fprintf(stderr, "first_root: %f, second_root: %f\n", g_first_root, g_second_root);
}


int main()
{
    root_quadratic_equation(0, 0, 0);
    assert(g_first_root == 0 && g_second_root == 0);
    
    root_quadratic_equation(2, 4, 0);          /* root = -2.0 */
    assert( (2 * g_first_root * g_first_root + 4 * g_first_root + 0) == 0);
    assert( (2 * g_second_root * g_second_root + 4 * g_second_root + 0) == 0);

    root_quadratic_equation(2, 2, -4);         /* root = -2.0 */
    assert( (2 * g_first_root * g_first_root + 2 * g_first_root - 4) == 0);
    assert( (2 * g_second_root * g_second_root + 2 * g_second_root - 4) == 0);

    root_quadratic_equation(0.25, .5, 0.25);   /* root = -1.0 */
    assert( (0.25 * g_second_root * g_second_root + 0.5 * g_second_root + 0.25) == 0);

    root_quadratic_equation(0, 3.37, 4.2337);  /* root = -1.256291 */
    assert(g_first_root == 0);
    assert( (3.37 * g_second_root + 4.2337) == 0);

    root_quadratic_equation(0.0003572, 3.37, 0.0003561);  /* root = -1.256291 */
    assert( (0.0003572 * g_first_root * g_first_root + 3.37 * g_first_root + 0.0003561) < 0.00001);
    assert( (0.0003572 * g_second_root * g_second_root + 3.37 * g_second_root + 0.0003561) < 0.00001);

/*************************************************************************/
 
    naive_root_quadratic_equation(2, 4, 0);   /* root = 0.0 */
    assert( (2 * g_first_root * g_first_root + 4 * g_first_root + 0) == 0); 
    assert( (2 * g_second_root * g_second_root + 4 * g_second_root + 0) == 0); 

    naive_root_quadratic_equation(2, 2, -4);  /* root == 1 */
    assert( (2 * g_first_root * g_first_root + 2 * g_first_root - 4) == 0);
    assert( (2 * g_second_root * g_second_root + 2 * g_second_root - 4) == 0);

    naive_root_quadratic_equation(0.25, .5, 0.25); /* root = -1.0 */
    assert( (0.25 * g_first_root * g_first_root + 0.5 * g_first_root + 0.25) == 0);
    assert( (0.25 * g_second_root * g_second_root + 0.5 * g_second_root + 0.25) == 0);

    naive_root_quadratic_equation(0, 3.37, 4.2337);
    assert(g_first_root == 0);
    assert(g_second_root == 0);

    naive_root_quadratic_equation(0.0003572, 3.37, 0.0003561);  /* root = -1.256291 */
    assert( (0.0003572 * g_first_root * g_first_root + 3.37 * g_first_root + 0.0003561) < 0.00001);
    assert( (0.0003572 * g_second_root * g_second_root + 3.37 * g_second_root + 0.0003561) < 0.00001);

    return 0;
}
