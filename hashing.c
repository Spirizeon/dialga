#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>
#define MAX_BUF_SIZE 1024

void *hash_file(const char *filename){
		char sha256_digest[SHA256_DIGEST_LENGTH];
		int bufsize = MAX_BUF_SIZE;
		int position = 0;
		char *buffer = malloc(sizeof(char) * bufsize);
		FILE *fp;
		char ch;
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

	for(int i = 0;i<SHA256_DIGEST_LENGTH;i++){
		printf("%02x",sha256_digest[i]);
	}
}
 


