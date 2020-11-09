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
   ###  `>>  Let's see the Code`  [Stack.c](https://github.com/Jeongbinheo/Datastructure/blob/master/stack.c) (클릭 시 전체 코드 페이지로 이동)
 - struct 정의 
```C++  
   typedef struct stack{
			int count; // stack 내부의 노드 수 
			STACK_NODE* top; // stack의 top 노드를 가르키는 
			                 //  포인터
   }STACK; 
``` 
 - stack에 사용되는 함수 
     
   - **Push** : stack에 새 노드를 추가하는 함수 


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


- **Pop** : 제일 상위에 위치하는 노드를 제거하는 함수


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
**-Queue는 선입선출의 기능을 가지는 자료구조의 형태**

**-enqueue, dequeue 의 함수를 통해 Queue 데이터 삽입 및 반출 기능 구현, count(데이터의 수),**
  **node의 위치 포인터 front, rear를 struct 내부 변수를 가짐.**

 **-Queue의 노드들은 다음 노드를 가르키는 포인터를 가지고 있음.**
 
   ###  `>>  Let's see the Code`  
   ### [ADT_QUEUE.h](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_queue.h) (클릭 시 전체 코드 페이지로 이동)             
   ### [ADT_QUEUE.c](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_queue.c) (클릭 시 전체 코드 페이지로 이동)
   
 **-node 및 struct 정의**
 
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

**-Queue에 사용되는 함수**

  **- create_queue()** : Queue 구조체를 만들고 초기화 하는 함수  

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

  **- enqueue**
  - queue에 새로운 노드를 추가하는 함수
  
  - 새롭게 추가되는 노드는 queue의 rear에 연결되는 것을 구현
  
  - 타겟으로 하는 queue와 새로운 노드를 함수의 인자로 받아 boolean 타입으로 반환함.


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
  **- dequeue**
  - queue의 가장 앞부분에 있는 노드를 제거하는 함수
  
  - queue의 front 다음 노드를 front로 바꾸고, count를 하나 늘리는 기능

//dequeue 함수 코드 입력하기
 












> ## BST_Tree
- BST_Tree는 Binary Search Tree로 child node가 오직 2개인 Tree이며,   재귀적으로 함수를 호출하며 데이터의 크기 비교를 하면서 작은 숫자는 left, 큰 숫자는 right에 데이터를 저장하는 자료구조.

- Tree는 ROOT라는 대표 Parent 노드 변수를 가지고 있음.

- 각 노드들은 데이터와 자신의 Right, Left에 있는 노드를 가르키는 포인터를 변수로 가지고 있음.
 
- Tree는 다양한 함수를 가지고 있음 
  1. add 함수는 새로운 노드를 재귀적으로 add함수를 사용해 크기 비교를 하면서 올바른 위치에 새 노드를 추가함
  
  2.  delete함수는 내가 없애고자 하는 노드를 없애고,  해당 노드가 가지고 있던 child를 다시 root와 연결해주는 기능을 가짐.
  
  3. 다양한 search (찾기) 함수들과 traverse (전체 훑기) 함수들이 존재함.  
 
   ###  `>>  Let's see the Code`  
   ### [ADT_BST_Tree.h](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_BST_TREE.h) (클릭 시 전체 코드 페이지로 이동)
   ### [ADT_BST_Tree.c](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_BST_TREE.c) (클릭 시 전체 코드 페이지로 이동)



  **>> 그림과 함께 보는 Binary Search Tree에 대한 설명**
 
  **8이 바로 ROOT 노드!**


![structure](https://blogfiles.pstatic.net/MjAyMDExMDZfMjg5/MDAxNjA0NjQzNDcxMDYz.-sO0T4S_jEIuMPaAsIiRFlqOhrdmG5EfYudIIOB2iY4g.kf1qUBP9DMoZgth1_zMxVNdbxnIRo7RcTOL4OWf5gygg.PNG.hdh988/BST_tree_image1.png?type=w2)


1. 새롭게 추가되는 노드들은 8과 크기 비교를 통해서 찾게 됨! 
2. 10이 추가되려면 8보다 크기때문에 Right에 추가됨
3. 이후의 숫자들도 모두 같은 과정을 통해 추가되어 숫자데이터를 저장하고 찾을 때 매우 빠른 속도로 내가 찾고자 하는 노드를 search 가능함.

> ## Heap
 - Heap Tree는 Tree 데이터 구조를 가지지만 배열을 사용하여 노드를 관리하기 때문에 BST와 배치방법에 있어 차이가 있음.
 
 -  우선적으로 데이터의 크기와 관계 없이 배열의 가장 끝에 데이터를 추가하고 나서 Parent노드와의 크기 비교를 통해 heap-up 과정을 거침 

 - 노드 제거 과정에서는 배열에서 제거하거자 하는 노드를 지우고 배열재정렬 후 크기에 맞게 Re-heap 과정을 진행함.

   ###  `>>  Let's see the Code`  
   ### [ADT_Heap.h](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_HEAP.h) (클릭 시 전체 코드 페이지로 이동)
   ### [ADT_Heap.c](https://github.com/Jeongbinheo/Datastructure/blob/master/ADT_HEAP.c) (클릭 시 전체 코드 페이지로 이동)

**>> 그림과 함께 보는 Heap에 대한 설명**

 **1.  HEAP은 Tree를 가장한 배열구조!**
 
 ![structure](   https://blogfiles.pstatic.net/MjAyMDExMDZfMTQ4/MDAxNjA0NjQ1NjUwOTQ3.Y4BWgiIW1dHSQRn60V8NPmqmygKpCHyNvsx1rcdgfL8g.twdL5UchIo04RmJ3AegXdU19UtypGUyvWadgS8KHG0kg.PNG.hdh988/heap_image1.png?type=w2)

위의 그림과 같이 heap은 tree구조를 가지는 것 처럼 보이지만

배열의 인덱스 계산을 통해 Child 노드를 정의함.

(현재 sorting까지 완전히 완료된 상태임을 알 수 있음. (Parent >  Child))


**2.  다음 자료구조 중에 Heap 구조가 아닌 것은?**

![structure](https://blogfiles.pstatic.net/MjAyMDExMDZfMTQ0/MDAxNjA0NjQ1ODExNTE0.ckvR6jThhVCUgfw3doM3fXW2a5yfLVlETeVT1Df5pFYg.8SGx3T-E9HnX3XVv1tHw5ptM7eYYPUjZmzR3jRwAnpwg.PNG.hdh988/heap_image_2.png?type=w2)

a) 는 올바른 HEAP 구조

b) 의 경우, HEAP의 대전제인 배열의 내림차순 채움이 위배된 경우

c) 는 배열은 올바르게 채워졌으나, 아직까지 크기비교를 통한 Re-heap과정이 진행되지 않아 완전한 HEAP 구조는 아님.
