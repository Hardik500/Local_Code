for _ in range(int(input())):
    N,M = map(int, input().split())
    F = list(map(int, input().split()))
    P = list(map(int, input().split()))
    Fruit_Basket = dict()
    minimum_price = 10**9
    for i in range(N):
        if(F[i] not in Fruit_Basket):
            Fruit_Basket[F[i]] = P[i]
        else:
            Fruit_Basket[F[i]] += P[i]

    for value in Fruit_Basket.values():
        if(value < minimum_price):
            minimum_price = value
    print(minimum_price)