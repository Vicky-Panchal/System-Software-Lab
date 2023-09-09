/*
============================================================================
Name : 1b.c
Author : Vicky Panchal
Description : 1. Create the following types of a files using (i) shell command (ii) system call
 b. hard link (link system call)

Date: 1st Sep, 2023.
============================================================================
*/

// shell command
// ln "./example.txt" "./hard_link_system_call"

#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* hardlink_path = "./hard_link_system_call";

    int result = link(source_path, hardlink_path);
    if (result == -1) {
        perror("link");
        return 1;
    }

    return 0;
}

