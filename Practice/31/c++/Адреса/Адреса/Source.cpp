#include<iostream>
#include<vector>
#include<fstream>

std::ostream& operator<< (std::ostream& out, std::vector<int> a);

int main() {
	std::vector<int> A;
	std::ofstream out("data.txt");
	for (int i = 0; i < 64; i++) {
		A.push_back(rand() % 100);
		out << A;
	}
	while (size(A) != 1) {
		A.pop_back();
		out << A;
	}
}

std::ostream& operator<< (std::ostream& out, std::vector<int> a) {
	out << size(a) << "	| ";
	for (int i = 0; i < size(a); i++) {
		out << &a[i] << " ";
	}
	out << std::endl;
	return out;
}