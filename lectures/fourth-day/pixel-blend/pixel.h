
struct _Pixel_ {
	unsigned int opacity : 8;
    unsigned int red     : 8;
    unsigned int green   : 8;
    unsigned int blue    : 8;
};

typedef struct _Pixel_ Pixel;
typedef unsigned char channel;

typedef enum BLEND_OP { COPY_SRC, BLEND_LINEAR } BLEND_OP;

Pixel pixel_new(channel o, channel r, channel g, channel b);
Pixel pixel_clone(const Pixel src);
Pixel pixel_blend(const Pixel src, Pixel dest);

#define SET_PIXEL_BLACK(pix)  { pix.red = pix.green = pix.blue = 0; }
#define SET_PIXEL_WHITE(pix)  { pix.red = pix.green = pix.blue = 255; }
#define SET_PIXEL_YELLOW(pix) { pix.red = pix.green = 255; pix.blue = 0; }

#define SET_PIXEL_OPAQUE(pix)        { pix.opacity = 255; }
#define SET_PIXEL_TRANSPARENT(pix)   { pix.opacity = 0;   }

#define TEST_BLACK_PIXEL(pix)       (pix.red == 0 && pix.green == 0 && pix.blue == 0)
#define TEST_WHITE_PIXEL(pix)       (pix.red == 255 && pix.green == 255 && pix.blue == 255)
#define TEST_YELLOW_PIXEL(pix)      (pix.red == 255 && pix.green == 255 && pix.blue == 0)

#define TEST_OPAQUE_PIXEL(pix)      (pix.opacity == 255)
#define TEST_TRASPARENT_PIXEL(pix)  (pix.opacity == 0)

