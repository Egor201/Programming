b = int(input());
a = int(input());
q = 0;
if a == 0:
    print (1);
else:
    if a < 0:
        q = 1;
    n = b;
    for i in range(1,abs(a)):
        n = n * b;
    if q == 1:
        print (1 / n);
    else: 
        print(n);