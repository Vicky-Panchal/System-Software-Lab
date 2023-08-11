#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	const char *file_name = "file_desc.txt";
	int file_descriptor = creat(file_name, 0644);

	if(file_descriptor == -1) {
		perror("creat");
		return 1;
	}

	printf("File '%s' created with file descriptor: %d\n", file_name, file_descriptor);

	if(close(file_descriptor) == -1) {
		perror("close");
		return 1;
	}

	return 0;
}
