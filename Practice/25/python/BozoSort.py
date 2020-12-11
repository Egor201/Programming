import math    
import random

# def BozoSort(a1, n1, b = True):
	# i = 0; i1 = 0; i2 = 0; i12 = 0;
	# p = True;
	# while (True): 
		# i = random.randint(0, int(n1)-1);
		# i2 = i % int(math.sqrt(n1));
		# i = i // int(math.sqrt(n1));
		# i1 = random.randint(0, int(n1)-1);
		# i12 = i1 % int(math.sqrt(n1));
		# i1 = i1 // int(math.sqrt(n1));
		# if (b):
			# if ((i > i1 or (i == i1 and i2 >= i12)) and a1[i][i2] < a1[i1][i12]):
				# a1[i][i2] = a1[i][i2] + a1[i1][i12];
				# a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				# a1[i][i2] = a1[i][i2] - a1[i1][i12];
			# else:
				# if ((i < i1 or (i == i1 and i2 <= i12)) and a1[i][i2] > a1[i1][i12]):
					# a1[i][i2] = a1[i][i2] + a1[i1][i12];
					# a1[i1][i12] = a1[i][i2] - a1[i1][i12];
					# a1[i][i2] = a1[i][i2] - a1[i1][i12];
			# for u in range(int (math.sqrt(n1))):
				# for u1 in range(int (math.sqrt(n1))):
					# if (u1 == int(math.sqrt(n1))-1):
						# if ((u+1)*(u1+1) < int(n1)) and (a1[u + 1][0] < a1[u][u1]):
							# p = False;
							# break;
					# else:
						# if (a1[u][u1] > a1[u][u1 + 1]):
							# p = False;
							# break;
				# if (not p): 
					# break;
		# else:
			# if ((i > i1 or (i == i1 and i2 >= i12)) and a1[i][i2] > a1[i1][i12]):
				# a1[i][i2] = a1[i][i2] + a1[i1][i12];
				# a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				# a1[i][i2] = a1[i][i2] - a1[i1][i12];
			# else: 
				# if ((i < i1 or (i == i1 and i2 <= i12)) and a1[i][i2] < a1[i1][i12]):
					# a1[i][i2] = a1[i][i2] + a1[i1][i12];
					# a1[i1][i12] = a1[i][i2] - a1[i1][i12];
					# a1[i][i2] = a1[i][i2] - a1[i1][i12];
			# for u in range (int (math.sqrt(n1))):
				# for u1 in range (int (math.sqrt(n1))):
					# if (u1 == int(math.sqrt(n1))-1):
						# if ((u+1)*(u1+1) < int(n1)) and (a1[u + 1][0] > a1[u][u1]):
							# p = False;
							# break;
					# else:
						# if (a1[u][u1] < a1[u][u1 + 1]):
							# p = False;
							# break;
				# if (not p):
					# break;
		# if (p):
			# for r in range (int (math.sqrt(n1))):
				# for j in range (int (math.sqrt(n1))):
					# print (a1[r][j], end = ' ');
			# break;
		# p = True;


# def BozoSort(a11, a12, a13, b = True):
	# i = 0; i1 = 0;
	# a1 = [a11,a12,a13 ];
	# p = True;
	# while (True):
		# i = random.randint(0, 2);
		# i1 = random.randint(0, 2);
		# if (b):
			# if (i >= i1 and a1[i] < a1[i1]):
				# a1[i] = a1[i] + a1[i1];
				# a1[i1] = a1[i] - a1[i1];
				# a1[i] = a1[i] - a1[i1];
			# else:
				# if (i < i1 and a1[i] > a1[i1]):
					# a1[i] = a1[i] + a1[i1];
					# a1[i1] = a1[i] - a1[i1];
					# a1[i] = a1[i] - a1[i1];
			# for u in range (2):
				# if (a1[u] > a1[u + 1]):
					# p = False;
					# break;
		# else:
			# if (i >= i1 and a1[i] > a1[i1]):
				# a1[i] = a1[i] + a1[i1];
				# a1[i1] = a1[i] - a1[i1];
				# a1[i] = a1[i] - a1[i1];
			# else:
				# if (i < i1 and a1[i] < a1[i1]):
					# a1[i] = a1[i] + a1[i1];
					# a1[i1] = a1[i] - a1[i1];
					# a1[i] = a1[i] - a1[i1];
			# for u in range (2):
				# if (a1[u] < a1[u + 1]):
					# p = False;
					# break;
		# if (p):
			# for u in range (3):
				# print (a1[u], end = ' ')
			# break;
		# p = True;


