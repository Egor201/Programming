﻿#include <iostream>

int main()
{
	double a, b, c, x1 = 0, x2 = 0, d = 0;
	setlocale(LC_ALL, "Russian");
	std::cout << "Ввкдите коэфиценты квадратного уравнения (a, b, c) \n";
	std::cin >> a >> b >> c;
	if (a == 0) {
		x1 = (-c) / b;
		std::cout << "Так как а=0, уравнение не является квадратным. Корень линейного уравнения равен "<< x1;
	}
	else {
		d = b * b - 4 * a * c;
		if (d < 0) {
			std::cout << "Уравнение не имеет действительных корней";
		}
		else {
			if (d == 0) {
				x1 = (-b) / (2 * a);
				std::cout << "Дискриминант уравнения равен 0. корень уравнения равен " << x1;
			}
			else {
				x1 = (-b + sqrt(d)) / (2 * a);
				x2 = (-b - sqrt(d)) / (2 * a);
				std::cout << "х1 = "<< x1 << "\nх2 = " << x2;
			}
		}
	}
}
