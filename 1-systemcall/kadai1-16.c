#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fdin, fdout;
  char *fnamein, *fnameout;
  int can_overwrite = 1;

  if (argc < 3) {
    fprintf(stderr, "useage: %s [-i] <input file> <output file>\n", argv[0]);
    exit(1);
  }

  if (argc == 3) {
    fnamein = argv[1];
    fnameout = argv[2];
  } else if (argc == 4) {
    can_overwrite = 0;
    fnamein = argv[2];
    fnameout = argv[3];
  } else {
    fprintf(stderr, "useage: %s [-i] <input file> <output file>\n", argv[0]);
    exit(1);
  }

  // Open to read
  if ((fdin = open(fnamein, O_RDONLY)) < 0) {
    perror(fnamein);
    exit(1);
  }

  // Open to write
  if (can_overwrite) {
    if ((fdout = open(fnameout, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0) {
      perror(fnameout);
      exit(1);
    }
  } else {
    if ((fdout = open(fnameout, O_WRONLY | O_CREAT | O_EXCL, 0644)) < 0) {
      perror(fnameout);
      exit(1);
    }
  }

  char c;
  int len;
  while ((len = read(fdin, &c, sizeof(c))) > 0) {
    if (write(fdout, &c, sizeof(c)) < 0) {
      perror(fnameout);
      exit(1);
    }
  }

  close(fdin);
  close(fdout);

  return 0;
}
