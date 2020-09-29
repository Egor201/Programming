a, b= input().split(':')
c, d= input().split(':')
a = int(a)
b = int(b)
d = int(d)
c = int(c)
if c == 00:
    c = 24
a = a * 60 + b
c = c * 60 + d
if abs(a - c) <= 15:
    print('встреча состоится')
else:
    print('встреча не состоится')
    