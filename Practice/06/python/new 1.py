from math import *
a = float(input())
b = float(input())
c = float(input())
if a == 0 :
    if b == 0 && c == 0:
        print('так как a и b равны 0 решением уравнения может быть любое число', end = '')
    elif b == 0 && c != 0: 
        print ('уравнение не имеет не одного корня')
    else:
        print('уравнение имеет единственное решение ',c/b, end = '')
else:
    d = b * b - 4 * a * c
    if d == 0:
        print ('уравнение имеет единственное решение X =', (-b) / (2 * a), end = '')
    if d < 0:
        print ('уравнение не имеет действительных корней', end = '')
    else:
        if d != 0:
            print('x1 =', ((-b)+sqrt(d))/(2 * a))
            print('x2 =', ((-b)-sqrt(d))/(2 * a), end = '')           