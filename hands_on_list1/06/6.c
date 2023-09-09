/*
============================================================================
Name : 6.c
Author : Vicky Panchal
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Date: 1st Sep, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>

int main() {
    char buffer[1024];

    size_t bytesRead;
    while ((bytesRead = read(0, buffer, sizeof(buffer))) > 1) {
        
        write(1, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;

}
