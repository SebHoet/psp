#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{	
	//Sebastian Hoet
	pid_t pid;
	
	pid = fork();
	
	if (pid ==0) { //proceso hijo
	printf("Sebastian\n");
	} else { // proceso padre
	pid = wait(NULL);
	printf("El pid del proceso hijo es = %d\n", pid);
	printf("El pid del proceso padre es = %d\n", getpid());
	}
	exit(0);
}
