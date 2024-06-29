#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "hashing.h"
#include <string.h>
#define MAX_BUF_SIZE 1024

int main(int argc,char *argv[]){
	//if argument is smaller than 2 
		if(argc < 2){
			printf("Dialga is under development, please make sure you use it properly");
			return 0;
		}
		if(strcmp(argv[1],"init")==0){
				init("."); // dialga init
		}
	/*
		hash_file(repo_name,"chicken.c"); //dialga add and commit 
		hash_file(repo_name,"fish.c");
		hash_file(repo_name,"beef.c");
	*/
		
		
    return 0;
}

	


