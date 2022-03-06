#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  int sleeplen;
  pid_t pid;

  for (int i = 0; i < 4; i++) {
    if ((pid = fork()) > 0) {
      printf("[%d]: create process %d([%d])\n", getpid(), i, pid);
    } else {
      sleeplen = ((getpid() % 7 + 2) + getpid()) % 6 + 1;
      printf("[%d]: execute %d s.\n", getpid(), sleeplen);
      sleep(sleeplen);
      status = i;
      exit(status);
    }
  }
  for (int i = 0; i < 4; i++) {
    // wait for one of the child processes.
    wait(&status);
    if (WIFEXITED(status)) {
      printf("[%d]: child (%d) returns %d\n", getpid(), pid,
             WEXITSTATUS(status));
    } else {
      printf("[%d]: child (%d) terminates or suspended unexpectedly\n",
             getpid(), pid);
    }
  }
  return 0;
}
