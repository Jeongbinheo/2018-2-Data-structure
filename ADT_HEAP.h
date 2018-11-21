#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int last;
	int size;
	int* array;
	int max_size;
}HEAP;

HEAP* create_heap(int max);
HEAP* reheapup(heap, newNode);
HEAP* reheapdown(heap, root, last);
HEAP* insertHeap(heap, last, data);
HEAP* deleteHeap(heap, last, data);
