#include "file.h"
#include "image.h"

int main() {
    char* filename = FILE_NAME;
    open_file(filename);

    printf("Hello, World!\n");
    return 0;
}
