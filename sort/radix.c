#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int radix_u32(uint32_t *new, uint32_t *array, int len, int shift)
{
	int i, k;
	int cnt[65536] = { 0 }; 

	for (i = 0; i < len; ++i)
	{
		k = array[i]>>shift & 0xFFFF;
		cnt[k]++;
	}

	for (i = 1; i < 65536; ++i)
		cnt[i] += cnt[i-1];

	for (i = len - 1; i >= 0; --i)
	{
		k = array[i]>>shift & 0xFFFF;
		new[--cnt[k]] = array[i];
	}

	return 0;
}

int radix_sort(uint32_t *array, int len)
{
	uint32_t *new = malloc(sizeof(new[0])*len);

	radix_u32(new, array, len, 0);
	radix_u32(array, new, len, 16);

	return 0;
}
