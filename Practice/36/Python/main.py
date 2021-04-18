from math import *
from copy import deepcopy
from enum import Enum


class coord_system(Enum):
    Cartesian = 1,
    Polar = 2


class Point:
    def __init__(self, a1 = 0, a2 = 0, system = coord_system.Cartesian):
        if type(a1) == str:
            p = a1.find(',')
            self.x = float(a1[1 : p].strip())
            self.y = float(a1[p+1 : -2].strip())
            return

        if (system == coord_system.Cartesian):
            self.x = a1
            self.y = a2
            return
        
        self.x = cos(a2) * a1
        self.y = sin(a2) * a1

    def __eq__(self, help):
        return type(help) == Point and (abs(self.x - help.x) < 1e-10) and (abs(self.y - help.y) < 1e-10)

    def __ne__(self, Q):
        return not self == Q

    def get_x(self):
        return self.x
        
    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y
        
    def set_y(self, y):
        self.y = y

    def get_r(self):
        return hypot(self.x, self.y)
        
    def set_r(self, r):
        phi = self.get_phi()
        self.x = cos(phi) * r
        self.y = sin(phi) * r

    def get_phi(self):
        return atan2(self.y, self.x)

    def set_phi(self, phi):
        r = self.get_r()
        self.x = cos(phi) * r
        self.y = sin(phi) * r

    def __repr__(self):
        return f"Point({self.x},{self.y}), "

    def __str__(self):
        return f"({self.x},{self.y}), "

if __name__ == '__main__':
    with open('data.txt') as file:
        original = [Point(point) for point in file.readline().split(', ')]

    simulacrum = deepcopy(original)
    for point in simulacrum:
        print(point, end='')
        point.set_x(point.get_x() + 10)
        point.set_phi(point.get_phi() + 180*pi/180)
        point.set_y(-point.get_y())
        point.set_x(-point.get_x() - 10)
        print(point)

    print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')