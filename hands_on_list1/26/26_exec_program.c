#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        execl("./hello"," ", argv[1], NULL);

        perror("execl");
        exit(1);
    } else {
        wait(0);
    }

    return 0;
}

