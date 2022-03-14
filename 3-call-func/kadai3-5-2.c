#include <stdint.h>
#include <stdio.h>

static __attribute__((always_inline)) inline uint64_t get_rbp() {
  uint64_t rbp;
  __asm__("movq %%rbp, %0\t\n" : "=rm"(rbp));
  return rbp;
}

void f(int x) {
  char w;
  int y;
  // printf("  y @ %p\n", &y);
  printf("   rbp(f) @ 0x%0lx\n", get_rbp());
  if (x > 0) {
    f(x - 1);
  }
}

int main() {
  int z;
  f(2);
  // printf("  z @ %p\n", &z);
  printf("rbp(main) @ 0x%0lx\n", get_rbp());
  return 0;
}
