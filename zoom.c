#include "image.h"
#include "file.h"

double lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

void generate_zoom_series(Pixmap *pixmap) {
    int width = atoi(pixmap->width);
    int height = atoi(pixmap->height);
    
    const double initial_xmin = X_MIN;
    const double initial_xmax = X_MAX;
    const double initial_ymin = Y_MIN;
    const double initial_ymax = Y_MAX;

    const double final_range_x = FINAL_RANGE_X;
    const double final_range_y = FINAL_RANGE_X * (double)height / width; 
    
    // Centre du zoom (-0.99, 0.3)
    const double center_x = ZOOM_TARGET_X;
    const double center_y = ZOOM_TARGET_Y;

    const double final_xmin = center_x - final_range_x / 2.0;
    const double final_xmax = center_x + final_range_x / 2.0;
    const double final_ymin = center_y - final_range_y / 2.0; 
    const double final_ymax = center_y + final_range_y / 2.0;

    printf("GGeneration of the Mandelbrot zoom series (%d frames) towards Z=(%.2f, %.2f)...\n", 
           NUM_FRAMES, ZOOM_TARGET_X, ZOOM_TARGET_Y);
    
    for (int k = 0; k < NUM_FRAMES; k++) {

        double t = (double)k / (NUM_FRAMES - 1); 

        double x_min_k = lerp(initial_xmin, final_xmin, t);
        double x_max_k = lerp(initial_xmax, final_xmax, t);
        double y_min_k = lerp(initial_ymin, final_ymin, t);
        double y_max_k = lerp(initial_ymax, final_ymax, t);

        char file_name[32];
        sprintf(file_name, "%s%d%s", BASE_FILE_NAME, k, FILE_EXTENSION);

        printf("  > Generation of the frame %d/%d : %s\n", k + 1, NUM_FRAMES, file_name);

        draw_mandelbrot(pixmap, x_min_k, y_max_k, x_max_k, y_min_k);

        save_ppm(file_name, pixmap);
    }
}

//ffmpeg -i im%d.ppm video.mpg