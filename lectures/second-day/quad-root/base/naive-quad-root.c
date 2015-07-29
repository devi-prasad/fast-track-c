#include <math.h>
#include <stdio.h>


/*
 * Finding the roots of a quadratic equation.
 * Recall that there are two roots. We are kind of handicapped at this moment
 * because we haven't yet learned ways to return compound values. Therefore,
 * in this example, we will be returning only one sensible root :)
 * We will later introduce the following 'solutions':
 *    (1) a not-so-recommended solution using global variables.
 *    (2) an array argument to receive results from a function.
 *    (3) two pointer arguments corresponding to the two return values
 *    (4) a structure of two fields.  
 *
 * Don't we love C!!? :P
 *
 */

double naive_root_quadratic_equation(double a, double b, double c)
{
    if (a == 0) return 0;

    double root = (-b + sqrt(b*b - 4*a*c))/(2 * a);

    fprintf(stderr, "naive root: %f\n", root);

    return root;
}
