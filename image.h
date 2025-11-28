#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIGNATURE "P6\0"
#define IMAGE_WIDTH "10\0"
#define IMAGE_HEIGHT "10\0"
#define IMAGE_INTENSITY "255\0"

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
    Pixel *pix;
} Pixmap;

void create_pixmap(Pixmap *img, int width, int height);
void delete_pixmap(Pixmap *img);
void display_pixmap(Pixmap *img);
void input_pixmap(Pixmap *img);

void create_pixel(Pixel *pixel, unsigned char r, unsigned char g, unsigned char b);
void delete_pixel(Pixel *pixel);
void display_pixel(Pixel *pixel);
void input_pixel(Pixel *pixel);

#endif
