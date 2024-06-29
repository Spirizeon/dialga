#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>
#define MAX_BUF_SIZE 1024


//function that returns the hash of a file 
void hash_file(const char *repo_name,const char *file_name){
		char sha256_digest[SHA256_DIGEST_LENGTH];
		int bufsize = MAX_BUF_SIZE;
		int position = 0;
		char *buffer = malloc(sizeof(char) * bufsize);
		FILE *fp;
		char ch;
		char filename[MAX_BUF_SIZE];
		strcpy(filename,repo_name);
		strcat(filename,"/");
		strcat(filename,file_name);
		fp = fopen(filename,"r");
		if(fp == NULL){
			printf("dialga: read error: file is empty or corrupted");
			exit(EXIT_FAILURE);
		}
		
		do{
			if(position>=bufsize){
				bufsize += MAX_BUF_SIZE;
				buffer = realloc(buffer,bufsize);
			}
			ch = fgetc(fp);
			buffer[position] = ch;
			position++;
		} while(ch != EOF); 
		
			SHA256(buffer,strlen(buffer),sha256_digest);



	fclose(fp);

	//time to create a blob
	FILE *blob;
	char blob_name[30];
	position = 0;
	while(position < 3){
		blob_name[position] = sha256_digest[position];
		position++;
	}
	printf("%s",blob_name);
	char blobname[MAX_BUF_SIZE];
	strcpy(blobname,"./");
	strcpy(blobname,repo_name);
	strcat(blobname,"/");
	char blob_path[] = ".dlgx/objects/";
	strcat(blobname,blob_path);
	strcat(blob_path,blob_name);
	char repoer[MAX_BUF_SIZE];
	strcpy(repoer,repo_name);
	strcat(repoer,"/"); //pakia/
	strcat(repoer,blob_path); //palkia/.dlgx/objects/??
	if(mkdir(repoer, 0755) == 0) {} 
	printf("blob created!");
	fclose(blob);

}
 


