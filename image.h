#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIGNATURE "P6\0"
#define IMAGE_WIDTH "10\0"
#define IMAGE_HEIGHT "10\0"
#define IMAGE_INTENSITY "255\0"

#define BLUE_RED 65
#define BLUE_GREEN 108
#define BLUE_BLUE 163

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    char signature[3];
    // entre les 2 > \n
    char width[5];
    // entre les 2 > 1 octet de séparation ' '
    char height[5];
    // entre les 2 > \n
    char intensity[5];
    // entre les 2 > \n
    Pixel *pixel;
} Pixmap;

void set_pixel(Pixmap *pixmap, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void create_pixmap(Pixmap *pixmap, int width, int height);
void delete_pixmap(Pixmap *pixmap);

#endif
