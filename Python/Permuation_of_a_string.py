str = "ABC"

def permute(string, i, n):
    if(i == n):
        print(string, end=" ")
    else:
        for j in range(i, n):
            string = list(string)
            string[i], string[j] = string[j], string[i]
            string = "".join(string)

            permute(string, i + 1, n)
            
            string = list(string)
            string[i], string[j] = string[j], string[i]
            string = "".join(string)


permute(str, 0, 3)