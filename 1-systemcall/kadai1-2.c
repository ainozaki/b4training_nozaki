#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	// Set umask
	mode_t prev = umask(0022);

	// Create file 
	int err = open("kadai1-2.txt", O_CREAT | O_EXCL, 0755);
	if (err < 0){
		fprintf(stderr, "err: open()\n");
		return -1;
	}
}
