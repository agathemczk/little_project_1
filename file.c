#include "file.h"

void open_file (char* file_name) {
    FILE *file = fopen(file_name, "w+");

    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    } 

    else if (file != NULL) {
        //écriture dans le fichier
        Pixmap img;
        strcpy(img.signature, IMAGE_SIGNATURE);
        strcpy(img.width, IMAGE_WIDTH);
        strcpy(img.height, IMAGE_HEIGHT);
        strcpy(img.intensity, IMAGE_INTENSITY);
        
        //img.pix = ? ;

        printf("sign : %s\n", img.signature);
        printf("width : %s\n", img.width);
        printf("height : %s\n", img.height);
        printf("int : %s\n", img.intensity);
    
        
    }
    
    fclose(file);    
}

void delete_file (char* file_name) {
    if (remove(file_name) == 0) {
        printf("Success deleting the file %s\n", file_name);
    } else {
        printf("Error deleting the file %s...\n", file_name);
    }
}