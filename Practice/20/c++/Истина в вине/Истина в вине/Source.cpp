#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
int main() {
	int x, y, q = 0, qw = 0, qwe = 0, sum = 0;
	double k, r;
	string s1, l, w;
	map <double, vector<string>> a;
	cin >> x;
	cin >> y;
	for (int i = 0; i < y; i++) {
		cin >> s1;
		cin >> k;
		cin >> l;
		k = k / stoi(l);
		a[k] = { s1, l };
	}
	for (auto c : a) {
		w = a[c.first][1];
		r = stoi(w);
		while (x >= (c.first * r) ) {
			qw++;
			x = x - c.first * r;
			q = 1;
			qwe = 1;
		}
		if (q == 1) {
			cout << a[c.first][0] << ' ' << qw << "\n";
			sum = sum + qw * r;
		}
		qw = 0;
		q = 0;
	}
	if (qwe == 1) {
		cout << sum << "\n" << x;
	}
	else {
		cout << -1;
	}
}