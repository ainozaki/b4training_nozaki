#include <stdio.h>

struct bar {
  char a;
  int b;
  char c;
  double d;
};

int main() {
  struct bar bar1, bar2;
  bar1.a = 'a';
  bar1.b = 1;
  bar1.c = 'a';
  bar1.d = 1;

  bar2.a = 'a';
  bar2.b = 1;
  bar2.c = 'a';
  bar2.d = 1;

  printf("bar1\n");
  unsigned char *src = (unsigned char *)&bar1;
  for (int i = 0; i < (int)sizeof(bar1); i++) {
    printf("%02x ", 0xff & src[i]);
  }
  printf("\n");

  printf("bar2\n");
  unsigned char *src2 = (unsigned char *)&bar2;
  for (int i = 0; i < (int)sizeof(bar2); i++) {
    printf("%02x ", 0xff & src2[i]);
  }
  printf("\n");
  return 0;
}
