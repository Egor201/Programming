#include <iostream>
#include"Header2.h"
#include"Header1.h"
#define M_PI
int main() {
	std::cout << "n		n!\n";
	for (int i = 1; i <= 10; i++) {
		std::cout << i << "		" << afr(i) << "\n";
	}
	std::cout << "\n";
	std::cout << "x		sin(x)\n";
/*	double x = 0;
	for (int i = 0; i <= 46; i++) {
		std::cout << x << "		" << sin2(x) << "\n";
		x = x + (M_PI \ 180);
	}*/
	std::cout << "\nk		C(k, 10)\n";
	for (int i = 1; i <= 10; i++) {
		std::cout << i << "		" << cox(i) << "\n";
	}
 }