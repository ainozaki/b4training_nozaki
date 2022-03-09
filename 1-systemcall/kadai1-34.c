#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int pipefds[2];
  char *msg = "Hello!";
  char buffer[100];

  printf("pipefds = {%d, %d}\n", pipefds[0], pipefds[1]);
  if (pipe(pipefds) < 0) {
    fprintf(stderr, "pipe() failed");
    exit(1);
  }
  write(pipefds[1], msg, strlen(msg) + 1);
  read(pipefds[0], buffer, 100);
  printf("pipe: %s\n", buffer);

  return 0;
}
