#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	int pid = fork();

	if (pid > 0)
		printf("Child process id: %d\n", pid);

	else if (pid == 0)
	{
		sleep(30);
		printf("in child process\n");
	}

	return 0;
}

