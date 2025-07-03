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

    char tree_data[8194] = {0};
    struct dirent *entry;

    while((entry = readdir(dir)) !=NULL){
        if(entry->d_type != DT_REG || strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
            continue;
        }

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        char* content = NULL;
        long size = 0;
        
        if (read_file_content(full_path, &content, &size) != 0) {
            return 1; 
        }

        char blob_sha[41];
        write_object("blob", content, size, blob_sha);
        free(content);

        char line[512];
        snprintf(line, sizeof(line), "10644 %s %s\n", entry->d_name, blob_sha);
        strcat(tree_data, line);
    }

    closedir(dir);
    write_object("tree", tree_data, strlen(tree_data), tree_sha_hash);
}