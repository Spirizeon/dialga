#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define MAX_BUF_SIZE 1024

void init(char* repo_name){
	if(mkdir(repo_name,0755) == 0){
	}
	else{
		perror("mkdir");
		return;
	}
	char temp_name = *repo_name;
	strcat(temp_name,"/.dlgx");
	if(mkdir(temp_name,0755) == 0){
	}else{
		perror("mkdir");
		return;
	}
	char* dlgx_contents[] = {"objects","refs","refs/heads"};
	for(int i=0;i<3;i++){
		temp_name = *repo_name;
		strcat(&temp_name,"/");
		strcat(&temp_name,dlgx_contents[i]);
		if(mkdir(temp_name,0755) == 0){
		}else{
			perror("mkdir");
			return;
		}
	}
		printf("dialga (.dlgx) repo initialised!\n");
}

int main(){
	char repo_name[MAX_BUF_SIZE];
	scanf("%s",repo_name);
	init(repo_name);
	return 0;
}
