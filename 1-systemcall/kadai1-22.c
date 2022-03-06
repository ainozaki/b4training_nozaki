#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s num", argv[0]);
    exit(1);
  }
  return *argv[1] - '0';
}
