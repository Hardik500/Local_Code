for _ in range(int(input())):
    LENGTH, MAX_SUM = map(int, input().split())
    ARRAY = list(map(int, input().split()))
    WINDOW_LENGTH = 0
    first = 0
    second = 0
    SUM_TILL_NOW = 0
    FLAG = False

    for i in range(LENGTH):
        SUM_TILL_NOW += ARRAY[i]

        while(SUM_TILL_NOW > MAX_SUM):
            SUM_TILL_NOW -= ARRAY[first]
            first += 1

        if(SUM_TILL_NOW == MAX_SUM):
            FLAG = True
            break
        
    if(FLAG):
        print(first + 1, i + 1)
    else:    
        print(-1)