#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

void init(char* repo_name) {
    if(mkdir(repo_name, 0755) == 0) {
    } 
    

    char temp_name[MAX_BUF_SIZE];
    strcpy(temp_name, repo_name);
    strcat(temp_name, "/.dlgx");

    if(mkdir(temp_name, 0755) == 0) {
    } 

    char* dlgx_contents[] = {"objects", "refs", "refs/heads"};
    strcat(temp_name, "/");
    char temp_temp_name[MAX_BUF_SIZE];
    strcpy(temp_temp_name,temp_name);
    strcat(temp_temp_name,"index");
    FILE *indexdb;
    indexdb = fopen(temp_temp_name,"a");
    fclose(indexdb);


    for(int i = 0; i < 3; i++) {
        strcpy(temp_name,"./.dlgx/");
        strcat(temp_name, dlgx_contents[i]);

        if(mkdir(temp_name, 0755) == 0) {
        }
    }

    printf("\n===================================\n");
    printf("dialga: your 💖 for git, debloated");
    printf("\n===================================\n");
    printf("repo %s initialised with (.dlgx)!\n\n", repo_name);
}

