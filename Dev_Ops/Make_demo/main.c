#include <stdio.h>
#include "header.h"

int main()
{
	int result1 = add(2, 3);
	printf("addition is done:  %d\n", result1);
	int result2 = sub(3, 2);
	printf("subtraction is done: %d\n", result2);
	
	return 0;
}

