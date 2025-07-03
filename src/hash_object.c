#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/hash_object.h"
#include "../include/utils.h"

char* hash_object(char* filename){
    FILE *fp = fopen(filename, "rb");
    if(!fp){
        perror("file open error");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *content = malloc(size);
    fread(content, 1, size, fp);

    
    printf("Blob created successfully\n");
    
    free(content);
    fclose(fp);

    return hash;
}
