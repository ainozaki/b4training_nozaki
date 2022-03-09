#include <stdio.h>
#include <unistd.h>

int x = 0x00216948;
int y = 0x656e6946;
char *str1 = (char *)&x;
char *str2 = (char *)&y;

int main() {
  printf("   &x = %p,    &y = %p\n", &x, &y);
  printf(" str1 = %p,  str2 = %p\n", str1, str2);
  printf("&str1 = %p, &str2 = %p\n", &str1, &str2);

  printf("str1: %s\n", str1);
  fflush(stdout);
  sleep(1);

  printf("str2: %s#\n", str2);
  return 0;
}
