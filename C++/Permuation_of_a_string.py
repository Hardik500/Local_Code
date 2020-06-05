str = "ABC"

def permute(str, i, n):
    if(i == n):
        print(str, end=" ")
    else:
        for j in range(i, n):
            str = list(str)
            str[i], str[j] = str[j], str[i]
            str = "".join(str)

            permute(str, i + 1, n)
            
            str = list(str)
            str[i], str[j] = str[j], str[i]
            str = "".join(str)


permute(str, 0, 3)