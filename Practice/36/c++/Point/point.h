#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <iostream>


enum class coord_system{
    Cartesian,
    Polar
};

class Point{

    double a1, a2;
    coord_system system;
public:
    Point(double x = 0, double y = 0, coord_system qwe = coord_system::Cartesian)
        {
            a1 = x;
            a2 = y;
            system = qwe;
        }
    double get_x (){
        if (system == coord_system::Cartesian) return a1;
        else return a1 * cos(a2);
    }
    double get_y (){
        if (system == coord_system::Cartesian) return a2;
        else return a1 * sin(a2);
    }
    double get_r (){
        if (system == coord_system::Cartesian)
            return sqrt(pow(a1, 2) + pow(a2, 2));
        else
            return a1;
    }
    double get_phi (){
        if (system == coord_system::Cartesian){
            return acos(a1/get_r());
        }
        else {
            return a2;
        }
    }
    void set_x (double i){
        if (system == coord_system::Cartesian) a1 = i;
       else {
            a1 = sqrt(pow (i, 2) + pow (get_y(), 2));
            a2 = atan(get_y() / i);
        }
    }
    void set_y (double i){
        if (system == coord_system::Cartesian) a2 = i;
        else {
            a1 =  sqrt(pow(i, 2) + pow (get_x(), 2));
            a2 = atan(get_x() / i);
        }
    }
    void set_r (double i){
        double help = get_phi();
        if (system == coord_system::Cartesian){
            a1 = i * cos(help);
            a2 = i * sin(help);
        }else a1 = i;
    }
    void set_phi (double i){
        double help = get_r();
        if (system == coord_system::Cartesian){
            a1 = help * cos(i);
            a2 = help * sin(i);
        }else a2 = i;
    }

    bool operator== (Point A){
//        if ((std::abs(A.a1 - a1) < 1e-9) && (std::abs(A.a2 - a2) < 1e-9)){
//            return true;
//        }else return false;

        return !int(std::abs(get_r() - A.get_r()) * pow(10,10)) && !int(std::abs(get_phi() - A.get_phi()) * pow(10,10));
    }
    bool operator!= (Point A){
        if (operator== (A)){
            return false;
        }else return true;
    }

    friend std::ostream& operator<< (std::ostream& out, Point point) {
        out <<"("<< point.get_x() <<"," << point.get_y() <<"), ";
        return out;
    }

    friend std::istream& operator >> (std::istream& in, Point& point) {
        char comma;
        double q, w;
        in >> comma >> q >> comma >> w >> comma;
        point.set_x(q);
        point.set_y(w);
        return in;
    }
};


#endif // POINT_H
