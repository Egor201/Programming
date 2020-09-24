#include<iostream>

int main() {
	int a = 2, n, q = 9;
	std::cin >> n;
	while (a < (n / 2)) {
		if (n % a == 0) {
			q = 99;
			break;
		}
		a++;
	}
	setlocale(LC_ALL, "Russian");
	if (q != 99) {
		std::cout << "Простое";
	}
	else {
		std::cout << "Составное";
	}
}