#include <stdio.h>
#include <string.h>
#include "include/init.h"
#include "include/hash_object.h"
#include "include/tree.h"
#include "include/commit.h"

int main(int argc, char* argv[]){
    if(argc <2){
        printf("Usage: git<command>\n");
        return 1;
    }

    if(strcmp(argv[1], "init") == 0){
        git_init();
    }else if(strcmp(argv[1], "hash-object") == 0){
        hash_object("hello.txt");
    }else if(strcmp(argv[1], "write-tree") == 0){
        char sha1[41];
        write_tree(".", sha1);
        printf("tree: %s\n", sha1);
    }else if(strcmp(argv[1], "commit") == 0){
        if(argv <3){
            printf("Usage: git commit <message>\n");
            return 1;
        }

        char tree_hash[41];
        write_tree(".", tree_hash);
        char commit_hash[41];

        write_commit(tree_hash, argv[2], commit_hash);
        printf("commit: %s\n", commit_hash);
    }eles{
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    

    return 0;
}

// printf("Unknown command: %s\n", argv[1]);