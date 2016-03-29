"""
Python implementation of Stack and Queue using Linkedlists
By Raghav Agarwal  
"""

class _Element(object):
    """
     Internal class to represent a node with a single item and a link to next node.
    """
    def __init__(self, item):
        self.item = item
        self.next = None

#Last in First Out (LIFO) - Stack Implementation 
class Stack(object):
    """
        An implementation of stack using linkedlists
    """
    def __init__(self):
        self._top = None
        self._size = 0

    @property #decorator 
    def size(self):
        """ Returns number of items on the stack """
        return self._size 

    @property 
    def isEmpty(self):
        """ Return True if the stack is empty, False otherwise """
        return 0 == self._size

    def push(self,item):
        """ Insert an item to the stack. """
        n           = _Element(item) # create new element
        n.next      = self._top      # assign previous element to next
        self._top   = n              # update top to new element
        self._size += 1              # update size
        
    def pop(self): 
        """ Remove item from top of stack """
        if (self._top != None):
            n = self._top
            self._top = self._top.next
            self._size -= 1
            print("Popped item = ", n.item)
            return n 
        else:
            return None

    def showStack(self):
        """ Print all items on the stack """
        if  not self.isEmpty:
            n = self._top
            for i in range (0,self.size):
                print ("%d " % n.item, end="<- ")
                n = n.next
        print ("NULL ")

    
    def purgeStack(self):
        """ Pop all items on the stack """
        print("Purging Stack")
        while not stack.isEmpty:
            self.pop()
        self.showStack()

#First in First Out (FIFO) - Queue Implementation 
class Queue(object):
        
    def __init__(self):
        self.front = None
        self.rear  = None
        self._size  = 0

    @property
    def size(self):
        return self._size
        
    @property
    def isEmpty(self):
        """ Return True if the queue is empty, False otherwise """
        return 0 == self._size

    def enqueue(self,item):
        """ Inserts a new item at the end of Queue """       
        n = _Element(item)
        if self.front == None:
            self.front     = n
            self.rear      = self.front
        else:
            self.rear.next = n
            self.rear      = self.rear.next  
        self._size += 1

    def dequeue(self):
        """ Prints and removes the item currently at the front of Queue """    
        if not self.isEmpty:
            n = self.front
            self.front = self.front.next
            self._size -= 1
            print("Dequeued Item = ", n.item)
            return n
        else:
            return None

    def showQueue(self):
        """ Prints all items in the Queue """
        if not self.isEmpty:
            n = self.front;
            for i in range (0, self.size):
                print("%d " % n.item, end="<- ")             
                n = n.next
        print("NULL ")

    def clearQueue(self):
        """ Print and remove all items on the Queue """
        while not self.isEmpty:
            self.dequeue()

if __name__ == "__main__":
    print ("Implementation of Stack in Python using Linkedlists")
    stack = Stack()

    if stack.isEmpty:
        print("Stack is empty!")

    for i in range (1,6):
        stack.push(i)
    stack.showStack()

    n = stack.pop()    
    stack.showStack()

    stack.purgeStack()

    for i in range (1,12):
        stack.push(i)
    stack.showStack()

    print ("\nImplementation of Queue in Python using Linkedlists")
    queue = Queue()

    if queue.isEmpty:
        print("Queue is empty!")

    for i in range (1,6):
        queue.enqueue(i)

    queue.showQueue()

    queue.dequeue()
    queue.showQueue()

    queue.clearQueue()

    for i in range (1,12):
        queue.enqueue(i)
    queue.showQueue()

    
    
