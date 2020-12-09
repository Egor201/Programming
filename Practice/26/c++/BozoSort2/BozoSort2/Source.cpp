#include<iostream>
#include<vector>

using namespace std;
// для double
#if 1
void BozoSort(double a5[101], int n, bool b = true);
void BozoSort(double a11, double a12, double a13, bool b = true);
void BozoSort(double a1[10][10], double n1, bool b = true);

int main() {
	double a1[101], a11 = 0, a12 = 0, a13 = 0, a2[10][10];
	int q = 1, n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i];

	}
	double n1 = (double(n));
	for (int i = 1; i <= int(sqrt(n1)); i++)
		for (int j = 1; j <= int(sqrt(n1)); j++) {
			a2[i][j] = a1[q];
			q++;
		}
	a11 = a1[1]; a12 = a1[2]; a13 = a1[3];
#if 1
	BozoSort(a1, n);
	cout << endl;
	BozoSort(a1, n, false);
	cout << endl;
#endif // 1

#if 1
	BozoSort(a2, n1);
	cout << endl;
	BozoSort(a2, n1, false);
	cout << endl;
#endif // 1

#if 1
	BozoSort(a11, a12, a13);
	cout << endl;
	BozoSort(a11, a12, a13, false);
#endif // 0


}


#if 1
void BozoSort(double a1[10][10], double n1, bool b) {
	int i = 0, i1 = 0, i2, i12;
	bool p = true;
	while (true) {
		i = rand() % int(n1);
		i2 = i % int(sqrt(n1)) + 1;
		i = (i / int(sqrt(n1))) + 1;
		i1 = rand() % int(n1);
		i12 = i1 % int(sqrt(n1)) + 1;
		i1 = i1 / int(sqrt(n1)) + 1;
		//if (!i1) i1++;
		//if (!i) i++;
		if (b) {
			if ((i > i1 || (i == i1 && i2 >= i12)) && a1[i][i2] < a1[i1][i12]) {
				a1[i][i2] = a1[i][i2] + a1[i1][i12];
				a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				a1[i][i2] = a1[i][i2] - a1[i1][i12];
			}
			else if ((i < i1 || (i == i1 && i2 <= i12)) && a1[i][i2] > a1[i1][i12]) {
				a1[i][i2] = a1[i][i2] + a1[i1][i12];
				a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				a1[i][i2] = a1[i][i2] - a1[i1][i12];
			}
			for (int u = 1; u <= int(sqrt(n1)); u++) {
				for (int u1 = 1; u1 <= int(sqrt(n1)); u1++) {
					if (u1 == int(sqrt(n1))) {
						if ((a1[u + 1][1] < a1[u][u1]) && ((u * u1) < int(n1))) {
							p = false;
							break;
						}
					}
					else {
						if (a1[u][u1] > a1[u][u1 + 1]) {
							p = false;
							break;
						}
					}

				}
				if (!p) break;
			}
		}
		else {
			if ((i > i1 || (i == i1 && i2 >= i12)) && a1[i][i2] > a1[i1][i12]) {
				a1[i][i2] = a1[i][i2] + a1[i1][i12];
				a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				a1[i][i2] = a1[i][i2] - a1[i1][i12];
			}
			else if ((i < i1 || (i == i1 && i2 <= i12)) && a1[i][i2] < a1[i1][i12]) {
				a1[i][i2] = a1[i][i2] + a1[i1][i12];
				a1[i1][i12] = a1[i][i2] - a1[i1][i12];
				a1[i][i2] = a1[i][i2] - a1[i1][i12];
			}
			for (int u = 1; u <= int(sqrt(n1)); u++) {
				for (int u1 = 1; u1 <= int(sqrt(n1)); u1++) {
					if (u1 == int(sqrt(n1))) {
						if ((a1[u + 1][1] > a1[u][u1]) && ((u * u1) < int(n1))) {
							p = false;
							break;
						}
					}
					else {
						if (a1[u][u1] < a1[u][u1 + 1]) {
							p = false;
							break;
						}
					}

				}
				if (!p) break;
			}
		}
		if (p) {
			for (int r = 1; r <= int(sqrt(n1)); r++)
				for (int j = 1; j <= int(sqrt(n1)); j++)
					cout << a1[r][j] << " ";
			break;
		}
		p = true;
	}
}
#endif // 1


