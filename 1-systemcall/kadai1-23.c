#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  pid_t pid;

  if ((pid = fork()) > 0) {
    printf("[%d]: parent = %d\n", getpid(), getppid());
    printf("\twaiting for the child...\n");
    wait(&status);
    if (WIFEXITED(status)) {
      printf("[%d]: child (%d) returns %d\n", getpid(), pid,
             WEXITSTATUS(status));
    } else {
      printf("[%d]: child (%d) terminates or suspended unexpectedly\n",
             getpid(), pid);
    }
  } else if (pid == 0) {
    printf("[%d]: parent = %d\n", getpid(), getppid());
    printf("\tsleeping for a while...\n");
    sleep(3);
    status = 33;
    printf("[%d]: child exits with %d\n", getpid(), status);
    exit(status);
  } else {
    perror("fork");
    exit(1);
  }

  return 0;
}
