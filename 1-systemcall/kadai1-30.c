#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler(int sig) {
  char *msg = "You can't stop me by Ctrl-C!\n";
  write(1, msg, strlen(msg));
}

int main() {
  struct sigaction act;
  memset(&act, 0, sizeof(act));
  act.sa_handler = handler;
  sigaction(SIGINT, &act, NULL);

  for (;;)
    ;

  return 0;
}
