/*
============================================================================
Name : 1a.c
Author : Vicky Panchal
Description : 1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)

Date: 1st Sep, 2023.
============================================================================
*/

// shell command 
// ln -s "./example.txt" "./soft_link_call2"
#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* symlink_path = "./soft_link_system_call2";

    int result = symlink(source_path, symlink_path);
    if (result == -1) {
        perror("symlink");
        return 1;
    }

    return 0;
}
