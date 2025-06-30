#include <stdio.h>
#include <string.h>
#include "include/init.h"


int main(int argc, char* argv[]){
    if(argc <2){
        printf("Usage: git<command>\n");
        return 1;
    }

    if(strcmp(argv[1], "init") == 0){
        git_init();
    }

    printf("Unknown command: %s\n", argv[1]);
    return 1;
}