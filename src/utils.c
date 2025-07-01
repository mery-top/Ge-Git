#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/hash_object.h"
#include <openssl/sha.h>
#include "../include/utils.h"

char* sha_hash(char* blob, long size){
    unsigned char sha[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)blob, size, sha);
    char* hash = malloc(41);
    for(int i=0; i<SHA_DIGEST_LENGTH; i++){
        sprintf(&hash[i*2], "%02x", sha[i]);
    }
    hash[40] ='\0';
    printf("Hash: %s\n", hash);
    return hash;
}


int save_blob(char* hash, char* blob, long size){
    char dir[3];
    char file[39];

    strncpy(dir, hash, 2);
    dir[2] = '\0';
    strncpy(file, hash+2, 38);
    file[38] = '\0';

    char dir_path[64];
    sprintf(dir_path, ".gegit/objects/%s", dir);
    mkdir(dir_path, 0755);

    char fullpath[128];
    sprintf(fullpath, "%s/%s", dir_path, file);

    FILE *fp = fopen(fullpath, "wb");
    if(!fp){
        perror("file open error");
        return 1;
    }

    fwrite(blob, 1, size, fp);
    fclose(fp);
    printf("File wrote successfully at %s\n", fullpath);
    return 0;
}