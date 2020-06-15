x = [1,3,5,7,9, 14, 17]
y = [2,4,6,8,10, 11,12 ,13]
i = j = 0
z = []

while i < len(x) and j < len(y):
    if(x[i] < y[j]):
        z.append(x[i])
        i += 1
    else:
        z.append(y[j])
        j += 1

while(j<len(y)):
    z.append(y[j])
    j += 1

while(i<len(x)):
    z.append(x[i])
    i += 1

print(z)