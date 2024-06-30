#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>
#define MAX_BUF_SIZE 1024

//function that returns the hash of a file 
void hash_file(const char *repo_name,const char *file_name){
		
		char sha256_digest[SHA_DIGEST_LENGTH];
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
			printf("dialga: file doesn't exist\n");
			return;
		}
		
		do{
			if(position>=bufsize){
				bufsize += MAX_BUF_SIZE;
				buffer = realloc(buffer,bufsize);
			}
			if(!buffer){
				perror("dialga, could not allocate buffer");
				return;
			}
			ch = fgetc(fp);
			buffer[position] = ch;
			position++;
		} while(ch != EOF); 
		
			SHA1(buffer,strlen(buffer),sha256_digest);
	//time for hash -> hexadecimal
	int hex_index = 0;
	size_t hex_digest_len = strlen(sha256_digest) * 2 + 1;
	char *hex_digest = malloc(hex_digest_len);
	if(!hex_digest){
		perror("dialga, could not allocate hex_digest");
	}

	memset(hex_digest,0,hex_digest_len); //init with zeroes
	for(int i=0;i<strlen(sha256_digest);i++){
		sprintf(&hex_digest[hex_index*2],"%02x",sha256_digest[i]);
	}
	hex_digest[hex_digest_len-1] = '\0';
		
	printf("%s\n",hex_digest);
	fclose(fp);

	//time to create a blob
	char blob_name[30];
	position = 0;
	while(position < 2){
		blob_name[position] = hex_digest[position];
		position++;
	}
	printf("%s",blob_name);
	char repoer[MAX_BUF_SIZE];
	strcpy(repoer,repo_name); //palkia
	strcat(repoer,"/"); //pakia/
	char blob_path[] = ".dlgx/objects/";
	strcat(blob_path,blob_name); //.dlgx/objects/0X
	strcat(repoer,blob_path); //palkia/.dlgx/objects/0X??
	//printf("%s",repoer);
	if(mkdir(repoer, 0755) == 0){
	}
	else{
		perror("dialga: could not use repoer");
	}
	
	//time to create the blob file
	FILE *blob;
	strcat(repoer,"/");
	strcat(repoer,hex_digest);
	blob = fopen(repoer,"a");
	
	fclose(blob);
	
	free(buffer);
	free(hex_digest);

}
 


