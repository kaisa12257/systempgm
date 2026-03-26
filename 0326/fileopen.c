#include<stdio.h>
int main(){
	FILE *fp;
	fp = fopen("./readme.md", "r");
	if (fp == NULL) {
		printf("File open error");
		fclode(fp);
	}
	

        return 0;
	
}
