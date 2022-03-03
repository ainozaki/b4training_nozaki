#include <stdio.h>

int main() {
	int x = 0xf1f2f3f4;
	char *p = (char*)&x;
	printf("p[0] = %d, p[1] = %d, p[2] = %d, p[3] = %d\n",*p, *(p + 1), *(p + 2), *(p + 3));
	return 0;
}
