
def print_factorization(n):
	e = {};
	q = 0;
	for i in range(2,n//2+1):
		if ((n % i == 0) and asd(i)):
			while (n % i == 0):
				e[i]+=1;
				n = n // i;
				q = i;
		if (asd(n) and n != 1):
			e[n]+=1;
			break;
	for (auto i : e):
		if (i.second > 1):
			print (i.first, '^' ,i.second);
		else:
			cout << i.first;
		if ((n == 1 and i.first != q) or (n != 1 and i.first == q)):
			print ("*");
bool asd(n):
	if (n == 2):
		return True;
	for i in range(2, n//2+1):
		if (n % i == 0):
			return False;
	return true;


n = int(input())
print_factorization(n);