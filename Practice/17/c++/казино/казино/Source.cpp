#include<iostream>
#include<vector>
using namespace std;

int main() {
	const int n = 37;
	int a[n];
	int x = 0, q = 0, w = 0, p = 0;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	while (1) {
		cin >> x;
		if (x < 0) {
			break;
		}
		a[x]++;
		switch (x)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 12:
		case 14:
		case 16:
		case 18:
		case 19:
		case 21:
		case 23:
		case 25:
		case 27:
		case 30:
		case 32:
		case 34:
		case 36: q++; break;
		case 0: break;
		default: w++;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > p) p = a[i];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == p) cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) cout << i << " ";
		}
		cout << endl << q << " " << w << endl;
	}
}