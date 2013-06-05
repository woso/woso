#include <assert.h>
#include "sort.h"

int insert_sort(uint32_t *array, int len)
{
	assert(array && len);

	int i, j;
	for (i = 1; i < len; i ++)
	{
		uint32_t v = array[i];
		for (j = i - 1; j >= 0; j --)
		{
			if (v < array[j])
				array[j+1] = array[j];
			else
				break;
		}
		array[j + 1] = v;
	}
	return 0;
}

