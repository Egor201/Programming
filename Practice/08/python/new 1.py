a, s, b = input().split(' ')
a = int(a)
b = int(b)
if s == '+':
    print (a + b, end = '')
elif s == '-':
    print (a - b, end = '')
elif s == '*':
    print (a * b, end = '')
elif s == '/':
    print (a / b, end = '')
else: print ('ошибка ввода ', end = '')