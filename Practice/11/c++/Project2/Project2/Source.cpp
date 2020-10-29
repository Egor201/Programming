#include<iostream>

int main() {
	double a, b, c;
	int q = 0;
	std::cin >> a >> b;
	c = a;
	if (b == 0) {
		std::cout << 1;
	}
	else {
		if (b < 0) {
			q = 1;
		}
		b = abs(b);
		b = b - 1;
		while (b != 0) {
			a = a * c;
			b = b - 1;
		}
		if (q == 1)	std::cout << 1 / a;
		else std::cout << a;
	}
}