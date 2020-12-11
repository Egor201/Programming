a = [1000001]*5
q = 0; o = 0;
n = int(input());
for i in range(n):
    x = int(input());
    if (x < a[0]):
        o += 1;
        j = 5;
        while (j>=0):
            j -= 1;
            if (x < a[j]):
                q = j;
                break;
        for j in range(q):
            a[j] = a[j + 1];
        a[q] = x;
    if (o < 5):
        for i in range(5-o,5):
            print (a[i], end = " ")
    else:
        for i in range(5):
            print (a[i], end = " ")