#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t child_pid, parent_pid;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child process
        parent_pid = getppid(); // Get the parent's PID
        printf("\nInside Child Process\n");
	printf("Child Process id: %d,\nParent's Process id:  %d\n", getpid(), parent_pid);

        sleep(2);

        if (kill(parent_pid, SIGKILL) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        printf("\nChild Process: Sent SIGKILL to the parent process.\n");
    } else { 
	printf("\nInside Parent Process\n");
        printf("Parent Process id: %d,\nChild's Process id:  %d\n", getpid(), child_pid);
	while(1);
    }

    return 0;
}

