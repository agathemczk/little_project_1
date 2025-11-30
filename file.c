#include "file.h"

void save_ppm (char* file_name, Pixmap *pixmap) {
    FILE *file = fopen(file_name, "w+");

    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    } 

    fprintf(file,"%s\n%s %s\n%s\n", 
        pixmap->signature, 
        pixmap->width, 
        pixmap->height, 
        pixmap->intensity);
        
    fwrite(pixmap->pixel, sizeof(Pixel), atoi(pixmap->width) * atoi(pixmap->height), file);
    fclose(file);  
   
}