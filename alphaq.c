#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>
int main(int argc,char** argv){
	system("clear");
	char indata[100];
	char* sa[10];
	char current_path[300];
	while(1){
		getcwd(current_path, sizeof(current_path));
		char* home=getenv("HOME");
		if(strncmp(current_path,home,strlen(home))==0){
			printf("~%s alpha>  ",current_path+strlen(home));
		}else{
			printf("%s alpha> ", current_path);
		}
		scanf(" %[^\n]",indata);
		getchar();
		if(strcmp(indata,"exit" )== 0) break;
		int i=0;
		char* token=strtok(indata," ");
		while(token!=NULL && i<10){
			sa[i++]=token;
			token=strtok(NULL," ");
		}
		sa[i]=NULL;
		if(strcmp(sa[0], "cd")==0){
			if(sa[1]==NULL){
				chdir(getenv("HOME"));
			}else if(strcmp(sa[1],"~")==0){
				chdir(getenv("HOME"));
			}else if(sa[1][0] == '~' && sa[1][1] == '/'){
				char home[]="/home/ubuntu";
				char path[200];
				char dir_name[50];
				int i,j;
				for (i=0; home[i] != '\0';i++){
					path[i]=home[i];
				}
				path[i]= '/';
				i++;
				for(j=0; sa[1][j+2] != '\0';j++){
					dir_name[j]=sa[1][j+2];
					path[i+j]=dir_name[j];
				}
				path[i+j]= '\0';
				chdir(path);
			}else if(chdir(sa[1])!=0) {
				printf("cd failed and directory not change");
			}
			continue;
		}
		pid_t pid = fork();
		if(pid==0){
			execvp(sa[0],sa);
			exit(1);
		}else{
			wait(NULL);
		}
	}
	return 0;
}
