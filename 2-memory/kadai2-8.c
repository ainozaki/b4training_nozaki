#include <stdio.h>

int main() {
  printf("%c%c%c%c%c\n", *"Hi", "everybody"[2], *("welcome" + 2),
         "to sslab."[5], *("Enjoy!" + 3));
  return 0;
}
