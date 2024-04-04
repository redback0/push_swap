#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	int	arr[5] = {4, 6, 3, 2, 8};

	int i = 0;
	while (i < 5)
		printf("%d\n", arr[i++]);
	printf("\n\n");
	quicksort(arr, 0, 4);
	i = 0;
	while (i < 5)
		printf("%d\n", arr[i++]);
}
