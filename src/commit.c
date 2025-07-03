#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/commit.h"
#include "../include/utils.h"

void write_commit(char* tree_sha, char* message, char* commit_sha){
    char commit_data[2048];

    time_t now = time(NULL);
    char* author = "Meerthika <meer@example.com>"
    
}