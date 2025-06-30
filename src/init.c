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

int git(){
    
    char *dirs[] = {
        ".git",
        ".git/objects",
        ".git/refs",
        ".git/refs/heads"
    };

    for(int i=0; i< sizeof(dirs)/sizeof(dirs[0]); i++){
        if(make_dir(dirs[i]) == -1){
            return -1;
        }
    }

    if(write_file(".git/HEAD", "Branch: Master\n") == -1){
        return -1;
    }

    printf("Initialized empty Mini-Git repository in .git/\n");
    return 0;

}