#include <iostream>
#include <string>

using namespace std;

/*
** Stack implementation in C++, using linkedlist.
** Last In First Out (LIFO)
*/
class Stack{

public:
      Stack();
      void push(void *data);
      void pop();
      void print();

protected:
      typedef struct Element{
        void           *data;
        struct Element *next;
      } Element;

      Element *top;
};

/* Constructor  */
Stack::Stack( void )
{
  cout << "Stack Object is being created \n" ; 
  top = NULL;
}

/**
**  Inserts item on top of stack
**/
void Stack::push(void *data)
{
  Element *elm = new Element;

  elm->data = data;
  elm->next = top;
  top = elm;
};

/**
**  Pop item from top of stack
**/
void Stack::pop()
{
  /* check stack is not empty,
  ** take copy of the top, 
  ** iterate stack,
  ** print data and delete element
  */

  Element *elm = new Element;

  //Check stack is not empty
  if(top != NULL)
  {
    elm = top;
    top = top->next;
    int* intptr = static_cast<int*>(elm->data);
    cout << "Pop item: " << *intptr << endl;
  }else
  {
    cout << "Stack is Empty!"<< endl;
  }

  delete elm;
};

/**
**  Prints all stack items as int
**/
void Stack::print()
{
  Element *elm;
  
  if( top != NULL)
  {
    cout << "Stack: ";
    elm = top;
    //|_|->|_|->|_|->NULL
    while(elm != NULL)
    {
      //Explicitly cast to another point type before dereferencing 
      int *intPtr = static_cast<int*>(elm->data);

      cout << *intPtr << " -> ";
      elm = elm->next;
    }
    cout << "NULL \n";
  }else
  {
    cout << "Stack is empty !\n" ;
  }
};

/*
** Queue implementation in C++, using linkedlist.
** First In First Out (FIFO)
*/
class Queue{

public:
   Queue();
   void  enqueue(void *data);
   void  dequeue();
   void  print();
private:

protected:
  typedef struct Element{
  void           *data;
  struct Element *next;
  }Element;

  Element *front;
  Element *rear;
};

//Constructor
Queue::Queue( void )
{
  cout << "Queue Object is being created \n" ; 
  front = NULL;
  rear  = NULL;
}

void Queue::enqueue(void *data)
{
  Element *temp = new Element();

  temp->data = data;
  temp->next = NULL;

  if(front == NULL)
  {
    front = temp;
    rear = front;   
  }else
  { 
    rear->next = temp;
    rear = rear->next;
  }
}

/* Dequeus and returns the first
** item on the queue.
**/
void Queue::dequeue()
{
  Element *elm = new Element();

  if(front != NULL)
  {
      elm = front;

      if(front == rear)//When last item is dequed
      {
        front = NULL;
        rear  = NULL;
      }else
      {
        front = front->next;
      }
        int* intptr = static_cast<int*>(elm->data);
        cout << "Dequeued item: " << *intptr <<endl;
  }

  delete elm;
}


/* Prints all items on the Queue as int
**/
void Queue::print()
{
  Element *elm;
  elm = front;

  cout << "Queue: ";
  while(elm != NULL)
  {
    int* intptr = static_cast<int*>(elm->data);
    cout  << *intptr << " <- ";

    elm = elm->next;
  }
  cout << "NULL\n";
}

/* 
**
*/
int main()
{
  Stack Stack1;

  int n1 = 2;
  int n2 = 4;
  int n3 = 6;
  int n4 = 8;
  int n5 = 10;

  Stack1.push(&n1);
  Stack1.print();
  Stack1.pop();
  Stack1.print();
  Stack1.push(&n2);
  Stack1.push(&n3);
  Stack1.push(&n4);
  Stack1.push(&n5);

  Stack1.print();
  Stack1.pop();
  Stack1.print();

  cout << endl;

  Queue Queue1;

  Queue1.enqueue(&n1);
  Queue1.print();
  Queue1.dequeue();
  Queue1.print();

  Queue1.enqueue(&n2);
  Queue1.enqueue(&n3);
  Queue1.enqueue(&n4);
  Queue1.enqueue(&n5);

  Queue1.print();
  Queue1.dequeue();
  Queue1.print();

  return 0;
}