def BozoSort(a1, n1, qwe, b = True):
    if (qwe == 1):
        i = 0; i1 = 0;
        p = True;
        while (True):
            i = random.randint (0, n1-1);
            i1 = random.randint(0, n1-1);
            if (b):
                if (i >= i1 and a1[i] < a1[i1]):
                    a1[i] = a1[i] + a1[i1];
                    a1[i1] = a1[i] - a1[i1];
                    a1[i] = a1[i] - a1[i1];
                if (i < i1 and a1[i] > a1[i1]):
                    a1[i] = a1[i] + a1[i1];
                    a1[i1] = a1[i] - a1[i1];
                    a1[i] = a1[i] - a1[i1];
                for u in range (n1-1):
                    if (a1[u] > a1[u + 1]):
                        p = False;
                        break;
            else:
                if (i >= i1 and a1[i] > a1[i1]):
                    a1[i] = a1[i] + a1[i1];
                    a1[i1] = a1[i] - a1[i1];
                    a1[i] = a1[i] - a1[i1];
                else:
                    if (i < i1 and a1[i] < a1[i1]):
                        a1[i] = a1[i] + a1[i1];
                        a1[i1] = a1[i] - a1[i1];
                        a1[i] = a1[i] - a1[i1];
                for u in range(n1-1):
                    if (a1[u] < a1[u + 1]):
                        p = False;
                        break;
            if (p):
                for u in range(n1):
                    print (a1[u], end = ' ');
                break;
            p = True;
    if (qwe == 2):
        i = 0; i1 = 0; i2 = 0; i12 = 0;
        p = True;
        while (True): 
            i = random.randint(0, int(n1)-1);
            i2 = i % int(math.sqrt(n1));
            i = i // int(math.sqrt(n1));
            i1 = random.randint(0, int(n1)-1);
            i12 = i1 % int(math.sqrt(n1));
            i1 = i1 // int(math.sqrt(n1));
            if (b):
                if ((i > i1 or (i == i1 and i2 >= i12)) and a1[i][i2] < a1[i1][i12]):
                    a1[i][i2] = a1[i][i2] + a1[i1][i12];
                    a1[i1][i12] = a1[i][i2] - a1[i1][i12];
                    a1[i][i2] = a1[i][i2] - a1[i1][i12];
                else:
                    if ((i < i1 or (i == i1 and i2 <= i12)) and a1[i][i2] > a1[i1][i12]):
                        a1[i][i2] = a1[i][i2] + a1[i1][i12];
                        a1[i1][i12] = a1[i][i2] - a1[i1][i12];
                        a1[i][i2] = a1[i][i2] - a1[i1][i12];
                for u in range(int (math.sqrt(n1))):
                    for u1 in range(int (math.sqrt(n1))):
                        if (u1 == int(math.sqrt(n1))-1):
                            if ((u+1)*(u1+1) < int(n1)) and (a1[u + 1][0] < a1[u][u1]):
                                p = False;
                                break;
                        else:
                            if (a1[u][u1] > a1[u][u1 + 1]):
                                p = False;
                                break;
                    if (not p): 
                        break;
            else:
                if ((i > i1 or (i == i1 and i2 >= i12)) and a1[i][i2] > a1[i1][i12]):
                    a1[i][i2] = a1[i][i2] + a1[i1][i12];
                    a1[i1][i12] = a1[i][i2] - a1[i1][i12];
                    a1[i][i2] = a1[i][i2] - a1[i1][i12];
                else: 
                    if ((i < i1 or (i == i1 and i2 <= i12)) and a1[i][i2] < a1[i1][i12]):
                        a1[i][i2] = a1[i][i2] + a1[i1][i12];
                        a1[i1][i12] = a1[i][i2] - a1[i1][i12];
                        a1[i][i2] = a1[i][i2] - a1[i1][i12];
                for u in range (int (math.sqrt(n1))):
                    for u1 in range (int (math.sqrt(n1))):
                        if (u1 == int(math.sqrt(n1))-1):
                            if ((u+1)*(u1+1) < int(n1)) and (a1[u + 1][0] > a1[u][u1]):
                                p = False;
                                break;
                        else:
                            if (a1[u][u1] < a1[u][u1 + 1]):
                                p = False;
                                break;
                    if (not p):
                        break;
            if (p):
                for r in range (int (math.sqrt(n1))):
                    for j in range (int (math.sqrt(n1))):
                        print (a1[r][j], end = ' ');
                break;
            p = True;
    if (qwe == 3): 
        i = 0; i1 = 0;
        
        p = True;
        while (True):
            i = random.randint(0, 2);
            i1 = random.randint(0, 2);
            if (b):
                if (i >= i1 and a1[i] < a1[i1]):
                    a1[i] = a1[i] + a1[i1];
                    a1[i1] = a1[i] - a1[i1];
                    a1[i] = a1[i] - a1[i1];
                else:
                    if (i < i1 and a1[i] > a1[i1]):
                        a1[i] = a1[i] + a1[i1];
                        a1[i1] = a1[i] - a1[i1];
                        a1[i] = a1[i] - a1[i1];
                for u in range (2):
                    if (a1[u] > a1[u + 1]):
                        p = False;
                        break;
            else:
                if (i >= i1 and a1[i] > a1[i1]):
                    a1[i] = a1[i] + a1[i1];
                    a1[i1] = a1[i] - a1[i1];
                    a1[i] = a1[i] - a1[i1];
                else:
                    if (i < i1 and a1[i] < a1[i1]):
                        a1[i] = a1[i] + a1[i1];
                        a1[i1] = a1[i] - a1[i1];
                        a1[i] = a1[i] - a1[i1];
                for u in range (2):
                    if (a1[u] < a1[u + 1]):
                        p = False;
                        break;
            if (p):
                for u in range (3):
                    print (a1[u], end = ' ')
                break;
            p = True;



a1 = [0]*100
a2 = [0] * 10, [0] * 10
q = 0
n = int (input ())
for i in range(n):
    a1[i] = int (input())
a3 = [a1[0],a1[1],a1[2]]
for i in range (int(math.sqrt(n))):
    for j in range (int(math.sqrt(n))):
        a2[i][j] = a1[q]
        q += 1 
BozoSort(a1, n, 1);
print ()
BozoSort(a1, n, 1, False);
print ()
BozoSort(a2, n, 2);
print ()
BozoSort(a2, n, 2, False);
print ()
BozoSort(a3, n, 3);
print ()
BozoSort(a3, n, 3, False);
