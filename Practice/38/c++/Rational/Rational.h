#ifndef RATIONAL_H
#define RATIONAL_H
#include<cmath>

class Rational {
public:
//    double Q;

    int a;
    int b;
//    Rational(): Q(0){
//    }
    Rational(int a = 0, int b = 1): a(a), b(b){
    }
    static int gcd(int a, int b){
//        a = std::abs(a);
//        b = std::abs(b);
        if (a == 0)
            return std::abs(b);
        return gcd(b % a, a);

    }
    bool operator== (Rational Q){
        if ((b == 0 && Q.b == 0 && a > 0 && Q.a > 0) || (b == 0 && Q.b == 0 && a < 0 && Q.a < 0))
            return true;
        if (b == 0 || Q.b == 0)
            return false;
        if (isNaN() || Q.isNaN())
            return false;
        return ((a*Q.b) == (Q.a * b));


//       if (this->b == Q.b && this->a == Q.a)
//           return true;

//       if (this->b == 0 || Q.b == 0)
//           return false;

//       if (this->a == 0 && Q.a == 0)
//           return true;

        //
//        if (this->b == Q.b &&
//            this->a == Q.a)
//            return true;

//        if (this->b == 0 || Q.b == 0)
//            return false;

//        if (this->a == 0 && Q.a == 0)
//            return true;


//        int od = this->b * Q.b;

//        int tmp_lhs = this->a * od / this->b;
//        int tmp_rhs = Q.a * od / Q.b;


//        return tmp_lhs == tmp_rhs;


//        if (this->b == 0 && Q.a == 0)
//                {
//                    return 0;
//                }
//                else
//                {
//                    if ((this->a / this->b) == (Q.a / Q.b))
//                    {
//                        return 1;
//                    }
//                    else
//                    {
//                        return 0;
//                    }
//                }

    }
    Rational operator+ (Rational Q){
        return Rational((a*Q.b + Q.a * b),(b * Q.b));
    }
    Rational operator- (Rational Q){
        return Rational((a*Q.b - Q.a * b),(b * Q.b));
    }
    Rational operator* (Rational Q){
        return Rational((a * Q.a),(b * Q.b));
    }
    Rational operator/ (Rational Q){
        return Rational((a * Q.b),(b * Q.a));
    }
    operator bool (){
        if (a == 0 && !isNaN()) return false;
        else return true;
    }
    operator double (){
        return double(a)/b;
    }
    int numerator(){
        return a;
    }
    int denominator(){
        return b;
    }
    bool isNaN(){
        return (b == 0 && a == 0);
    }
};

#endif // RATIONAL_H
