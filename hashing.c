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
		printf("%s",filename);
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


	// debugging purposes
	for(int i = 0;i<SHA256_DIGEST_LENGTH;i++){
		printf("%02x",sha256_digest[i]);
	}
	printf("\nEND\n");

	fclose(fp);

	//time to create a blob
	FILE *blob;
	char blob_name[3];
	position = 0;
	while(position <= 1){
		blob_name[position] = sha256_digest[position];
		position++;
	}
	char blobname[MAX_BUF_SIZE];
	strcpy(blobname,repo_name);
	strcat(blobname,"/");
	char blob_path[] = ".dlgx/objects/";
	strcat(blobname,blob_path);
	strcat(blob_path,blob_name);
	blob = fopen(blob_name,"a");
	printf("blob created!");
	fclose(blob);

}
 


