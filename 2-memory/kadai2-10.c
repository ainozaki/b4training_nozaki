#include <stdio.h>

struct bar {
  char a;
  int b;
  char c;
  double d;
} bar;

int main() {
  printf("sizeof(double) = %lu, sizeof(bar) = %lu\n", sizeof(double),
         sizeof(struct bar));
  printf("&bar = %p\n", &bar);
  printf("&bar.a = %p\n", &bar.a);
  printf("&bar.b = %p\n", &bar.b);
  printf("&bar.c = %p\n", &bar.c);
  printf("&bar.d = %p\n", &bar.d);
  return 0;
}
