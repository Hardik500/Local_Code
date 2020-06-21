# Write your code here
 
n = int(input())
total = 0
previous = None
total_smaller = 0
stack = []
for x in input().split():
    count = 0
    num = int(x)
    while stack:
        if stack[-1][0] < num:
            count += stack.pop()[1]
        else:
            break
    
    if stack:
        if stack[-1][0] == num:
            count += stack[-1][1]
            stack[-1][1] += 1
            if len(stack)>1:
                count += 1
        else:
            count += 1
            stack.append([num,1])
    else:
        stack.append([num,1])
    total += count
    #print(stack)
print(total)