from math import *
from copy import deepcopy
from enum import Enum

def equal(a, b, e=1E-10):
    if -e < a - b < e: return True
    else: return False

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
        

class Vector:
    __point__: Point
    
    def __init__(self, begin = None, end = None):
        if begin == None:
            if end == None:
                self.__point__ = Point(1, 0)
            else:
                self.__point__ = end
        else:
            if end == None:
                self.__point__ = begin
            else:
                self.__point__ = Point(end.get_x() - begin.get_x(), end.get_y() - begin.get_y())

    
    def __eq__(self, Q):
        return self.__point__ == Q.__point__

    
    def __neg__(self):
        return Vector(Point(-self.__point__.get_x(), -self.__point__.get_y()))

    
    def __add__(self, Q):
        p = Point()
        p.set_x(self.__point__.get_x() + Q.__point__.get_x())
        p.set_y(self.__point__.get_y() + Q.__point__.get_y())
        
        return Vector(p)

    
    def __sub__(self, Q):
        p = Point()
        p.set_x(self.__point__.get_x() - Q.__point__.get_x())
        p.set_y(self.__point__.get_y() - Q.__point__.get_y())
        
        return Vector(p)

    
    def __mul__(self, Q):
        if type(Q) == int or type(Q) == float:
            p = Point()
            p.set_x(self.__point__.get_x() * Q)
            p.set_y(self.__point__.get_y() * Q)
            
            return Vector(p)
        else:
            return self.length() * Q.length() * cos(self.__point__.get_phi() - Q.__point__.get_phi())

    
    def length(self):
        return self.__point__.get_r()

if __name__ == '__main__':
    a = Vector(Point(1, 2))
    b = Vector(Point(-2, 0), Point(-1, 2))
    if a == b and b == a: print('Equality test passed')
    else: print('Equality test failed')

    na  = Vector(Point(-1, -2))
    ox  = Vector(Point( 1,  0))
    nox = Vector(Point(-1,  0))
    oy  = Vector(Point( 0,  1))
    noy = Vector(Point( 0, -1))
    if a == -na and na == -a and -ox == nox and -oy == noy: print('Invert test passed')
    else: print('Invert test failed')

    if ox + oy + oy == a and -ox == -a + oy + oy: print('Summation test passed')
    else: print('Summation test failed')

    if -ox + oy == oy - ox and -oy + ox == ox - oy: print('Subtraction test passed')
    else: print('Subtraction test failed')

    if (ox * 3 == ox + ox + ox and
        oy * 3 == oy + oy + oy and
        ox * (-3) == -ox - ox - ox and
        oy * (-3) == -oy - oy - oy): print('Multiplication by number test passed')
    else: print('Multiplication by number test failed')

    if (equal(ox.length(), 1) and
        equal(oy.length(), 1) and
        equal((ox * 3 + oy * 4).length(), 5)): print('Length test passed')
    else: print('Length test failed')

    if (equal(ox*ox, ox.length()**2) and
        equal(oy*oy, oy.length()**2) and
        equal((ox*3 + oy*4)*(ox*3 + oy*4), (ox*3 + oy*4).length()**2)): print('Multiplication by Vector test passed')
    else: print('Multiplication by Vector test failed')