#include<cmath>
#include"Header.h"
#ifndef F_H
#define F_H
double sin2(double x) {
	double sum = 0, n = 0;
	for (int i = 0; i < 5; i++) {
		n = pow(x, 2 * i + 1) / afr(2 * i + 1);
		if (i % 2 == 0) sum = sum + n;
		else sum = sum - n;
	}
	return sum;
}

#endif