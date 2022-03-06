#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;

	if ((fd = open("sample2.txt", O_WRONLY)) < 0){
		perror("sample2.txt");
		exit(1);
	}

	write(fd, "C", 1);
	lseek(fd, 0, SEEK_SET);
	write(fd, "B", 1);

	close(fd);
	return 0;
}	
