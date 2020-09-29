n = int(input())
b = 1
if n == 1:
    print (b)
else:
    for i in range(2,n+1):
        b = b * i
    print (b)