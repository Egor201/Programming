#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double x, y;
	char q = ' ', w = ' ';

	std::cout << "¬ведитет выражение \n";
	std::cin >> x >> q >> y;
	q = (int)(q);
	w = (int)('+');
	if (q == '+') {
		std::cout << x + y;
	}
	else {
		if (q == '-') {
			std::cout << x - y;
		}
		else {
			if (q == '*') {
				std::cout << x * y;
			}
			else {
				if (q == '/') {
					std::cout << setprecision(5) << fixed;
					std::cout << x / y;
				}
			}
		}
	}
}