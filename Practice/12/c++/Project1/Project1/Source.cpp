#include<iostream>

int main() {
	int a, b = 1, f = 1;
	std::cin >> a;
	if (a == 1 || a == 0) {
		if (a == 1) {
			std::cout << 1;
		}
		else {
			std::cout << 0;
		}
	}
	else {

		while (b != a) {
			f = f * b;
			b++;
		}
		std::cout << f * b;
	}
}