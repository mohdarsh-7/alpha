#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,char** argv){
	system("clear");
	char indata[100];
	char* sa[10];
        while(1){
                printf("~alpha>");
		scanf(" %[^\n]",indata);
                if(strcmp(indata,"exit" )== 0) break;
                int i=0;
                char* token=strtok(indata," ");
                while(token!=NULL && i<10){
                        sa[i++]=token;
                        token=strtok(NULL," ");
                }
                sa[i]=NULL;
                pid_t pid = fork();
                if (pid <0){
                        printf("fork failed\n");
                }
                else if (pid == 0){
                        printf("child successful\n");
                }
                else{
                        printf("parent is waiting\n");
                        wait(NULL);
                        printf("parent is completed after child\n");
                }
        }
        return 0;
}


