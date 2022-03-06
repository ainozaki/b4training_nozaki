#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct line_info {
  int offset;
  struct line_info *prev;
  struct line_info *next;
};

int main(int argc, char *argv[]) {
  int fd;
  char *fname;
  int offset = 0;

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

  struct line_info *current;
  // top
  struct line_info *top = (struct line_info *)malloc(sizeof(struct line_info));
  top->offset = 0;
  top->prev = NULL;
  current = top;

  while ((len = read(fd, &c, sizeof(c))) > 0) {
    offset += len;
    if (c == '\n') {
      struct line_info *entry =
          (struct line_info *)malloc(sizeof(struct line_info));
      entry->offset = offset;
      entry->prev = current;
      current->next = entry;
      current = entry;
    }
  }

  // tail
  struct line_info *entry =
      (struct line_info *)malloc(sizeof(struct line_info));
  entry->offset = offset + 1;
  entry->prev = current;
  current->next = entry;
  current = entry;

  // Output
  while (1) {
    if (current->prev == NULL) {
      break;
    }
    lseek(fd, current->prev->offset, SEEK_SET);
    for (int i = 0; i < current->offset - current->prev->offset; i++) {
      read(fd, &c, sizeof(c));
      putchar(c);
    }
    current = current->prev;
  }

  close(fd);

  return 0;
}
