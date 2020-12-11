#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, a[5], x, q = 0, o = 0;
	cin >> n;
	for (int i = 0; i < 5; i++)
		a[i] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x < a[0]) {
			o++;
			for (int j = 4; j >= 0; j--)
				if (x < a[j]) {
					q = j;
					break;
				}
			for (int j = 0; j < q; j++)
				a[j] = a[j + 1];
			a[q] = x;
		}
		if (o < 5)
			for (int i = 5 - o; i < 5; i++)
				cout << a[i] << " ";
		else
			for (int i = 0; i < 5; i++)
				cout << a[i] << " ";
	}
}