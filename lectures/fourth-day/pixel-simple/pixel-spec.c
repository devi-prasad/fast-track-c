#include <assert.h>
#include "pixel.h"

int main()
{
    Pixel p;

    p = pixel_new(255, 0, 0, 0);
    assert(TEST_BLACK_PIXEL(p));
    assert(TEST_OPAQUE_PIXEL(p));
    
    SET_PIXEL_TRANSPARENT(p)
    assert(!TEST_OPAQUE_PIXEL(p));
    assert(TEST_TRASPARENT_PIXEL(p));
    
    SET_PIXEL_YELLOW(p);

    Pixel yp;

    yp = pixel_clone(p);
    assert(TEST_TRASPARENT_PIXEL(yp));
    assert(TEST_YELLOW_PIXEL(yp));

    return 0;
}