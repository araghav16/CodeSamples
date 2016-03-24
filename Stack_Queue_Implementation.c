#include <stddef.h>

/*
** Raghav Agarwal
** C Implementation of stack using array and 
** of Queue using linkedlist 
*/
#define MAX_ITEMS 10

/*
** STACK - Last In First Out 
*/
typedef struct stack_t{
  int stack_items[MAX_ITEMS];
  int top;
}Stack;

Stack stack;

/*
** QUEUE - First In First Out utilising LinkedLists
*/
typedef struct Element{
int             item;
struct Element* next;
}Element;

typedef struct queue_t{
Element *first;
Element *last;
int      size;
}Queue;

Queue queue;

/*
**  Pop the top item on the Stack
*/
int pop(){

  int item;

  //check if there are items to remove
  if( -1 == stack.top )
  {
    printf("Stack is Empty !\n");
    return stack.top;
  }else
  {
    item = stack.stack_items[stack.top];
    printf("Popped item from stack is = %d\n", item);
    stack.top--;
    return item;
  }
  return item;
}

/*
**  Prompts user for an input and then pushes item onto the Stack 
*/
void push(){

  int item;

  if ( stack.top == MAX_ITEMS - 1 )
  {
    printf("Stack is Full, stack.top = %d", stack.top);
  }else
  {
    printf("Enter item to push to stack: ");
    scanf_s("%d", &item);
    
    stack.top++;
    stack.stack_items[stack.top] = item;
  }
}

/*
**  Prints all items on the Stack
*/
void showAllStack(){

  int i = 0;

  if( -1 == stack.top)
  {
    printf("Stack is Empty!\n");
  }

  for(i = stack.top;i > -1;i--)
  {
    printf("Stack item[%d]: %d\n", i, stack.stack_items[i]);
  }
}

/*
**  Returns the current number of items on the Stack
*/
int getStackSize(){

  int size = stack.top + 1;
  //printf("No. of Items in Stack: %d\n", size);

  return size;
}

/*
** Deletes all item on the Stack
*/
void purgeStack(){
  
  if( -1 == stack.top)
  {
    printf("Stack is Empty");
  }

  while( -1 != stack.top)
  {
    pop();
  }
}

/*
** Inserts item in the Queue and updates queue.last
*/
void enqueue()
{
  int item = 0;
  
  printf("Enter item to equeue : ");
  scanf_s("%d", &item);


  if(queue.first == NULL) 
  {
    //Queue is empty, entering first entry and assigning both first and last to same node

    queue.first = (struct Element*)malloc(sizeof(struct Element));
    queue.first->item = item;
    queue.first->next = NULL;

    queue.last = (struct Element*)malloc(sizeof(struct Element));
    queue.last = queue.first;
  }else
  {
    //Enter element at the end of queue, using queue.last as reference.
    queue.last->next = (struct Element*)malloc(sizeof(struct Element));
    queue.last = queue.last->next;
    
    queue.last->item = item;
    queue.last->next = NULL;
  }

   queue.size++;
}

/*
** prints and removes the first item on the queue and updates queue.first
*/
Element* dequeue()
{
  Element *dequeued_node;

  if( queue.first == NULL )
  {
    printf("Queue is Empty");
  }else
  {
    dequeued_node = queue.first;
    
    if(queue.first->next != NULL)
    {
      //Iterate queue first to next node
      queue.first = queue.first->next;
    }else
    {
      //Queue is empty
      queue.first = NULL;
      queue.last = NULL;
    }

    queue.size--;  
    printf("Dequeued Item = %d\n", dequeued_node->item);
    
    return dequeued_node;
  }
}

/*
** Prints all items on the queue
*/
void showAllQueue()
{
  if(queue.first != NULL)
  {
     Element *temp = queue.first;

     printf("Queue: ");
     while(temp != NULL)
     {
       printf("%d <- ", temp->item);
       temp = temp->next;    
     }
     printf("NULL\n");
  }else
  {
    printf("Queue is empty !\n");
  } 
}

/*
**  Returns the current number of items in the Queue
*/
int getQueueSize(){
  //printf("No. of Items in Queue: %d\n", queue.size);
  return queue.size;
}

/*
** Function to test various Stack operations
*/
void testStack()
{
  int i,stackSize;

  for(i = 0; i < 5; i++)
  {
    push();
  }

  showAllStack();

  stackSize = getStackSize();
  for(i = 0; i < stackSize; i++)
  {
    pop();
  }

  showAllStack();

  for(i = 0; i < 5; i++)
  {
    push();
  }

  purgeStack();

  showAllStack();
}

/*
** Function to test various Queue operations
*/
void testQueue()
{
  int i,queueSize;
  Element* temp;

  for(i = 0; i < 5; i++)
  {
    enqueue();
  }

  showAllQueue();

  queueSize = getQueueSize();

  for(i = 0; i < queueSize; i++)
  {
    temp = dequeue();
    free(temp);
  }

  showAllQueue();

  printf("Queue size = %d\n", getQueueSize());
}

int main()
{
  Element *temp;
  int option =  1;
  stack.top  = -1;
  queue.size =  0;
  
  while(option){

    printf("\n************* Menu *************\n");
    printf("****            STACK        ***\n");
    printf("****  1) Push Item to Stack  ***\n");
    printf("****  2) Pop Item from Stack ***\n");
    printf("****  3) Show Items on Stack ***\n");
    printf("****  4) Show Stack Size     ***\n");
    printf("****  5) Purge               ***\n");
    printf("****            QUEUE        ***\n");
    printf("****  7) Enqueue             ***\n");
    printf("****  8) Dequeue             ***\n");
    printf("****  9) Show Items on Queue ***\n");
    printf("**** 10) Show Queue Size     ***\n");    
    printf("****                         ***\n");
    printf("**** 11) Test Stack          ***\n");
    printf("**** 12) Test Queue          ***\n");
    printf("****  0) Exit                ***\n");
    printf("********************************\n");

    printf("Selection Your Option: ");
    scanf_s("%d", &option);

    switch(option)
    {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        showAllStack();
        break;
      case 4:
        getStackSize();
        break;
      case 5:
        purgeStack();
        break;  
      case 7:
        enqueue();
        break;   
      case 8:
        temp = dequeue();
        free(temp);
        break;      
      case 9:
        showAllQueue();
      case 10:
        getQueueSize();
        break; 
      case 11:
        testStack();
        break; 
      case 12:
        testQueue();
        break;   
      case 0:
        exit(0);
    }
  }

  return 0;
}