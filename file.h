#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include "image.h"

#define FILE_NAME "image.ppm"

void save_ppm(char* file_name, Pixmap *pixmap);

#endif