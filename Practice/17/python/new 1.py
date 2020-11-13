n = 37;
a = [];
x = 0; q = 0; w = 0; p = 0;
q = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
for i in range(n): 
	a[i] = 0;
while True:
	x = int(input());
    a[x]++;
    if x < 0:
	    break;
    if x != 0:
        if q.issubset(x):
            q++;
        else:
            w++;
    for i in range(n):
        if a[i] > p:
            p = a[i];
    for i in range(n):
		if a[i] == p:
            print (i + " ");
		print('\n')
    for i in range(n):
		if (a[i] == 0):
            print (i + " ");
    print ('\n', q, " ", w, '\n');