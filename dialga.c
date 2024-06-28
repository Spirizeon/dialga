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
	char temp_name[MAX_BUF_SIZE];
	strcpy(temp_name,repo_name);
	strcat(temp_name,"/.dlgx");
	if(mkdir(temp_name,0755) == 0){
	}else{
		perror("mkdir");
		return;
	}
	char* dlgx_contents[] = {"objects","refs","refs/heads"};
	for(int i=0;i<3;i++){
		strcpy(temp_name,repo_name);

		strcat(temp_name,"/.dlgx/");
		strcat(temp_name,dlgx_contents[i]);

		if(mkdir(temp_name,0755) == 0){
		}else{
			perror("mkdir");
			return;
		}
	}
		printf("\n===================================\n");
		printf("dialga: your 💖 for git, debloated");
		printf("\n===================================\n");
		printf("repo %s initialised with (.dlgx)!\n\n",repo_name);
}

int main(){
	char repo_name[MAX_BUF_SIZE];
	printf("enter repo name: ");
	scanf("%s",repo_name);
	init(repo_name);
	return 0;
}
