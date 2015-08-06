#ifndef _INCLUDED_COMPLEX_
#define _INCLUDED_COMPLEX_

struct _complex_ {
    double real;
    double imag;
};

typedef struct _complex_ Complex;

Complex complex_new(double real, double imag);
Complex complex_add(const Complex a, const Complex b);
Complex complex_mul(const Complex a, const Complex b);

#endif
