#include <stdio.h>
#include <stdlib.h>
/*
test: 
	@./dialga init
	@./dialga add init.c
	@./dialga add main.c
	@./dialga status
	@./dialga commit 
*/

int main(){
	if(system("./dialga init") == 0){
		printf("✅ init works!");
	}
	else{
		printf("💀 init failed");
	}
	if(system("./dialga add init.c main.c") == 0){
		printf("✅ add works!");
	}
	else{
		printf("💀 add failed");
	}
	if(system("./dialga commit") == 0){
		printf("✅ commit works!");
	}
	else{
		printf("💀 commit failed");
	}
	if(system("./dialga --version") == 0){
		printf("✅ rest works!");
	}
	else{
		printf("💀 rest failed");
	}

	return 0;
}





