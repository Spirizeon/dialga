#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#define MAX_BUF_SIZE 1024
#define SHA256_DIGEST_LENGTH 32
char *hash_file(const char *filename){

	FILE *file = fopen(filename,"rb");
	if(!file){
		fprintf(stderr,"dialga: error opening file\n");
		return NULL;
	}

	SHA256_CTX sha256;
	SHA256_Init(&sha256);

	char buffer[MAX_BUF_SIZE];
	size_t bytesRead;

	// Read file in chunks and update SHA-256 hash
	while ((bytesRead = fread(buffer, 1, MAX_BUF_SIZE, file)) > 0) {
			SHA256_Update(&sha256, buffer, bytesRead);
	}

	// Finalize SHA-256 hash and retrieve the digest
	char hash[SHA256_DIGEST_LENGTH];
	SHA256_Final(hash, &sha256);
	printf("%s",hash);
	// Close the file
	fclose(file);

}

int main(){
			char file_name[MAX_BUF_SIZE] = "main.c";
	 
	hash_file(file_name);
	return 0;
}
