#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	const char *file_name = "file_desc.txt";
	int file_descriptor = creat(file_name, 0644);
	int file_descriptor2 = creat(file_name, 0644);
	 close(file_descriptor2);
	int file_descriptor3 = creat(file_name, 0644);


	if(file_descriptor == -1) {
		perror("creat");
		return 1;
	}

	printf("File '%s' created with file descriptor: %d\n", file_name, file_descriptor);
	printf("File '%s' created with file descriptor: %d\n", file_name, file_descriptor2);
	printf("File '%s' created with file descriptor: %d\n", file_name, file_descriptor3);

	close(file_descriptor3);
	if(close(file_descriptor) == -1) {
		perror("close");
		return 1;
	}

	return 0;
}
