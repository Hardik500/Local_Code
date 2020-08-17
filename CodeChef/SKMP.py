from copy import deepcopy

for _ in range(int(input())):
    s = list(input())
    p = list(input())
    for i in p:
        s.remove(i)
    s.sort()
    new = deepcopy(s)
    
    new.append(p[0])
    new = sorted(new, reverse=True)

    if p[0] not in s:
        print(''.join(s[0:len(new)-new.index(p[0])-1]) +
              ''.join(p) + ''.join(s[len(new)-new.index(p[0])-1:]))
    else:
        new_string = ''.join(s[0:s.index(p[0])]) + \
            ''.join(p) + ''.join(s[s.index(p[0]):])
        print(min(new_string, ''.join(s[0:len(
            new)-new.index(p[0])-1]) + ''.join(p) + ''.join(s[len(new)-new.index(p[0])-1:])))
