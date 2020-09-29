n = int(input())
a = 2
i = 1
q = 0
if n == 1:
    print(i)
    q = 1
if n == 2:
    print (2)
else:
    if q != 1:
        while a <= n:
            a = a * 2
            i = i + 1
        print(i)