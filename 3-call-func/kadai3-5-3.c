#include <stdio.h>

void f(int);

void g(int x){
	char w;
	double y;
	printf("y @ %p\n", &y);
	if (x > 0){
		f(x);
	}
}

void f(int x){
	char z;
	printf("z @ %p\n", &z);
	g(x - 1);
}

int main(){
	int w;
	f(2);
	printf("w @ %p\n", &w);
	return 0;
}
