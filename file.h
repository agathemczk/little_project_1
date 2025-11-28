#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "image.h"

#define FILE_NAME "image.ppm"

void open_file(char* file_name);
void delete_file(char* file_name);

#endif