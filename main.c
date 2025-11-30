#include "file.h"
#include "image.h"

int main() {

    Pixmap pixmap;
    create_pixmap(&pixmap, IMAGE_WIDTH, IMAGE_HEIGHT, IMAGE_INTENSITY);

    save_ppm(FILE_NAME, &pixmap);
    delete_pixmap(&pixmap);

    printf("ok\n");
    return 0;
}
