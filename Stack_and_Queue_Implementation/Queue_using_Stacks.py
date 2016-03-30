"""
Python implementation of Queue using stacks
By Raghav Agarwal  
"""

from Stack_and_Queue_Implementation import Stack

class Queue_S(object):
    """
     Class containing implemenation of queue using stacks
    """
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()
        self.top   = None
        self._size = self.stack1._size

    @property
    def isEmpty(self):
        """ Return True if current size is 0, False otherwise """
        return 0 == self.stack1._size

    @property
    def size(self):
        """ Return size of stack1 which holds all items """
        return self.stack1._size

    def enqueue_s(self,item):
        """" Inserts an item on top of Stack 1 """ 
        self.stack1.push(item)
     
    def dequeue_s(self):
        """ Moves all items from Stack 1 -> Stack 2, and pop the top item on Stack 2 """
        if self.stack1.isEmpty:
            return None

        for i in range (0,self.stack1.size): #Move items
            n = self.stack1.pop()
            self.stack2.push(n.item)     
        
        dequeued_item = self.stack2.pop()

        for i in range (0,self.stack2.size):
            n = self.stack2.pop()
            self.stack1.push(n.item)
        
        print("Dequeued Item = ", dequeued_item.item)
        return dequeued_item

    def showStacks(self):
        """ Prints Stack 1 and Stack 2 """
        print("Stack 1:", end=" ")
        self.stack1.showStack()
        print("Stack 2:", end=" ")      
        self.stack2.showStack()

    def showQueueS(self):
        """ Prints Stack 1 as a Queue """
        print("Queue: NULL",end=" -> ")
        if not self.stack1.isEmpty:
            n = self.stack1._top
            for i in range (0, self.stack1.size):
                print("%d" % n.item, end=" ")
                n = n.next
        
        print(" ", end="\n")

def selfTestQueueS():
    """ Function to test various methods from Queue_S class """ 
    print ("Implementation of Queue in Python using 2 Stacks")
    queue_s = Queue_S()

    if queue_s.isEmpty:
        print("Queue is Empty!")

    for i in range (1,6):  
        queue_s.enqueue_s(i)
    queue_s.showQueueS()

    print("Queue contains %d elements"% queue_s.size)
    queue_s.dequeue_s()
    print("Queue contains %d elements"% queue_s.size)
                
    queue_s.showQueueS()

    for i in range (6,26):  
        queue_s.enqueue_s(i)
    queue_s.showQueueS()
    queue_s.showStacks()
    
    if not queue_s.isEmpty:
        print("Queue contains %d elements"% queue_s.size)

if __name__ == "__main__":
    selfTestQueueS()
