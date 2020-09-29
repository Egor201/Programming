a = int(input())
q = 0
for i in range(2, (a//2)+1):
    if a % i == 0:
        q = 1
        break
if q == 1:
    print('составное')
else:
    print('простое')