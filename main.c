#include "file.h"
#include "image.h"

int main() {

    Pixmap pixmap;
    create_pixmap(&pixmap, IMAGE_WIDTH, IMAGE_HEIGHT);

    int center_x = IMAGE_WIDTH / 2;
    int center_y = IMAGE_HEIGHT / 2;
    draw_circle(&pixmap, center_x, center_y, CIRCLE_RADIUS, CIRCLE_RED, CIRCLE_GREEN, CIRCLE_BLUE);

    save_ppm(FILE_NAME, &pixmap);
    delete_pixmap(&pixmap);

    printf("ok\n");
    return 0;
}