#if 1
void BozoSort(double a11, double a12, double a13, bool b) {
	int i = 0, i1 = 0;
	double a1[4] = { 0,a11,a12,a13 };
	bool p = true;
	while (true) {
		i = 1 + rand() % 3;
		i1 = 1 + rand() % 3;
		if (b) {
			if (i >= i1 && a1[i] < a1[i1]) {
				a1[i] = a1[i] + a1[i1];
				a1[i1] = a1[i] - a1[i1];
				a1[i] = a1[i] - a1[i1];
			}
			else if (i < i1 && a1[i] > a1[i1]) {
				a1[i] = a1[i] + a1[i1];
				a1[i1] = a1[i] - a1[i1];
				a1[i] = a1[i] - a1[i1];
			}
			for (int u = 1; u < 3; u++) {
				if (a1[u] > a1[u + 1]) {
					p = false;
					break;
				}
			}
		}
		else {
			if (i >= i1 && a1[i] > a1[i1]) {
				a1[i] = a1[i] + a1[i1];
				a1[i1] = a1[i] - a1[i1];
				a1[i] = a1[i] - a1[i1];
			}
			else if (i < i1 && a1[i] < a1[i1]) {
				a1[i] = a1[i] + a1[i1];
				a1[i1] = a1[i] - a1[i1];
				a1[i] = a1[i] - a1[i1];
			}
			for (int u = 1; u < 3; u++) {
				if (a1[u] < a1[u + 1]) {
					p = false;
					break;
				}
			}
		}
		if (p) {
			for (int u = 1; u <= 3; u++) {
				cout << a1[u] << " ";
			}
			break;
		}
		p = true;
	}
}
#endif // 0


#if 1
void BozoSort(double a5[101], int n, bool b) {
	int i = 0, i1 = 0;
	bool p = true;
	while (true) {
		i = 1 + rand() % n;
		i1 = 1 + rand() % n;
		if (b) {
			if (i >= i1 && a5[i] < a5[i1]) {
				a5[i] = a5[i] + a5[i1];
				a5[i1] = a5[i] - a5[i1];
				a5[i] = a5[i] - a5[i1];
			}
			else if (i < i1 && a5[i] > a5[i1]) {
				a5[i] = a5[i] + a5[i1];
				a5[i1] = a5[i] - a5[i1];
				a5[i] = a5[i] - a5[i1];
			}
			for (int u = 1; u < n; u++) {
				if (a5[u] > a5[u + 1]) {
					p = false;
					break;
				}
			}
		}
		else {
			if (i >= i1 && a5[i] > a5[i1]) {
				a5[i] = a5[i] + a5[i1];
				a5[i1] = a5[i] - a5[i1];
				a5[i] = a5[i] - a5[i1];
			}
			else if (i < i1 && a5[i] < a5[i1]) {
				a5[i] = a5[i] + a5[i1];
				a5[i1] = a5[i] - a5[i1];
				a5[i] = a5[i] - a5[i1];
			}
			for (int u = 1; u < n; u++) {
				if (a5[u] < a5[u + 1]) {
					p = false;
					break;
				}
			}
		}
		if (p) {
			for (int u = 1; u <= n; u++) {
				cout << a5[u] << " ";
			}
			break;
		}
		p = true;
	}
}


#endif // 0  

#else
	//для string
	void BozoSort(string a1[101], int n, bool b = true);
	void BozoSort(string a11, string a12, string a13, bool b = true);
	void BozoSort(string a1[10][10], double n1, bool b = true);

	int main() {
		string a1[101], a11 = "", a12 = "", a13 = "", a2[10][10];
		int q = 1, n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i];
		}
		double n1 = (double(n));
		for (int i = 1; i <= int(sqrt(n1)); i++)
			for (int j = 1; j <= int(sqrt(n1)); j++) {
				a2[i][j] = a1[q];
				q++;
			}

#if 1
		BozoSort(a1, n);
		cout << endl;
		BozoSort(a1, n, false);
		cout << endl;
#endif // 1

#if 1
		BozoSort(a2, n1);
		cout << endl;
		BozoSort(a2, n1, false);
		cout << endl;
#endif // 1

#if 1
		BozoSort(a1[1], a1[2], a1[3]);
		cout << endl;
		BozoSort(a1[1], a1[2], a1[3], false);
#endif // 0


	}


