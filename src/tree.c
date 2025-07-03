#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../include/tree.h"
#include "../include/utils.h"

void write_tree(char* dir_path, char* tree_sha_hash){
    DIR *dir = opendir(dir_path);
    if(!dir){
        perror("directory open error");
        return;
    }

    char tree_dir[8194] = {0};
    struct dirent *entry;

    while((entry = readdir(dir)) !=NULL){
        if(entry->d_type != DT_REG || strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
            continue;
        }

        

    }

}