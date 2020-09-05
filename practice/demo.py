
def factorial(n):
    result = list()
    if(n >= 0):
        result.append(1)
        
        for i in range(1, 2*n):
            result.append(i * result[i - 1])
    

    return result


def solve(N, K, M):
    S = M
    N1 = N - K + 1

    result = factorial(N1)

    numerator = result[S + N1 - 1]

    denominator = result[S] * result[N1 - 1]

    result = (numerator/denominator) % (10**9 + 7)

    return int(result)


def main():
    T = int(input())

    for _ in range(T):
        N, K, M = map(int, input().split())
        out_ = solve(N, K, M)
        print(out_)


if __name__ == "__main__":
    main()