#if 1
	void BozoSort(string a1[10][10], double n1, bool b) {
		int i = 0, i1 = 0, i2, i12;
		string s1 = "";
		bool p = true;
		while (true) {
			i = rand() % int(n1);
			i2 = i % int(sqrt(n1)) + 1;
			i = (i / int(sqrt(n1))) + 1;
			i1 = rand() % int(n1);
			i12 = i1 % int(sqrt(n1)) + 1;
			i1 = i1 / int(sqrt(n1)) + 1;
			//if (!i1) i1++;
			//if (!i) i++;
			if (b) {
				if ((i > i1 || (i == i1 && i2 >= i12)) && a1[i][i2] < a1[i1][i12]) {
					s1 = a1[i][i2];
					a1[i][i2] = a1[i1][i12];
					a1[i1][i12] = s1;
				}
				else if ((i < i1 || (i == i1 && i2 <= i12)) && a1[i][i2] > a1[i1][i12]) {
					s1 = a1[i][i2];
					a1[i][i2] = a1[i1][i12];
					a1[i1][i12] = s1;
				}
				for (int u = 1; u <= int(sqrt(n1)); u++) {
					for (int u1 = 1; u1 <= int(sqrt(n1)); u1++) {
						if (u1 == int(sqrt(n1))) {
							if ((a1[u + 1][1] < a1[u][u1]) && ((u * u1) < int(n1))) {
								p = false;
								break;
							}
						}
						else {
							if (a1[u][u1] > a1[u][u1 + 1]) {
								p = false;
								break;
							}
						}

					}
					if (!p) break;
				}
			}
			else {
				if ((i > i1 || (i == i1 && i2 >= i12)) && a1[i][i2] > a1[i1][i12]) {
					s1 = a1[i][i2];
					a1[i][i2] = a1[i1][i12];
					a1[i1][i12] = s1;
				}
				else if ((i < i1 || (i == i1 && i2 <= i12)) && a1[i][i2] < a1[i1][i12]) {
					s1 = a1[i][i2];
					a1[i][i2] = a1[i1][i12];
					a1[i1][i12] = s1;
				}
				for (int u = 1; u <= int(sqrt(n1)); u++) {
					for (int u1 = 1; u1 <= int(sqrt(n1)); u1++) {
						if (u1 == int(sqrt(n1))) {
							if ((a1[u + 1][1] > a1[u][u1]) && ((u * u1) < int(n1))) {
								p = false;
								break;
							}
						}
						else {
							if (a1[u][u1] < a1[u][u1 + 1]) {
								p = false;
								break;
							}
						}

					}
					if (!p) break;
				}
			}
			if (p) {
				for (int r = 1; r <= int(sqrt(n1)); r++)
					for (int j = 1; j <= int(sqrt(n1)); j++)
						cout << a1[r][j] << " ";
				break;
			}
			p = true;
		}
	}
#endif // 1


#if 1
	void BozoSort(string a11, string a12, string a13, bool b) {
		int i = 0, i1 = 0;
		string a1[4] = { "",a11,a12,a13 }, s1 = "";
		bool p = true;
		while (true) {
			i = 1 + rand() % 3;
			i1 = 1 + rand() % 3;
			if (b) {
				if (i >= i1 && a1[i] < a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				else if (i < i1 && a1[i] > a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				for (int u = 1; u < 3; u++) {
					if (a1[u] > a1[u + 1]) {
						p = false;
						break;
					}
				}
			}
			else {
				if (i >= i1 && a1[i] > a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				else if (i < i1 && a1[i] < a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				for (int u = 1; u < 3; u++) {
					if (a1[u] < a1[u + 1]) {
						p = false;
						break;
					}
				}
			}
			if (p) {
				for (int u = 1; u <= 3; u++) {
					cout << a1[u] << " ";
				}
				break;
			}
			p = true;
		}
	}
#endif // 0


#if 1
	void BozoSort(string a1[101], int n, bool b) {
		int i = 0, i1 = 0;
		string s1 = "";
		bool p = true;
		while (true) {
			i = 1 + rand() % n;
			i1 = 1 + rand() % n;
			if (b) {
				if (i >= i1 && a1[i] < a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				else if (i < i1 && a1[i] > a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				for (int u = 1; u < n; u++) {
					if (a1[u] > a1[u + 1]) {
						p = false;
						break;
					}
				}
			}
			else {
				if (i >= i1 && a1[i] > a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				else if (i < i1 && a1[i] < a1[i1]) {
					s1 = a1[i];
					a1[i] = a1[i1];
					a1[i1] = s1;
				}
				for (int u = 1; u < n; u++) {
					if (a1[u] < a1[u + 1]) {
						p = false;
						break;
					}
				}
			}
			if (p) {
				for (int u = 1; u <= n; u++) {
					cout << a1[u] << " ";
				}
				break;
			}
			p = true;
		}
	}
#endif 
#endif