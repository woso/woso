#include <assert.h>
#include "sort.h"

int bubble_sort(uint32_t *array, int len)
{
	assert(array && len > 0);
	int i, j, swap;
	for (i = 1; i < len; i ++)
	{
		swap = 0;
		for (j = 0; j < len - i; j ++)
		{
			if (array[j] <= array[j+1])
				continue;
			SWAP(array[j], array[j+1]);
			swap = 1;
		}

		if (!swap)
			break;
	}
	return 0;
}
