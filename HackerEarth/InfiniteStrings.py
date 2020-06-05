p = input()
x = "".join(input().split(" "))
lengthOfString = len(x)
y = int(input())
for _ in range(y):
    a = int(input())
    z = int((a + 1) / lengthOfString)
    print(lengthOfString, z)