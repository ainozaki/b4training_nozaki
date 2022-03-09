#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int sig) {
  char *msg = "Catch SIGCHLD\n";
  char *msg_waitpid = "waitpid\n";
  write(1, msg, strlen(msg));

  while (waitpid(-1, NULL, WNOHANG) > 0) {
    write(1, msg_waitpid, strlen(msg_waitpid));
  }
  /* To create zombi */
  sleep(1);
}

int main() {
  int pid;
  int status;
  struct sigaction act;
  char *msg = "Child exit\n";

  memset(&act, 0, sizeof(act));
  act.sa_handler = handler;
  sigaction(SIGCHLD, &act, NULL);

  for (int i = 0; i < 10; i++) {
    if ((pid = fork()) == 0) {
      /* Child */
      write(1, msg, strlen(msg));
      exit(1);
    }
  }

  while (1)
    ;
  return 0;
}
