#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
  char *fname;
  int lines = 0;

  if (argc < 2) {
    fprintf(stderr, "useage: %s <input file>\n", argv[0]);
    exit(1);
  }
  fname = argv[1];

  // Open to read
  if ((fd = open(fname, O_RDONLY)) < 0) {
    perror(fname);
    exit(1);
  }

  // Read
  char c;
  int len;
  while ((len = read(fd, &c, sizeof(c))) > 0) {
    if (c == '\n') {
      lines++;
    }
  }

  printf("Lines of %s: %d\n", fname, lines);
  close(fd);

  return 0;
}
