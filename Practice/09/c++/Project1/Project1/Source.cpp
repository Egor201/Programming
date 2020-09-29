#include<iostream>

using namespace std;
int main() {
	int a, b, c, d;
	char s = ' ';
	cin >> a >> s >> b;
	cin >> c >> s >> d;
	setlocale(LC_ALL, "Russian");
	if (c == 00) {
		c = 24;
	}
		b = a * 60 + b;
		d = c * 60 + d;
		if (abs(b - d) <= 15) {
			cout << "Встреча состоится";
		}
		else {
			cout << "Встреча не состоится";
	}
}