#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/init.h"

int make_dir(char* path){
    if(mkdir(path, 0755) == -1){
        perror("mkdir error");
        return -1;
    }
    return 0;
}

int write_file(char* path, char* content){
    FILE *fp = fopen(path, "w");
    if(!fp){
        perror("file write error");
        return -1;
    }

    fprintf(fp, "%s", content);
    fclose(fp);
    return 0;
}