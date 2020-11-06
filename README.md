# 자료구조 
- ### 2018FW COMP331 자료구조 수업동안 배웠던 코드자료에 대한 정리를 위한 Resipotary

-  ### 목차 (각 제목 클릭 시 설명부분으로 바로 이동)
   1. [Stack](README.md#Stack) 
   2. [Queue](README.md#Queue) 
   3. [BST_Tree](README.md#BST_Tree) 
   4. [Heap](README.md#Heap)
   5. [List](README.md#List) 
  
> ## Stack
- Stack은 후입선출의 기능을 가지는 자료구조의 형태

- push, pop 의 함수를 통해 Stack의 기능을 구현하고, 
 count(데이터의 수), top(가장 상위 데이터를 나타내는 포인터) 라는   struct 내부 변수를 가짐.
   ###  `>>  Let's see the Code`  
 - struct 정의 
```C++  
   typedef struct stack{
			int count; // stack 내부의 노드 수 
			STACK_NODE* top; // stack의 top 노드를 가르키는 
			                 //  포인터
   }STACK; 
``` 
 - stack에 사용되는 함수 
     --  Push  
         stack에 새 노드를 추가하는 함수 
```C++  
   int push(STACK* S, void* in){
	   printf("pushing a data into stack......\n");
		STACK* PSTACK = (STACK*)malloc(sizeof(STACK));
		STACK_NODE* N1 = (STACK_NODE*)malloc(sizeof(STACK_NODE));
        //stack을 새로 생성하고 노드까지 생성함.
        
		if(!N1) return 0;
			N1 -> data_ptr = in;
			N1 -> link = S -> top; // my next become old boss

			S -> top = N1; // 새롭게 추가된 노드는 top이 되고
			S -> count++; // 카운트는 하나 증가
	return 1;
}
```
   -- Pop  
      제일 상위에 위치하는 노드를 제거하는 함수
```C++  
   int pop(STACK* S, void* in){
	   printf("pushing a data into stack......\n");
		STACK* PSTACK = (STACK*)malloc(sizeof(STACK));
		STACK_NODE* N1 = (STACK_NODE*)malloc(sizeof(STACK_NODE));
        //stack을 새로 생성하고 노드까지 생성함.
        
		if(!N1) return 0;
			N1 -> data_ptr = in;
			N1 -> link = S -> top; // my next become old boss

			S -> top = N1; // 새롭게 추가된 노드는 top이 되고
			S -> count++; // 카운트는 하나 증가
	return 1;
}
```

> ## Queue
- Queue는 선입선출의 기능을 가지는 자료구조의 형태

- enqueue, dequeue 의 함수를 통해 Queue 데이터 삽입 및 반출 기능 구현, count(데이터의 수), node의 위치 포인터 front, rear를 struct 내부 변수를 가짐.

- Queue의 노드들은 다음 노드를 가르키는 포인터를 가지고 있음.
 
   ###  `>>  Let's see the Code`  
 - node 및 struct 정의 
```C++  
	typedef struct node{
			void* data_ptr;
			struct node* next;
	}QUEUE_NODE; // queue노드는 데이터 내용과 다음 노드의 포인터를 변수로 가짐

	typedef struct{
			int count;
			QUEUE_NODE* front; //queue 내부의 노드 위치를 가지는 
			QUEUE_NODE* rear;  // 포인터 front, rear
	}QUEUE;
```

- Queue에 사용되는 함수

    -- create_queue()  
``` C++
	 QUEUE* create_queue(){
		QUEUE* queue;
		queue=(QUEUE*)malloc(sizeof(QUEUE));
		//malloc를 이용해 queue 생성 후 동적 메모리 할당
		if(queue){
			queue->front = NULL; // 초기화 과정
			queue->rear = NULL;
			queue->count = 0;
		
		return queue;
		}else{
			return NULL;
}  
```
   -- enqueue
    queue에 새로운 노드를 추가하는 함수 
  새롭게 추가되는 노드는 queue의 rear에 연결되는 것을 구현  
 타겟으로 하는 queue와 새로운 노드를 함수의 인자로 받아 boolean 타입으로 반환함.
```C++   
bool enqueue(QUEUE* queue, void* in){
	QUEUE_NODE* new_node=(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    
	if(new_node == NULL){
		return false;
	}else{	
		new_node->data_ptr = in;
		new_node->next = NULL;
	if(queue->count == 0){
		queue->front=new_node;
	}else{
		queue->rear->next = new_node;
	}

	queue->rear=new_node;
	queue->count++;

	return true;
	}
}
``` 
   -- dequeue
   queue의 가장 앞부분에 있는 노드를 제거하는 함수
   queue의 front 다음 노드를 front로 바꾸고, count를 하나 늘리는 기능

//dequeue 함수 코드 입력하기
```C++    
bool enqueue(QUEUE* queue, void* in){
	QUEUE_NODE* new_node=(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    
	if(new_node == NULL){
		return false;
	}else{	
		new_node->data_ptr = in;
		new_node->next = NULL;
	if(queue->count == 0){
		queue->front=new_node;
	}else{
		queue->rear->next = new_node;
	}

	queue->rear=new_node;
	queue->count++;

	return true;
	}
}
``` 
