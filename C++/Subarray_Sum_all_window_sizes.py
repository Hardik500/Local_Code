for _ in range(int(input())):
    LENGTH, MAX_SUM = map(int, input().split())
    ARRAY = list(map(int, input().split()))
    WINDOW_LENGTH = 1
    first = 0
    second = 0
    SUM_TILL_NOW = 0
    found = False
    
    while WINDOW_LENGTH < (LENGTH):
        if not LENGTH > WINDOW_LENGTH: 
            break

        SUM_TILL_NOW = sum(ARRAY[:WINDOW_LENGTH])

        for i in range(LENGTH - WINDOW_LENGTH):
            if(i==0):
                SUM_TILL_NOW += ARRAY[i + 1]
            else:
                SUM_TILL_NOW += ARRAY[i + 1] - ARRAY[i - 1] 

            if(SUM_TILL_NOW == MAX_SUM):
                print(i - 1, i + 1)
                found = True
                break

        if(found):
            break

        WINDOW_LENGTH += 1

