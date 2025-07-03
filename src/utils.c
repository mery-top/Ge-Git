#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/hash_object.h"
#include <openssl/sha.h>
#include "../include/utils.h"

void sha_hash(char* blob, long size, char* hash){
    unsigned char sha[SHA_DIGEST_LENGTH];
    SHA1((unsigned char*)blob, size, sha);
    for(int i=0; i<SHA_DIGEST_LENGTH; i++){
        sprintf(&hash[i*2], "%02x", sha[i]);
    }
    hash[40] ='\0';
    printf("Hash: %s\n", hash);
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


void write_object(char* type, char* content, long data_size, char* sha_hash){
    char header[64];
    sprintf(header, "%s %ld",type, size);
    long header_length = strlen(header);
    long blob_size = header_length+1+data_size;
    char* blob = malloc(blob_size);

    memcpy(blob, header, header_length);
    blob[header_length] = '\0';
    memcpy(blob+header_length+1, content, size);

    sha_hash(blob, blob_size,sha_hash);
    save_blob(sha_hash, blob, blob_size);
    free(blob);
}

void read_file_content(char* filename, char* content, long* size){
    FILE *fp = fopen(filename, "rb");
    if(!fp){
        perror("file open error");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    content = malloc(size);
    fread(content, 1, size, fp);
}



