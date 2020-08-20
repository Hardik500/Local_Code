def binaryCountOf(n, length):
    count = 0
    for x in range(length):
        if(n[x] == '1'):
            count += 1
    
    return count

def main():
    x = int(input())
    m = list(map(int, input().split()))

    d = dict()

    maximumOfm = max(m)

    maximumOfm = bin(maximumOfm).split("b")[1]
    length = len(maximumOfm)

    print(binaryCountOf(maximumOfm, length))

if __name__ == "__main__":
    main()