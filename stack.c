#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	void* data_ptr;
	struct node* link;
} STACK_NODE;//TYPEDEF all together

typedef struct stack{
	int count;
	STACK_NODE* top;
}STACK;

STACK* make_stack();
int push(STACK* S, void* in);
void* pop(STACK* S);


int main(){

	STACK* s1=make_stack();	
	printf("stack s1's size : %d \n", s1->count);

	int a =10;
	int b =20;

	push(s1, &a);
	push(s1, &b);

	printf("stack s1's size : %d \n", s1->count);
	return 0;
}

STACK* make_stack(){
	printf("creating a stack....\n");
	STACK* PSTACK = (STACK*)malloc(sizeof(STACK));
	if(!PSTACK) return 0;
	PSTACK -> count = 0;
	PSTACK -> top = 0;
	return PSTACK;
}

int push(STACK* S, void* in){

	printf("pushing a data into stack......\n");
	STACK* PSTACK = (STACK*)malloc(sizeof(STACK));
	STACK_NODE* N1 = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!N1) return 0;
	
	N1 -> data_ptr = in;
	N1 -> link = S -> top; //  my next become old boss
	S -> top = N1;
	S -> count++;
	return 1;
}

void* pop(STACK* S){



}
