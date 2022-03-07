#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
  int len;
  char c;

  if (argc < 2) {
    fprintf(stderr, "usage: %s fd", argv[0]);
    exit(1);
  }

  fd = atoi(argv[1]);
  if ((len = read(fd, &c, sizeof(c))) < 0) {
    fprintf(stderr, "read failure (fd: %d)", fd);
    exit(1);
  }
  printf("read %d byte (fd: %d)", len, fd);
  return 0;
}
