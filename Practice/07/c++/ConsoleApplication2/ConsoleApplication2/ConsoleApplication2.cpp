#include <iostream>

int main()
{
	int q;
	double a, b, c, p = 0, s = 0, x1, x2, x3, y1, y2, y3;
	setlocale(LC_ALL, "Russian");
	std::cout << "Выберите команду:\n1 - Вычисление площади через стораны треугольника\n2 - Вычисление площади через координаты вершин\n";
	std::cin >> q;
	if (q == 1) {
		std::cout << "Введите длины сторон (а, в, с)\n";
		std::cin >> a >> b >> c;
		p = (a + b + c) / 3;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		std::cout << "S = " << s;
	}
	else {
		std::cout << "Введите координаты вершин треугольника\n";
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		s = (x1 * abs ((y2 - y3)) + x2 * abs((y3 - y1)) + x3 * abs((y1 - y2))) / 2;
		std::cout << "S = " << s;
	}
}