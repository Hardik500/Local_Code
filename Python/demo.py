# python3 program for power set 
  
import math; 
  
def printPowerSet(set,set_size): 
      
    # set_size of power set of a set 
    # with set_size n is (2**n -1) 
    pow_set_size = (int) (math.pow(2, set_size)); 
    counter = 0; 
    j = 0; 
      
    # Run from counter 000..0 to 111..1 
    for counter in range(0, pow_set_size): 
        for j in range(0, set_size): 
              
            # Check if jth bit in the  
            # counter is set If set then  
            # print jth element from set  
            if((counter & (1 << j)) > 0): 
                print(set[j], end = ""); 
        print(""); 
  
# Driver program to test printPowerSet 
# set = [2,4,6,10]; 
# printPowerSet(set, 4);

def insertAtBottom(stack, item):
    if isEmpty(stack):
        push(stack, item)
    else:
        temp = pop(stack)
        insertAtBottom(stack, item)
        push(stack, temp)

def reverse(stack):
    if not isEmpty(stack):
        temp = pop(stack)
        reverse(stack)
        insertAtBottom(stack, temp)

def sortStack(stack, item):
    if(isEmpty(stack) or item > stack[-1]):
        push(stack, item)
    else:
        temp = pop(stack)
        sortStack(stack, item)
        push(stack, temp)


def sort(stack):
    if not isEmpty(stack):
        temp = pop(stack)
        sort(stack)
        sortStack(stack, temp)

def createStack():
    stack = [] 
    return stack 
  
# Function to check if  
# the stack is empty 
def isEmpty( stack ): 
    return len(stack) == 0
  
# Function to push an  
# item to stack 
def push( stack, item ): 
    stack.append( item ) 
  
# Function to pop an  
# item from stack 
def pop( stack ): 
  
    # If stack is empty 
    # then error 
    if(isEmpty( stack )): 
        print("Stack Underflow ") 
        exit(1) 
  
    return stack.pop() 
  
# Function to print the stack 
def prints(stack): 
    for i in range(len(stack)-1, -1, -1): 
        print(stack[i], end = ' ') 
    print() 
  
# Driver Code 
  
stack = createStack() 
push( stack, 300 ) 
push( stack, 5 ) 
push( stack, 15 ) 
push( stack, 98 ) 
print("Original Stack ") 
prints(stack) 
  
# reverse(stack)
# print("Reveresed Stack ") 

sort(stack)
  
print("Sorted Stack ") 
prints(stack) 