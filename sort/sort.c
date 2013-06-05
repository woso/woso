#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "sort.h"

#define DEFAULT_SCALE (1024)
#define DEFAULT_DIST (64)


static const char *mode_list[] = {"heap","insert","select","bubble","merge","quick", NULL};
static const sort_func_t func_list[] = {NULL, NULL, NULL, bubble_sort, NULL, NULL, NULL};

static void usage(const char *prog, const char *info)
{
	fprintf(stderr, "\nUsage: %s [options]\n", prog);
    fprintf(stderr, "%s",
"  -p             print items after sort\n"
"  -s  <scale>    how many items to be sorted\n"
"  -d  <dist>     the value of item is deside by scale*dist\n"
"  -m  <mode>     avaliable sort mode:\n"
"      buble\n"
"      quick\n"
"      insert\n"
"      select\n"
"      merge\n"
"      heap\n"
"      radix\n"
        );
}

static int array_init(uint32_t *array, int len, int range)
{
	srandom(time(NULL));
	int i;
	for (i = 0; i < len; i ++)
		array[i] = random()%(range);
	return 0;
}

static int array_dump(uint32_t *array, int len)
{
	int i;
	for (i = 0; i < len; i ++)
	{
		printf("%u\t",array[i]);
		if((i+1)%8 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}

int main(int argc, char **argv)
{
	int ret;
	sort_func_t sort = NULL;
	int scale = 0;
	int dist = 0;
	int dump = 0;
	while( ( ret = getopt( argc, argv, "m:s:d:p" ) ) != EOF )
	{
		int i;
		switch( ret )
		{
			case 'm'://sort mode
				for(i = 0; mode_list[i] != NULL; i++)
				{
					if(!strcmp(optarg, mode_list[i]))
						sort = func_list[i];
				}
				break;
			case 's'://array scale
				scale = atoi(optarg);
				break;
			case 'd'://random dist
				dist = atoi(optarg);
				break;
			case 'p'://dump
				dump = 1;
				break;
			default:
				usage(argv[0], NULL);
				exit(1);
		}
	}
	if (scale <= 0)
		scale = DEFAULT_SCALE;
	if (dist <= 0)
		dist = DEFAULT_DIST;
	if (sort == NULL)
	{
		usage(argv[0], "sort mode must be specified by -m\n");
		exit(1);
	}

	uint32_t *array = (uint32_t *)malloc(sizeof(array[0]) * scale);
	array_init(array, scale, scale*dist);

	sort(array, scale);

	if(dump)
		array_dump(array, scale);
	return 0;
}

