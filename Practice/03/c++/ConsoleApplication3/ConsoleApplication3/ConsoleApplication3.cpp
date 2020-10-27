#include <iostream>
using namespace std;
int main()
{
    //int a, b; //для данного типа     / является целочисленным делением
    // double a; int b;// для такой пары бедет выполняться вешественное деление 
    //double b; int a;// для такой пары бедет выполняться вешественное деление 
    double a, b;
    std::cin >> a >> b;
    std::cout << a + b << endl << a - b << endl << a * b << endl << a / b;
}

