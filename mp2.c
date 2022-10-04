#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{	
	pid_t pid;
	
	pid = fork();
	
	if (pid == 0){ //P1
		pid=fork();
		if (pid == 0){//P2
			printf("Este es el proceso P2 y su pid es =  %d\n", getpid());
			printf("el pid padre de P2 es = %d\n", getppid());

		} else {//P1
			pid = wait(NULL);
			printf("Este es el proceso P1 y su pid es =  %d\n", getpid());
			printf("el pid hijo de P1 es = %d\n", pid);
		}
	} else { //P3
		wait(NULL);
		
		printf("Este es el proceso P3 y su pid es =  %d\n", getpid());
		printf("el pid padre de P3 es = %d\n", getppid());

	}
}

