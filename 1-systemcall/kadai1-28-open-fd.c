#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd;
  int len;
  char c;
  char *filename = "sample.txt";

  if ((fd = open(filename, O_RDONLY)) < 0) {
    perror(filename);
    exit(1);
  }

  char fd_char[10];
  sprintf(fd_char, "%d", fd);
  char *exec_argv[] = {
      "/home/aino/Projects/b4-training-nozaki/1-systemcall/kadai1-28-use-fd.o",
      fd_char, NULL};
  if ((execve(exec_argv[0], exec_argv, NULL)) < 0) {
    perror("execve");
    exit(1);
  }

  return 0;
}
