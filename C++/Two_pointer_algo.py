array = [7,2,5,4,3,6,1,9,10,12]
length = len(array)
total = 0

def isPair(arr,N, X):
    first = 0
    second = N - 1
    total = 0
    sumOfBoth = arr[first] + arr[second]

    while(first < second):
        if(sumOfBoth == X):
            total += 1
            first += 1           
        
        elif(sumOfBoth > X):
            second -= 1
        else:
            first += 1

        sumOfBoth = arr[first] + arr[second]
    
    return total

array.sort();

for i in array:
    total += isPair(array, length, i)

print(total)