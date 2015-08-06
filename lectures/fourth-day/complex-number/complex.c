#include "complexnum.h"
#include "complexnum.h"

Complex complex_new(double real, double imag)
{
    Complex r = {real, imag};

    return r;
}

Complex complex_add(const Complex x, const Complex y)
{
    Complex res;

    res.real = x.real + y.real;
    res.imag = x.imag + y.imag;
    
    return res;
}

/*
 * x = a + ib and y = c + id
 * x * y = (a*c - b*d) + i(a*d + b*c)
 *
 */
Complex complex_mul(const Complex x, const Complex y)
{
    Complex res = {
   	    x.real * y.real - x.imag * y.imag, 
   	    x.real * y.imag + x.imag * y.real     
   	};

   return res; 
}
