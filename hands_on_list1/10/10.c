/*
============================================================================
Name : 10.c
Author : Vicky Panchal
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. 

Date: 1st Sep, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char data1[] = "0123456789";
    char data2[] = "abcdefghij";

   
    if (write(fd, data1, 10) == -1) {
        perror("Error writing data");
        close(fd);
        return 2;
    }

    
    off_t new_offset = lseek(fd, 10, SEEK_CUR);

    if (new_offset == -1) {
        perror("Error seeking file");
        close(fd);
        return 3;
    }

  
    if (write(fd, data2, 10) == -1) {
        perror("Error writing data");
        close(fd);
        return 4;
    }

    close(fd);

    printf("lseek return value: %ld\n", new_offset);

    return 0;
}

