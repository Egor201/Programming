#ifndef VECTOR_H
#define VECTOR_H
#include "point.h"



class Vector {
    Point end;
    Point begin;
public:
    Vector(){
        this->begin = Point(0, 0);
        this->end = Point(0, 1);
    }
    Vector(Point end)
    {
        this->begin = Point(0, 0);
        this->end = end;
    }
    Vector(Point begin, Point end)
    {
        this->begin = begin;
        this->end = end;
    }
    double operator* (Vector Q){
        return (end.get_x() - begin.get_x()) * (Q.end.get_x() - Q.begin.get_x()) +
                (end.get_y() - begin.get_y()) * (Q.end.get_y() - Q.begin.get_y());
    }
    bool operator== (Vector Q){
        if ((module_vec(Vector (begin,end)) - module_vec(Q) < 1e-9) &&
                (int) ((Vector (begin, end) * Q) / (module_vec(Vector (begin,end))*module_vec(Q))) - 1 < 1e-9){
            return true;
        }else return false;
    }
    double module_vec(Vector Q){
        return sqrt(pow (Q.end.get_x() - Q.begin.get_x(), 2) + pow (Q.end.get_y() - Q.begin.get_y(), 2));
    }
    Vector operator- (){
        return Vector (end, begin);
    }
    Vector operator+ (Vector Q){
        return Vector (Point (this->begin.get_x() + Q.begin.get_x(),this->begin.get_y() + Q.begin.get_y()),
                       Point (this->end.get_x() + Q.end.get_x(),this->end.get_y() + Q.end.get_y()));
    }
    Vector operator- (Vector Q){
        return Vector (Point (this->begin.get_x() - Q.begin.get_x(),this->begin.get_y() - Q.begin.get_y()),
                       Point (this->end.get_x() - Q.end.get_x(),this->end.get_y() - Q.end.get_y()));
    }
    Vector operator* (double Q){
        return Vector (Point (this->begin.get_x() * Q,this->begin.get_y() * Q),
                       Point (this->end.get_x() * Q,this->end.get_y() * Q));
    }
    double length (){
        return module_vec(Vector (begin,end));
    }

};


#endif // VECTOR_H
