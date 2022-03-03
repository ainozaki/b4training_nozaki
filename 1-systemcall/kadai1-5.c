#include <fcntl.h>
#include <stdio.h>

int main(){
	int count = 0;
	while(open("kadai1-5.txt", O_RDONLY) >= 0){
		count++;
	}
	printf("counter: %d\n", count);
	return 0;
}
