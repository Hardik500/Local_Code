def binconcat(a, b):
    abin = bin(a).replace("0b", "")
    bbin = bin(b).replace("0b", "")
    apb = str(abin) + str(bbin)
    bpa = str(bbin) + str(abin)
    n1 = int(apb,2)
    n2 = int(bpa, 2)
    return n1-n2

def main():
    t = int(input())
    while t:
        n = int(input())
        a = list(map(int, input().split(" ")))
        maximum = -1
        maxi = max(a)

        if(n <= 500):
            for i in range(n):
                for j in range(n):
                    maximum = max(maximum, binconcat(a[i], a[j]))
            print(maximum)
        else:
            for i in range(n):
                maximum = max(maximum, binconcat(maxi, a[i]))
            print(maximum)
        t -= 1

if __name__ == "__main__":
    main()