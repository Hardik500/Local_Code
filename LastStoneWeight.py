arr = [2, 7, 4, 1, 8, 1]

while len(arr) > 1:
    arr.sort()
    x = arr.pop()
    y = arr.pop()
    arr.append(x - y)
    print(arr)

return arr[0]
