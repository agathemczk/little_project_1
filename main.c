#include "file.h"
#include "image.h"

int main() {

    Pixmap pixmap;
    create_pixmap(&pixmap, 10, 10);

    save_ppm(FILE_NAME, &pixmap);
    delete_pixmap(&pixmap);

    printf("ok\n");
    return 0;
}
