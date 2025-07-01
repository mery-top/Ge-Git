#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hash_object.h"
#include <openssl/sha.h>

char* sha_hash(char* blob, long size){
    unsigned char sha[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)blob, size, sha);
    char* hash = malloc(41);
    for(int i=0; i<SHA_DIGEST_LENGTH; i++){
        snprintf(&hash[i*2], "%02x", sha[i]);
    }
    hash[40] ='\0';
    printf("Hash: %s\n", hash);
    return hash;
}

int save_blob(char* hash, char* blob, long size){
    
}

int hash_object(char* filename){
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

    char header[64];
    sprintf(header, "blob %ld", size);
    long header_length = strlen(header);
    long blob_size = header_length+1+size;
    char* blob = malloc(blob_size);

    memcpy(blob, header, header_length);
    blob[strlen(header)] = "\0";
    memcpy(blob+header_length+1, content, size);

    printf("Blob created successfully\n");
    char* hash = sha_hash(blob, blob_size);
    free(content);
    free(blob);
    fclose(fp);

    return 0;
}
