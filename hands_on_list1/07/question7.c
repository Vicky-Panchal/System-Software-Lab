#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char* argv[]) {

	if(argc != 3) {
		printf("Incorrect arguments");
		return 0;
	}
	int fd_read = open(argv[1], O_RDONLY);
	int fd_write = open(argv[2], O_WRONLY | O_CREAT, 0644);

	if(fd_read == -1 || fd_write == -1) {
		printf("Unable to read or open a file");
	}

	char buf;

	while(1) {

		int char_read = read(fd_read, &buf, 1);
		if(char_read == 0) {
			break;
		}
		int char_written = write(fd_write, &buf, 1);

	}
	
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);

	if(fd_read_close == -1 || fd_write_close == -1) {
                printf("Unable to close a file");
        }

	return 0;
}

