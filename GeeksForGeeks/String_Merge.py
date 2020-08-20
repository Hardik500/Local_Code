def main():
    s = input()

    d = dict()

    for i in s:
        if(i in d):
            d[i] += 1
        else:
            d[i] = 1

    numOfChars = int(input())

    c = list()

    for _ in range(numOfChars):
        c.append(input())

    notdone = False

    for i in c:
        for j in i:
            if(d[j] > 0):
                d[j] -= 1
            else:
                notdone = True
                break

    if(notdone):
        print("NO")
    else:
        print("YES")


if __name__ == "__main__":
    main()
