
#include "pixel.h"

Pixel pixel_new(channel o, channel r, channel g, channel b)
{
    Pixel p = {o, r, g, b};
    
    return p;
}


Pixel pixel_clone(Pixel src)
{
    return src;
}

