#include "image.h"

int convergence(double x, double y) {
    Complex u = {0.0, 0.0};
    Complex c = {x, y}; 

    u.real = c.real;
    u.imag = c.imag;

    int n = 0;
    double module_squared;

    module_squared = u.real * u.real + u.imag * u.imag;

    while (module_squared <= 4.0 && n < MAX_ITERATIONS) {
        double temp_real = u.real * u.real - u.imag * u.imag + c.real;
        double temp_imag = 2.0 * u.real * u.imag + c.imag;

        u.real = temp_real;
        u.imag = temp_imag;

        module_squared = u.real * u.real + u.imag * u.imag;
        n++;
    }

    if(n == MAX_ITERATIONS) {
        return 0;
    } else {
        return n;
    }
}

void draw_mandelbrot(Pixmap *pixmap, double x_min, double y_max, double x_max, double y_min) {
    int width = atoi(pixmap->width);
    int height = atoi(pixmap->height);

    double x_scale = (x_max - x_min) / width;
    double y_scale = (y_max - y_min) / height;
    
    for (int y_pixel = 0; y_pixel < height; y_pixel++) {
        for (int x_pixel = 0; x_pixel < width; x_pixel++) {

            double x0 = x_min + x_pixel * x_scale;
            double y0 = y_max - y_pixel * y_scale;

            int c = convergence(x0, y0);
            unsigned char r,g,b;

            if (c == 0) {
                set_pixel(pixmap, x_pixel, y_pixel, BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE);
            } else {
                int g_value = 3 * c;
                r = 0;
                g = (unsigned char)(g_value > 255 ? 255 : g_value);
                b = 255;                
                set_pixel(pixmap, x_pixel, y_pixel, r, g, b);
            }
        }
    }
    
}