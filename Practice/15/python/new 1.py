import random
a = 4
x = 1
n = 0
w = 0
q = 9
while 1:
    print('Игра началась. Попробуйте отгадать число, загаданное компьютером(у вас 5 попыток)')
    n = random.randint(1, 100)
    for i in range(1,5):
        w = int(input())
        if w == n:
            print ('Поздравляю!! Вы угадали')
            q = 99
            break
        else:
            if w < n:
                print('Загаданное число больше')
            else:
                print('Загаданное число меньше')
    if q != 99:
        w = int(input())
        if w != n:
            print('Вы проиграли.Было загадано число ', n)
    print ('хотите начать сначала? 1 - Да')
    w = int(input())
    if w != 1:
        break
         
    