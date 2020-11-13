#pragma once
int afr(int n) {
	int q = 1, i = 1;
	for (int i = 1; i <= n; i++) {
		q = q * i;
	}
	return q;
}