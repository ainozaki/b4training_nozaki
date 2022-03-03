#include <stdio.h>

int main(){
	const char *a = "aa";
	char * const b = "bb";
	const char * const c = "cc";

	// Change value
	// Error
	*a = 'x';
	// Change pointer
	// Ok
	a += 1;

	// Change value
	// Ok
	*b = 'x';
	// Change pointer
	// Error
	b += 1;

	// Change value
	// Error
	*c = 'x';
	// Change pointer
	// Error
	c += 1;

	return 0;
}
