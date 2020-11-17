#include <iostream>
#include <iomanip>
#include"Header2.h"
#include"Header1.h"
int main() {
	std::cout << "n		n!\n";
	for (int i = 1; i <= 10; i++) {
		std::cout << i << "		" << afr(i) << "\n";
	}
	std::cout << "\n";
	std::cout << "x		sin(x)\n";
	double x = 0, Pi = 3.1415926535;

	for (int i = 0; i <= 46; i++) {
		std::cout << std::setprecision(4) << x << "		" << sin2(x) << "\n";
		x = x + (Pi / 180);
	}
	std::cout << "\nk		C(k, 10)\n";
	for (int i = 1; i <= 10; i++) {
		std::cout << i << "		" << cox(i) << "\n";
	}
 }