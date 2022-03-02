#include <stdio.h>

int main(){
	int x = 10, y = 20;
	int *xp = &x, *yp = &y;

	printf("x=%d, *xp=%d, y=%d, *yp=%d\n", x, *xp, y, *yp);

	xp = yp;
	*yp = 30;
	
	printf("x=%d, *xp=%d, y=%d, *yp=%d\n", x, *xp, y, *yp);
	return 0;
}


