#include <stdio.h>

void foo() { int x = 200; }

// int *bar(){
//	int y = 100;
//	return &y;
//}

int main() {
  int *z;
  int before_foo, after_foo;
  // z = bar();
  before_foo = *z;
  foo();
  after_foo = *z;
  printf("before_foo = %d, after_foo = %d\n", before_foo, after_foo);
  return 0;
}
