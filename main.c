#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sort.c"

#define NUMCOUNT 10
#define MAX 255

#define type unsigned char

int main() {
	srand(time(0));
	
	type* nums = (type*) malloc(NUMCOUNT * sizeof(type));

	for(int i = 0; i < NUMCOUNT; i++) {
		nums[i] = (type) rand() % 16;
		printf("%d ", nums[i]);
	}
	printf("\n");

	sort(nums, nums+NUMCOUNT, 3);

	for(int i = 0; i < NUMCOUNT; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}