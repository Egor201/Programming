s, l1, r1, l2, r2 = input().split(' ')
q = 0
s = int (s)
l1 = int (l1)
r1 = int (r1)   # 10 1 5 6 15
r2 = int (r2)   # 0 -2 -1 1 2
l2 = int (l2)   # 0 -4 -2 1 3
if s > (r1 + r2) | s < (l1 + l2):
    print (-1, end = '')
else:
    if (s - l1) >= l2:
        if s <= (l1 + r2):
            print (l1, s - l1, end = '')
        else: 
            q = abs (s - (l1 + r2))
            if (l1 + q) < r1 & (r2 - q) > l2:
                print (l1 + q, s - (l1 + q), end = '')
            else: 
                print (-1, end = '')            
    else:
        print (-1, end = '')
        
            