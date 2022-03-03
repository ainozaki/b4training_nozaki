#include <stdio.h>

void swap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){
	int a = 10, b = 20;
	printf("a: %d, b; %d\n", a, b);

	swap(&a, &b);

	printf("a: %d, b: %d\n", a, b);
}
