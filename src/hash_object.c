#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/hash_object.h"
#include "../include/utils.h"

int hash_object(char* filename){
    char* content = NULL;
    long size = 0;
    
    if (read_file_content(filename, &content, &size) != 0) {
        return 1; 
    }

    char hash[41];
    write_object("blob", content, size, hash);
    
    printf("Hash:%s\n", hash);
    

    free(content);
    fclose(fp);

    return 0;
}
