#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int a = 4, x = 1, n = 0, w = 0, q = 9;
	//srand();
	//RAND_MAX(100);
	setlocale(LC_ALL, "Russian");
	while (true) {
		std::cout << "���� ��������; ���������� �������� �����, ���������� ����������� (� ��� 5 �������) \n";
		n = rand() % 100 + 1;
		while (x <= a) {
			x++;
			std::cin >> w;
			if (w == n) {
				std::cout << "����������! �� �������\n";
				q = 99;
				break;
			}
			else {
				if (w < n) {
					std::cout << "���������� ����� ������\n";
				}
				else {
					std::cout << "���������� ����� ������\n";
				}
			}
		}
		if (q != 99) {
			std::cin >> w;
			if (w != n) {
				std::cout << "�� ���������. ���� ��������� ����� " << n << std::endl;
			}
		}
		std::cout << "������ ������ �������? \n1 - ��\n";
		x = 1;
		std::cin >> w; //>> std::endl;
		if (w != 1) {
			break;
		}
	}
}