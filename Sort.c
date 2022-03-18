#include <stdio.h>
#include <stdint.h>

#define type unsigned char

void swap(type* one, type* two) {
	type temp = *one;
	*one = *two;
	*two = temp;
}

void sort(type* start, type* end, int shift) {
	if(shift == -1 || !(start < end-1)) {
		return;
	}

	for(int i = 0; i < 10; i++) {
		printf("%d ", start[i]);
	}
	printf("\n");

	
	type* i = start;
	type* j = end-1;
	int swaps = 0;
	while(i < j) {
		if(((*i) >> shift & 1) && !((*j) >> shift & 1)) {
			printf("arr[%d]: %d  arr[%d]: %d  ", i - start, *i, j-start, *j);
			printf("Swapping...\n");
			swap(i, j);
			i++;
			j--;
			swaps++;
		} else if((*j) >> shift & 1) {
			printf("arr[%d]: %d  arr[%d]: %d\n", i - start, *i, j-start, *j);
			j--;
			swaps++;
		} else {
			printf("arr[%d]: %d  arr[%d]: %d\n", i - start, *i, j-start, *j);
			i++;
		}
	}
	j += j==i;

	printf("DOING LEFT COMPARISONS %d\n", shift - 1);
	sort(start, j, shift - 1);
	printf("DOING RIGHT COMPARISONS %d\n", shift - 1);
	sort(j, end, shift - 1);
}