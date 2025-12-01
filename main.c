#include "file.h"
#include "image.h"

int main() {

    Pixmap pixmap;
    create_pixmap(&pixmap, IMAGE_WIDTH, IMAGE_HEIGHT);

    draw_mandelbrot(&pixmap);

    save_ppm(FILE_NAME, &pixmap);
    delete_pixmap(&pixmap);

    printf("ok\n");
    return 0;
}
