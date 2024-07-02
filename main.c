#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "hashing.h"
#include <string.h>
#define MAX_BUF_SIZE 1024
#define VERSION_NUM "0.0.1"



int main(int argc,char *argv[]){
	//if argument is smaller than 2 
		if(argc < 2){
			printf("Dialga is under development, please make sure you use it properly");
			return 0;
		}


	
		if(strcmp(argv[1],"init") == 0){
			init(".");
		}

		else if(strcmp(argv[1],"commit") == 0){
				char ch;
				int position = 0;
				//read index file
				FILE *indexread;
				char line[MAX_BUF_SIZE];
				indexread = fopen(".dlgx/index","r");

				while(fgets(line,sizeof(line),indexread)){
				//strip newline
							while(line[position] != '\n'){
								position++;
							}
							line[position] = '\0';
							hash_file(".",line);
				}
				system("rm .dlgx/index");
				fclose(indexread);
			}

		else if(strcmp(argv[1],"status") == 0){
			FILE *statuschecker;
			char line[MAX_BUF_SIZE];
			statuschecker = fopen(".dlgx/index","r");
			if(!statuschecker){
				printf("could not read status");
			}
			while(fgets(line,sizeof(line),statuschecker)){
				printf("<added> %s",line);
			}
			

		}

		else if(strcmp(argv[1],"add") == 0){
				FILE *check;
				check = fopen(argv[2],"r");
				if(check!=NULL){
						//add file name to git index		
						FILE *indexwriter;
						indexwriter = fopen(".dlgx/index","a");
						if(!indexwriter){
							printf("could not open file for writing");
							return 0;
						}
						fprintf(indexwriter,"%s\n",argv[2]);
						fclose(indexwriter);
				}
				else{
					printf("value file arg needed");
				}
				fclose(check);
				
			}
	



		else if(strcmp(argv[1],"--version") == 0){
				printf("dialga version %s\n",VERSION_NUM);
		}




		else{
			printf("no such command");
		}
	/*
		hash_file(repo_name,"chicken.c"); //dialga add and commit 
		hash_file(repo_name,"fish.c");
		hash_file(repo_name,"beef.c");
	*/
		
		
    return 0;
}

	


