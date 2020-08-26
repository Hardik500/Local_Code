def duplicateZeros(arr):
    n = len(arr)

    for i in range (n - 1, -1, -1):
        print(i)
        if (arr[i] == 0):
            for index in range(n - 2, i - 1, -1):
                arr[index + 1] = arr[index]

    print(arr)



arr = [0,1,7,6,0,2,0,7]
duplicateZeros(arr)