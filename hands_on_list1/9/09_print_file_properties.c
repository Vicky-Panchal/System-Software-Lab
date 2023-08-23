#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	struct stat fileStat;

	if(stat(argv[1], &fileStat) == -1) {
		perror("Error");
		return 2;
	}

	printf("Inode: %lu\n", fileStat.st_ino);
	printf("Number of Hard Links: %lu\n", fileStat.st_nlink);
	printf("UID: %d\n", fileStat.st_uid);
	printf("GID: %d\n", fileStat.st_gid);
	printf("Size: %ld bytes\n", fileStat.st_size);
	printf("Block Size: %ld bytes\n", fileStat.st_blksize);
	printf("Number of Blocks: %ld\n", fileStat.st_blocks);
	printf("Time of Last Access: %s", ctime(&fileStat.st_atime));
	printf("Time of Last Modifications: %s", ctime(&fileStat.st_mtime));
	printf("Time of Last Change: %s", ctime(&fileStat.st_ctime));
	return 0;
}
