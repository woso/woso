#include <assert.h>
#include "sort.h"

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
			SWAP(array[i], array[m]);
	}
	return 0;
}
