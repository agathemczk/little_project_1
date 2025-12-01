#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_SIGNATURE "P6\0"
#define IMAGE_WIDTH 900
#define IMAGE_HEIGHT 600
#define IMAGE_INTENSITY "255\0"

#define BLUE_RED 65
#define BLUE_GREEN 108
#define BLUE_BLUE 163

#define CIRCLE_RED 186
#define CIRCLE_GREEN 137
#define CIRCLE_BLUE 74
#define CIRCLE_RADIUS 100

#define BACKGROUND_RED 0
#define BACKGROUND_GREEN 0
#define BACKGROUND_BLUE 0

#define X_MIN -2.0 //x1
#define Y_MAX 1.0 //y1
#define X_MAX 1.0 //x2
#define Y_MIN -1.0 //y2
#define MAX_ITERATIONS 85

#define NUM_FRAMES 10
#define ZOOM_TARGET_X -0.99
#define ZOOM_TARGET_Y 0.3
#define BASE_FILE_NAME "im"
#define FILE_EXTENSION ".ppm"
#define FINAL_RANGE_X 0.005

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

typedef struct {
    double real;
    double imag;
} Complex;

void set_pixel(Pixmap *pixmap, int x, int y, unsigned char r, unsigned char g, unsigned char b);

void create_pixmap(Pixmap *pixmap, int width, int height);
void delete_pixmap(Pixmap *pixmap);

void draw_circle(Pixmap *pixmap, int center_x, int center_y, int radius, unsigned char r, unsigned char g, unsigned char b);
int convergence(double x, double y);
void draw_mandelbrot(Pixmap *pixmap, double x_min, double y_max, double x_max, double y_min);

double lerp(double a, double b, double t) ;
void generate_zoom_series(Pixmap *pixmap);

#endif
