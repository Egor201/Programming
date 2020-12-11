#include<iostream>
#include<map>

using namespace std;

void print_factorization(unsigned int n);
bool asd(int n);

int main() {
	int n;
	cin >> n;
	print_factorization(n);
}

void print_factorization(unsigned int n) {
	map<int, int> e;
	int q = 0;
	for (int i = 2; i < n / 2 + 1; i++) {
		if ((n % i == 0) and asd(i)) {
			while (n % i == 0) {
				e[i]++;
				n = n / i;
				q = i;
			}
		}
		if (asd(n) && n != 1) {
			e[n]++;
			break;
		}
	}
	for (auto i : e){
		if (i.second > 1) {
			cout << i.first << '^' << i.second;
		}
		else {
			cout << i.first;
		}
		if ((n == 1 && i.first != q) || (n != 1 && i.first == q)) cout << "*";
	}
}

bool asd(int n) {
	if (n == 2)
		return true;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}