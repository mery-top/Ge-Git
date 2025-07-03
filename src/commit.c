#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/commit.h"
#include "../include/utils.h"

void write_commit(char* tree_sha, char* message, char* commit_sha){
    char commit_data[2048];

    time_t now = time(NULL);
    char* author = "Meerthika <meer@mail.com>";
    snprintf(commit_data, sizeof(commit_data), "tree %s\n author %s %ld\n %s\n", 
    tree_sha, author, now, message);

    write_object("commit", commit_data, strlen(commit_data), commit_sha);

}