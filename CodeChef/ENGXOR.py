for _ in range(int(input())):
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))

    for _ in range(Q):
        P = int(input())
        even_count = 0
        one_count = 0
        
        for i in range(N):
            one_count += bin(A[i]).count('1')
            if(one_count % 2):
                if(A[i] % 2 == 0 and P % 2 == 1):
                    even_count += 1
                if(A[i] % 2 == 1 and P % 2 == 0):
                    even_count += 1

        print(N - even_count, even_count)