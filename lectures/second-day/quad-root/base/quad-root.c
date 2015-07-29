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

double root_quadratic_equation(double a, double b, double c)
{
    double q;
    int sign = b >= 0 ? 1 : -1;

    if (a == 0 && c == 0) return 0;

    q = -(b + sign * sqrt(b*b - 4*a*c))/2;

    double root = (a != 0) ? q/a : c/q;
    //double root = (c != 0) ? c/q : q/a;

    fprintf(stderr, "%f\n", root);

    return root;
}
