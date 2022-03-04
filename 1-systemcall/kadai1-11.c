#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fd;
	char *fname = "kadai1-11.txt";
	if (open(fname, O_WRONLY | O_CREAT, 0644) < 0){
		perror(fname);
		exit(1);
	}
	char *string = " z";
	if (write(fd, string, 2) < 0){
		perror(fname);
		exit(1);
	}
	close(fd);
	return 0;
}
