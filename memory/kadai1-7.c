#include <stdio.h>

int a[10];
int *p;

short b[10];
short *q;

void init_array(int a[]){
	for (int i = 0; i < sizeof(a)/sizeof(int); i++){
		a[i] = i;
	}
}

int main() {
  int i;
  for (i = 0; i < sizeof(a) / sizeof(int); i++) {
    a[i] = i;
  }

	printf(" a    = %p\n", a);
	printf(" a[0] = %d\n", a[0]);
	printf("&a[0] = %p\n", &a[0]);

  printf("\n");
  p = a;
  printf("&p = %p\n", &p);
  printf(" p = %p | &a[0] = %p\n", p, &a[0]);

  p += 5;
  printf("*p = %11d |  a[5] = %11d | *(a+5) = %11d\n", *p, a[5], *(a + 5));
  printf(" p = %p | &a[5] = %p |  (a+5) = %p\n", p, &a[5], (a + 5));

  printf("\n");

	// short
  for (i = 0; i < sizeof(b) / sizeof(short); i++) {
    b[i] = i;
  }
  q = b;
  printf("&q = %p\n", &q);
  printf(" q = %p | &b[0] = %p\n", q, &b[0]);

  q += 5;
  printf("*q = %11d |  b[5] = %11d | *(b+5) = %11d\n", *q, b[5], *(b + 5));
  printf(" q = %p | &b[5] = %p |  (b+5) = %p\n", q, &b[5], (b + 5));

	// write a[10]
	//a[10] = 10;

	// sizeof
  printf("\n");
	printf("sizeof(a)  :%lu\n", sizeof(a));
	printf("sizeof(int):%lu\n", sizeof(int));
  return 0;
}
