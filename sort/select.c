#include <assert.h>
#include "sort.h"
#include "heap.h"

int select_sort(uint32_t *array, int len)
{
	int i, j, v, m ;
	for (i = 0; i < len; i ++)
	{
		m = i;
		v = array[m];
		for (j = i + 1; j < len; j ++)
		{
			if (array[j] < v)
			{
				m = j;
				v = array[m];
			}
		}
		if (m != i)
			SWAP_U32(array[i], array[m]);
	}
	return 0;
}

#define HEAP_LESS(x, y)		((x) < (y))
#define HEAP_SWAP(a, i, j)	SWAP_U32((a)[i], (a)[j])

int heap_sort(uint32_t *array, int len)
{
	HEAPIFY(array, len, HEAP_LESS, HEAP_SWAP);
	int i;
	for (i = len - 1; i > 0; i --)
	{
		SWAP_U32(array[0], array[i]);
		HEAP_FIX_DOWN(array, 0, i, HEAP_LESS, HEAP_SWAP);
	}
	return 0;
}
