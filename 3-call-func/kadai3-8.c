#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f();

void g(int x) {
  if (x % 2 == 0) {
    f();
  } else {
    f();
  }
}

void h(int x) {
  if (x % 3 == 0) {
    f();
  } else if (x % 3 == 1) {
    f();
  } else {
    f();
  }
}

int main() {
  int i;
  int r1, r2;

  srand(time(NULL));
  for (i = 0; i < 10; i++) {
    r1 = rand();
    r2 = rand();
    if (r1 % 2 == 0) {
      printf("calling g(0x%10d)...\t", r2);
      g(r2);
    } else {
      printf("calling h(0x%10d)...\t", r2);
      h(r2);
    }
  }
  return 0;
}

int search_func(void *addr) {
  if (addr > &g && addr < &h) {
    return 'g';
  } else if (addr > &h) {
    return 'h';
  } else {
    return 0;
  }
}

void f() {
  int x;
  void *ret = __builtin_return_address(0);
  printf("ret = %p, caller = %c\n", ret, search_func(ret));
}
