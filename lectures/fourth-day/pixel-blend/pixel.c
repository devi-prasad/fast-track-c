
#include <assert.h>
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

Pixel pixel_blend(const Pixel src, Pixel dest)
{
    enum BLEND_OP op = COPY_SRC;

    switch (op) {
        case COPY_SRC: {
            dest = src;
        }
        break;
   
        default: assert(0);
    }

    return dest;
}
