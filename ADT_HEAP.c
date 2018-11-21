#include "ADT_HEAP.h"

HEAP* create_heap(int max){
	HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
	heap->last = -1;
	heap->size = 0;
	heap->max_size = max;
	heap->array = (int*)malloc(sizeof(int)*max);
	return heap;
}
	
