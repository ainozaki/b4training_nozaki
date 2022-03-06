#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  char *command = "/usr/bin/ls";
  char *argv[] = {"/usr/bin/ls", "-l", NULL};
  if (execve(command, argv, NULL) == -1) {
    perror("execve");
  }
  return 0;
}
