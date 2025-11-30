#include "image.h"

void create_pixmap(Pixmap *img, int width, int height) {
    strcpy(img->signature, IMAGE_SIGNATURE);
    sprintf(img->width, "%d", width);
    sprintf(img->height, "%d", height);
    strcpy(img->intensity, IMAGE_INTENSITY);

    img->pixel = malloc(sizeof(Pixel) * width * height);

    for (int i = 0; i < width * height; i++) {
        img->pixel[i].r = BLUE_RED;
        img->pixel[i].g = BLUE_GREEN;
        img->pixel[i].b = BLUE_BLUE;
    }
}

void delete_pixmap(Pixmap *img) {
    free(img->pixel);
}