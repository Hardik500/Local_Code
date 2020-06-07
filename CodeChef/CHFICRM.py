for _ in range(int(input())):
    x = int(input())
    arr = list(map(int, input().split()))
    d = dict()
    unpaid = False

    for i in arr:
        if(i == 5):
            if(i in d):
                d[i] += 1
            else:
                d[i] = 1
        elif(i == 10):
            if(5 in d and d[5] >= 1):
                d[5] -= 1
                if(10 in d):
                    d[10] += 1
                else:
                    d[10] = 1
            else:
                unpaid = True
                print("NO")
                break
        else:
            if(10 in d and d[10] >= 1):
                d[10] -= 1
                if(15 in d):
                    d[15] += 1
                else:
                    d[15] = 1
            elif(5 in d and d[5] >= 2):
                d[5] -= 2
                if(15 in d):
                    d[15] += 1
                else:
                    d[15] = 1
            else:
                unpaid = True
                print("NO")
                break
    
    if(not unpaid):
        print("YES")