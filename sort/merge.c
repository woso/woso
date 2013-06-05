#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int merge(uint32_t *new, uint32_t *a1, int len1, uint32_t *a2, int len2)
{
	assert(len1 > 0 && len2 > 0);

	int i1 = 0;
	int i2 = 0;
	int i = 0;

	while (i1 < len1 && i2 < len2)
	{
		if (a1[i1] <= a2[i2])
			new[i++] = a1[i1++];
		else
			new[i++] = a2[i2++];
	}

	if (i1 < len1)
	{
		memcpy(&new[i], &a1[i1], sizeof(new[0])*(len1 - i1));
		i += len1 - i1;
	}
	if (i2 < len2)
	{
		memcpy(&new[i], &a2[i2], sizeof(new[0])*(len2 - i2));
		i += len2 - i2;
	}

	assert(i == len1 + len2);
	return 0;
}

int merge_sort(uint32_t *array, int len)
{
	if (len < 2)
		return 0;

	static uint32_t *new = NULL;
	if (!new)
		new = malloc(sizeof(new[0])*len);

	uint32_t *a1 = array;
	int len1 = len / 2;

	uint32_t *a2 = array + len1;
	int len2 = len - len1;

	merge_sort(a1, len1);
	merge_sort(a2, len2);

	merge(new, a1, len1, a2, len2);
	memcpy(array, new, sizeof(array[0])*len);

	return 0;
}
