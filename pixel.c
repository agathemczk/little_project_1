#include "image.h"

void set_pixel(Pixmap *pixmap, int x, int y, unsigned char R, unsigned char G, unsigned char B) {
    int w = atoi(pixmap->width);

    int index = y * w + x;
    pixmap->pixel[index].r = R;
    pixmap->pixel[index].g = G;
    pixmap->pixel[index].b = B;
}