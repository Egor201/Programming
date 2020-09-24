#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int a = 4, x = 1, n = 0, w = 0, q = 9;
	//srand();
	//RAND_MAX(100);
	setlocale(LC_ALL, "Russian");
	while (true) {
		std::cout << "Игра началась; попробуйте отгадать число, загаданное компьютером (у вас 5 попыток) \n";
		n = rand() % 100 + 1;
		while (x <= a) {
			x++;
			std::cin >> w;
			if (w == n) {
				std::cout << "Поздравляю! Вы угадали\n";
				q = 99;
				break;
			}
			else {
				if (w < n) {
					std::cout << "Загаданное число больше\n";
				}
				else {
					std::cout << "Загаданное число меньше\n";
				}
			}
		}
		if (q != 99) {
			std::cin >> w;
			if (w != n) {
				std::cout << "Вы проиграли. Было загадпнно число " << n << std::endl;
			}
		}
		std::cout << "Хотите начать сначала? \n1 - ДА\n";
		x = 1;
		std::cin >> w; //>> std::endl;
		if (w != 1) {
			break;
		}
	}
}