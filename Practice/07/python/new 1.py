from math import *
q = int(input())
if q == 1:
    print ('введите стороны треугольника')
    a = float(input())
    b = float(input())
    c = float(input())
    p = (a + b + c)/2
    print ('S = ', sqrt(p * (p - a) * (p - b) * (p - c)))
if q == 2:
    print ('Введите координаты вершин треугольника')
    x1, y1 = (input().split(' ')) 
    x2, y2 = (input().split(' '))  
    x3, y3 = (input().split(' ')) 
    x1 = int (x1)
    x2 = int (x2)
    x3 = int (x3)
    y1 = int (y1)
    y2 = int (y2)
    y3 = int (y3)
    print ('S = ',(x1 * abs(y2 - y3) + x2 * abs(y3 - y1) + x3 * abs(y1 - y2))/2)    
if (q != 1) & (q!= 2):
    print ('ошибка ввода')