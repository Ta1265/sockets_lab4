#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	char* clients[6] = {
		 "./client6",
		 "./client5", 
		 "./client4", 
		 "./client3", 
		 "./client2", 
		 "./client1"
		};

	for(int i=0; i<6; i++){
		pid_t pid = fork();
		if(pid == 0){
			char* args[]={clients[i],NULL};
			execvp(args[0],args);
			exit(127);
		}

	}
	return 0;
}