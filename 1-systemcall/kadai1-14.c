#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd;

  if ((fd = open("sample.txt", O_RDWR)) < 0) {
    perror("sample.txt");
    exit(1);
  }

  lseek(fd, 4, SEEK_END);
  write(fd, "A", 1);

  close(fd);
  return 0;
}
