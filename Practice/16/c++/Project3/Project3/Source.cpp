#include<iostream>
#include<vector>
using namespace std;

int main() {
	int  n, w = 0;
	const int q = 9;
	char a[q];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++) {
			cin >> a[j];
		}
		if (a[0] == 'a' && a[4] == '5' && a[5] == '5' && a[6] == '6' && a[7] == '6' && a[8] == '1') {
			for (int j = 0; j < q; j++) {
				cout << a[j];
			}
			cout << " ";
			w = 1;
		}
	}
	if (w == 0) {
		cout << -1;
	}
}