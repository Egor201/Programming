#include<iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b;
	c = a;
	b = b - 1;
	while (b != 0) {
		a = a * c;
		b = b - 1;
	}
	std::cout << a;
}