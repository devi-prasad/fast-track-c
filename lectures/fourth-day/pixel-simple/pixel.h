
struct _pixel_ {
	unsigned int opacity : 8;
    unsigned int red     : 8;
    unsigned int green   : 8;
    unsigned int blue    : 8;
};

typedef struct _pixel_ Pixel;
typedef unsigned char channel;

Pixel pixel_new(channel o, channel r, channel g, channel b);
Pixel pixel_clone(const Pixel src);

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

