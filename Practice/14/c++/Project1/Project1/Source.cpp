#include <iostream>
int main() {
	int x = 1 , n, a = 1;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0;
	}
	else {
		while (a <= n) {
			a = a * 2; 
			x++;
		}
		std::cout << x - 1;
	}
}