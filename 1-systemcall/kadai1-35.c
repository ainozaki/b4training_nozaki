#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int pipefds[2];
  pipe(pipefds);

  if ((pid = fork()) > 0) {
    close(pipefds[0]);
    char *msg = "hello from parent";
    write(pipefds[1], msg, strlen(msg) + 1);
    wait(NULL);
  } else {
    close(pipefds[1]);
    char buffer[100];
    read(pipefds[0], buffer, 100);
    printf("child: %s\n", buffer);
  }

  return 0;
}
