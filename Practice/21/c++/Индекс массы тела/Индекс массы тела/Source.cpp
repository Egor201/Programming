#include<iostream>

using namespace std;
double BMI (double weight, double height) {
	return weight / pow(height/100, 2);
}
void printBMI(double BMI) {
	if (BMI < 18.5) cout << "Underweight";
	else if (BMI < 25.0) cout << "Normal weight";
		 else if (BMI < 30.0)	cout << "Overweight";
			  else  cout << "Obesity";
}
int main() {
	double a, x;
	cin >> a >> x;
	printBMI(BMI(a, x));
}