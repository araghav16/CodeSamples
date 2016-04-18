"""
Solutions to some popular interview questions - By Raghav Agarwal
 
---Questions:
Q. Implement a function to get the Fibonacci sequence  

Q. Find if an array include duplicates (use HashMap),

Q. Remove duplicate numbers in an array in O(n) time in place

Q. Implement Merge Sort

Q. Encode and decode a string given just a function that provide the encoding of a character.  

Q. Order numbers in an array according to number of occurrencies.
[3 4 3 4 2 1 3 4 2 4] --> [4 4 4 4 3 3 3 2 2 1]  

---Completed:
Q. Given an array of numbers, find the 2 two largest numbers in the array 

Q. Given an int array int list = {4,5,6,1,2,...} and an integer int target = 8 Write a function to return all the pairs (x, y) 
   in the integer array that x + y = target (remove the duplicate one) 
                            OR
Q. Get all the pairs in a sequence of numbers S, whose sum was some other specific number N. 
   Eg: you have S = {2, 4, 6, 1}, N = 8 -> your output should be (2, 6), because 2+6 = 8.
                            OR
Q. Write a function to find two numbers in an array whose sum is equal to a given number.  

Q. Find the nth element from the end for a given singly linkedlist.
    struct Node {
        Node* next;
        Node : next(0) {}
    }

Q. Write a function to reverse a linkedlist

"""

#O(n^2)
def sortList(mylist):
    """ Perform selection sort, from largest to smaller value """
    sortedlist = list(mylist)
    list_length = len(sortedlist)
    for i in range (0,list_length):
        for j in range (i+1, list_length):
            #print(sortedlist[i],sortedlist[j])
            if sortedlist[j] > sortedlist[i]:
                sortedlist[i], sortedlist[j] = sortedlist[j], sortedlist[i] #swap
    return sortedlist

#---------------------------------------------------------------------------------#

#Q1 - Given an array of numbers, find the 2 two largest numbers in the array 
def findTwoLargest(mylist):
    """ Prints and returns two largest numbers by sorting list from largest to smallest and returning the first two items """
    sortedlist = sortList(mylist)
   
    #return first two items as they should be largest
    print("Two Largest numbers in list", mylist,"are:", sortedlist[0],"&",sortedlist[1])
    return sortedlist[0],sortedlist[1]

#---------------------------------------------------------------------------------#

#Q2 - Write a function to return all the pairs (x, y), in the integer array that x + y = target (remove the duplicate one) 
def findTwoWhoseSumTarget(mylist, target):
    """ finds two numbers in a list whose sum is equal to a given number.  """
    sortedlist = sortList(mylist)
    pair_list = []
   
    sum = int(sortedlist[0] + sortedlist[1])
    #if target is greater than sum of the two largest numbers in list then return 
    if target > sum:  
        print("No pairs found")  
        return
    #O(n^2)
    for i in range (0, len(sortedlist)):
        for j in range (i+1, len(sortedlist)):
            sum = sortedlist[i] + sortedlist[j]
            if target == sum:
                pair = [sortedlist[i],sortedlist[j]]
                if len(pair_list) == 0:
                    pair_list.append(pair)
                else: 
                    #To avoid duplicates check if pair exists before inserting.
                    exists = 0
                    for k in range (0,len(pair_list)):
                        if pair == pair_list[k]:
                            exists = 1
                            break #pair already exists
                    if not exists: 
                        pair_list.append(pair)
                        
    print("Pairs: ",pair_list)

#---------------------------------------------------------------------------------#
class Node(object):
    def __init__(self):
        self.item     = 0
        self.next     = None

class LinkedList(object):
    def __init__(self):
        self._top  = None
        self._size = 0

    def insert(self, item):
        """ Insert an item at the end of list, and increment size """
        n = Node()
        n.item = item 
        n.next = None
      
        if(self._top == None):
            self._top = n
        else: 
           temp = self._top
           while(temp.next is not None): #iterate to end of list
               temp = temp.next
           temp.next = n   #insert item at end of list
        self._size += 1

    def printList(self):
        """ Prints all items in a linkedlist """
        temp = self._top
        print("Linkedlist: ")
        while(temp is not None):
            print(temp.item, end = ' -> ')
            temp = temp.next
        print("None")
#---------------------------------------------------------------------------------#

def returnNthElementFromtheEnd(listHead, n):
    """ Given a singly linked list, find the nth element from the end 
        Using size to check if 'count == (size -n + 1)
        Two while loops, hence Big O - Worst Case = 2.O(n) = O(n)
    """
    listSize = 0
    count = 0
    tempList = listHead

    #Get Size of linkedlist - O(n)
    while(tempList is not None):
        listSize += 1
        tempList = tempList.next

    tempList = listHead #assign templist back to top

    #Find nth Element, by checking if count equals to (size-n+1)
    while(tempList is not None):
        count += 1
        if(count == (listSize-n+1)):
            print("Nth Element from end for n = ",n ," is ", tempList.item) 
            return tempList.item
        else:
            tempList = tempList.next
                    
#---------------------------------------------------------------------------------#

def reverseLinkedlist(listhead):
    """ Reverses and returns the updated linkedlist head """
    prev = None
    current = listhead
    while current is not None:
        next = current.next
        current.next = prev
        prev = current
        current = next

    return prev
#---------------------------------------------------------------------------------#

if __name__ == "__main__":
    print("Few Problem Solving Questions")

    #Q1
    print("\nQ1")
    mylist = ['1','2','3','4']
    findTwoLargest(mylist)
    mylist = ['5.5','-7','-3.5','80']
    findTwoLargest(mylist)
    mylist = ['12','52','22','75']
    findTwoLargest(mylist)

    #Q2
    print("\nQ2", )
    target = 8
    mylist = [4,5,6,1,2,7]
    findTwoWhoseSumTarget(mylist, target)
    mylist = [4,5,6,1,2,7,9,2,7,1,2,7,11,86,4]
    findTwoWhoseSumTarget(mylist, target)
    mylist = [4,-5,3,2,-1,1,0]
    findTwoWhoseSumTarget(mylist, target)

    #Q3 - Given a singly linked list, find the nth element from the end
    print("\nQ3 - Given a singly linked list, find the nth element from the end")
    singlylinkedlist = LinkedList()
    for i in range (1,7):
        singlylinkedlist.insert(i)
    singlylinkedlist.printList()
    nthElementFromEnd = 2
    returnNthElementFromtheEnd(singlylinkedlist._top, nthElementFromEnd)
    nthElementFromEnd = singlylinkedlist._size
    returnNthElementFromtheEnd(singlylinkedlist._top, nthElementFromEnd)
    nthElementFromEnd = 1
    returnNthElementFromtheEnd(singlylinkedlist._top, nthElementFromEnd)

    #Q4 - Function to reverse a linkedlist
    print("\nQ4")
    singlylinkedlist._top = reverseLinkedlist(singlylinkedlist._top)
    singlylinkedlist.printList()
        
    print("EoF")