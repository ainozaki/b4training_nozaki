#include <stdio.h>

int main() {
	int x = 0xf1f2f3f4;
	char *p = (char*)&x;
	printf("p[0] = %hhx, p[1] = %hhx, p[2] = %hhx, p[3] = %hhx\n",*p, *(p + 1), *(p + 2), *(p + 3));

	return 0;
}
