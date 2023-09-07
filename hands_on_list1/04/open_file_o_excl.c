#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	const char *file_name = "example.txt";
	int file_descriptor = open(file_name, O_RDWR);

	if(file_descriptor == -1) {
		perror("open");
		return -1;
	} else {
		printf("File '%s' opened in read-write mode with file descriptor: %d\n", file_name, file_descriptor);
	}
	const char *file_excl = "example1.txt";
	int file_descriptor_excl = open(file_excl, O_CREAT | O_EXCL);

	if(file_descriptor_excl == -1) {
		perror("open with )_EXCL");
		printf("O_EXCL flag failed as expected. \n");
	} else {
		printf("O_EXCL flag opened the file with file descriptor: %d\n", file_descriptor_excl);
		close(file_descriptor_excl);
	}

	if(close(file_descriptor) == -1) {
		perror("close");
		return 1;
	}

	return 0;
}
