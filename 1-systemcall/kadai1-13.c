#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define FILESIZE 8*1024*24

int main(){
	struct timespec start, end;
	int sec, nsec;
	double d_sec;

	char a = 'a';

	/* 1-12 write */
	int fd;
	char *fname = "foo.txt";
	if ((fd = open(fname, O_WRONLY | O_CREAT, 0644)) < 0){
		perror(fname);
		exit(1);
	}

	/* start */
	clock_gettime(CLOCK_REALTIME, &start);
	for (int i = 0; i < 8 * 1024 * 1024; i++){
		write(fd, &a, sizeof(a));
	}
	/* end */
	clock_gettime(CLOCK_REALTIME, &end);
	sec = end.tv_sec - start.tv_sec;
	nsec = end.tv_nsec - start.tv_nsec;
	d_sec = (double)sec + (double)nsec / (1000 * 1000 * 1000);
	printf("write: %f\n", d_sec);
	close(fd);


	// 1-13 fputc
	FILE *fp;
	char *fname2 = "bar.txt";
	if ((fp = fopen(fname2, "w")) == NULL){
		perror(fname2);
		exit(1);
	}
	/* start */
	clock_gettime(CLOCK_REALTIME, &start);
	for (int i = 0; i < 8 * 1024 * 24; i++){
		fputc(a, fp);
	}
	/* end */
	clock_gettime(CLOCK_REALTIME, &end);
	sec = end.tv_sec - start.tv_sec;
	nsec = end.tv_nsec - start.tv_nsec;
	d_sec = (double)sec + (double)nsec / (1000 * 1000 * 1000);
	printf("fputc: %f\n", d_sec);

	return 0;
}
