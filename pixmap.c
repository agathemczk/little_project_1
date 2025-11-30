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

void draw_circle(Pixmap *pixmap, int center_x, int center_y, int radius, unsigned char r, unsigned char g, unsigned char b) {
    int width = atoi(pixmap->width);
    int height = atoi(pixmap->height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - center_x;
            int dy = y - center_y;
            int distance_squared = dx * dx + dy * dy;
            
            if (distance_squared <= radius * radius) {
                set_pixel(pixmap, x, y, r, g, b);
            }
        }
    }
}