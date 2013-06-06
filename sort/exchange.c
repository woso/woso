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
			SWAP_U32(array[j], array[j+1]);
			swap = 1;
		}

		if (!swap)
			break;
	}
	return 0;
}

static int partition(uint32_t *off, int len)
{
	assert(off);

	int low = 0;
	int high = len - 1;

	int v = off[low];

	while (low != high)
	{
		while (low != high)
		{
			if (off[high] < v)
			{
				off[low++] = off[high];
				break;
			}
			else
				high --;
		}
		while (low != high)
		{
			if (off[low] > v)
			{
				off[high--] = off[low];
				break;
			}
			else
				low ++;
		}
	}

	off[low] = v;
	return low;
}

int quick_sort(uint32_t *array, int len)
{
	if (len < 2)
		return 0;

	int p = partition(array, len);
	quick_sort(array, p);
	quick_sort(array + p + 1, len - p - 1);
	return 0;
}
