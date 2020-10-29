from array import *
n = 0;
w = 0;
j = 0;
i = 0;
q = 9;
a = '';
n = int(input());
for i in range (n):
	a = input().split();
	if a[0] == 'a' & a[4] == '5' & a[5] == '5' & a[6] == '6' & a[7] == '6' & a[8] == '1':
		print (a + " ");
		w = 1;
        a = '';
if w == 0:
	print (-1);