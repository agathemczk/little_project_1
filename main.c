#include "file.h"
#include "image.h"

int main() {

    Pixmap pixmap;
    create_pixmap(&pixmap, IMAGE_WIDTH, IMAGE_HEIGHT);

    draw_mandelbrot(&pixmap, X_MIN, Y_MAX, X_MAX, Y_MIN);
    save_ppm(FILE_NAME, &pixmap);

    generate_zoom_series(&pixmap);

    delete_pixmap(&pixmap);

    printf("ok\n");
    return 0;
}
