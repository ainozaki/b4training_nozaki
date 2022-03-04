#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILESIZE 8*1024*1024

int main(){
	int fd;
	char *fname = "kadai1-12.txt";
	if ((fd = open(fname, O_WRONLY | O_CREAT, 0644)) < 0){
		perror(fname);
		exit(1);
	}
	
	char a_array[FILESIZE];
	for (int i = 0; i < FILESIZE; i++){
		a_array[i] = 'a';
	}

	if (write(fd, a_array, FILESIZE) < 0){
		perror(fname);
		exit(1);
	}
	close(fd);
	return 0;
}
