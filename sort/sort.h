#ifndef SORT_H_
#define SORT_H_

#include <stdint.h>

#define SWAP(x,y) do{uint32_t temp=(x); (x)=(y); (y)=temp;} while(0)

typedef int (*sort_func_t)(uint32_t *array, int len);
int select_sort(uint32_t *array, int len);
int insert_sort(uint32_t *array, int len);
int bubble_sort(uint32_t *array, int len);
int merge_sort(uint32_t *array, int len);
int quick_sort(uint32_t *array, int len);
int heap_sort(uint32_t *array, int len);
int radix_sort(uint32_t *array, int len);
int shell_sort(uint32_t *array, int len);

#endif /*SORT_H_*/
