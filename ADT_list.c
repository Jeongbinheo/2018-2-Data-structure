#include "ADT_list.h"

LLIST* create_list(){
	LLIST* list;
	list = (LLIST*)malloc(sizeof(LLIST));
	
	if(list){	
		list->front = NULL;
		list->rear  = NULL;
		list->pos   = NULL;
		list->count = 0;
		return list;

	} else{
		return NULL;
	}

}

bool
add_node_at(
	LLIST* list,
	void* in,
	unsigned int index
){
	if((list->count) < index) return false;
	
	NODE* new_p = (NODE*)malloc(sizeof(NODE));
	if(!new_p){
		printf("fail to malloc \n");
		 return false;
	} else {
		new_p->data_ptr = in;
		new_p->next = NULL;
	}
	if(list->count==0){
		list->front = new_p;
		list->rear =  new_p;
		list->count++;
		return true;
	}
	




}
