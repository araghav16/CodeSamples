#include <iostream>
#include <string>

using namespace std;

/*
** Stack implementation in C++, using linkedlist.
** Last In First Out (LIFO)
*/
class Stack {

public:
	Stack();
	void  push(void *data);
	void* pop();
	void  print();

protected:
	typedef struct Element {
		void           *data;
		struct Element *next;
	} Element;

	Element *top;
};

/* Constructor  */
Stack::Stack(void)
{
	cout << "Stack Object is being created \n";
	top = nullptr;
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
void* Stack::pop()
{
	/* check stack is not empty,
	** take copy of the top,
	** iterate stack,
	** print data and delete element
	*/

	Element *elm;

	//Check stack is not empty
	if (top != nullptr)
	{
		elm = top;
		top = top->next;
		#if 1
		int* intptr = static_cast<int*>(elm->data);
		cout << "Pop item: " << *intptr << endl;
		#endif
		return elm->data;
	}
	else
	{
		cout << "Stack is Empty!" << endl;
	}

	return nullptr;
};

/**
**  Prints all stack items as int
**/
void Stack::print()
{
	Element *elm;

	if (top != nullptr)
	{
		cout << "Stack: ";
		elm = top; 
		//|_|->|_|->|_|->nullptr
		while (elm != nullptr)
		{
			//Explicitly cast to another point type before dereferencing 
			int *intPtr = static_cast<int*>(elm->data);

			cout << *intPtr << " -> ";
			elm = elm->next;
		}
		cout << "nullptr \n";
	}
	else
	{
		cout << "Stack is empty !\n";
	}
};

/*
** Queue implementation in C++, using linkedlist.
** First In First Out (FIFO)
*/
class Queue {

public:
	Queue();
	void   enqueue(void *data);
	void*  dequeue();
	void   print();
private:

protected:
	typedef struct Element {
		void           *data;
		struct Element *next;
	}Element;

	Element *front;
	Element *rear;
};

//Constructor
Queue::Queue(void)
{
	cout << "Queue Object is being created \n";
	front = nullptr;
	rear  = nullptr;
}

void Queue::enqueue(void *data)
{
	Element *temp = new Element();

	temp->data = data;
	temp->next = nullptr;

	if (front == nullptr)
	{
		front = temp;
		rear = front;
	}
	else
	{
		rear->next = temp;
		rear = rear->next;
	}
}

/* Dequeus and returns the first
** item on the queue.
**/
void* Queue::dequeue()
{
	Element *elm;

	if (front != nullptr)
	{
		elm = front;

		if (front == rear)//When last item is dequed
		{
			front = nullptr;
			rear  = nullptr;
		}
		else
		{
			front = front->next;
		}
		#if 1
		int* intptr = static_cast<int*>(elm->data);
		cout << "Dequeued item: " << *intptr << endl;
		#endif

		return elm->data;
	}

	return nullptr;
}

/* Prints all items on the Queue as int
**/
void Queue::print()
{
	Element *elm;
	elm = front;

	cout << "Queue: ";
	while (elm != nullptr)
	{
		int* intptr = static_cast<int*>(elm->data);
		cout << *intptr << " <- ";

		elm = elm->next;
	}
	cout << "nullptr\n";
}


/* Various functions to test Stack
**/
void testStack1(void)
{
	Stack stack;

	int n1 = 2;
	int n2 = 4;
	int n3 = 6;
	int n4 = 8;
	int n5 = 10;

	stack.push(&n1);
	stack.print();
	stack.pop();
	stack.print();
	stack.push(&n2);
	stack.push(&n3);
	stack.push(&n4);
	stack.push(&n5);

	stack.print();
	stack.pop();
	stack.print();
}
void testStack2(void)
{
	Stack stack;

	int n1 = 2;
	int n2 = 4;
	int n3 = 6;
	int n4 = 8;
	int n5 = 10;

	stack.push(&n1);
	stack.push(&n2);
	stack.push(&n3);
	stack.push(&n4);
	stack.push(&n5);

	stack.print();
}
void testStack3(int input)
{
	Stack stack;
	int n1 = 5;

	for (int i = 0; i < input; i++)
	{
		stack.push(&n1);
	}

	stack.print();

	for (int i = 0; i < input; i++)
	{
		stack.pop();
	}

	stack.print();

	for (int i = 0; i < input; i++)
	{
		stack.push(&n1);
	}

	stack.print();
}
/* Various functions to test Queue
**/
void testQueue1(void)
{
	Queue queue;
	int n1 = 2;
	int n2 = 4;
	int n3 = 6;
	int n4 = 8;
	int n5 = 10;

	queue.enqueue(&n1);
	queue.print();
	queue.dequeue();
	queue.print();

	queue.enqueue(&n2);
	queue.enqueue(&n3);
	queue.enqueue(&n4);
	queue.enqueue(&n5);

	queue.print();
	queue.dequeue();
	queue.print();
}
void testQueue2(int input)
{
	Queue queue;

	int n1 = 5;

	for (int i = 0; i < input; i++)
	{
		queue.enqueue(&n1);
	}

	queue.print();

	for (int i = 0; i < input; i++)
	{
		queue.dequeue();
	}

	queue.print();

	for (int i = 0; i < input; i++)
	{
		queue.enqueue(&n1);
	}
}

/*
**
*/
int main()
{
	testStack1();
	testStack2();
	testStack3(10000);
	
	cout << endl;

	testQueue1();
	testQueue2(10000);

	return 0;
}
