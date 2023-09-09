/*
============================================================================
Name : 1c.c
Author : Vicky Panchal
Description : 1. Create the following types of a files using (i) shell command (ii) system call
  c. FIFO (mkfifo Library Function or mknod system call)

Date: 1st Sep, 2023.
============================================================================
*/

// shell command
// mkfifo "./fifo_example.txt"


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char* fifo_path = "./fifo_example.txt";
    mode_t mode = 0666; // Permissions for the FIFO

    int result = mkfifo(fifo_path, mode);
    if (result == -1) {
        perror("mkfifo");
        return 1;
    }

    return 0;
}

