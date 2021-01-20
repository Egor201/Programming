#include<iostream>
#include<vector>
#include <fstream>
#include <cstdlib>
#include<string>

struct Passenger
{
	int PassengerId = 0;
	int Survived = 0;
	int Pclass = 0;
	std::string Name = "";
	enum class sex {
		male,
		female
	}sex = Passenger::sex::male;
	int Age = 0;
	int SibSp = 0;
	int Parch = 0;
	std::string Ticket = "";
	double Fare = 0;
	std::string Cabin = "";
	std::string Embarked = "";
};

Passenger Zapolnenie(std::string& Q) {
	Passenger help;
	int pos = 1;
	Q = Q + ',';
	std::string y = "";
	for (int i = 0; i < 12; i++) {
		std::string x = "";
		if (i == 3) {
			pos = Q.find(",");
			for (int j = 0; j < pos + 1; j++) {
				y = y + Q[j];
			}
			Q.erase(0, pos + 1);
			pos = Q.find(",");
		}else pos = Q.find(",");
		for (int j = 0; j < pos+1; j++) {
			x = x + Q[j];
		}
		if (i == 3) x = y + x;
		if (pos != 0) {
			x.erase(x.size()-1, 1);
			switch (i)
			{
			case 0:help.PassengerId = (std::stoi(x)); break;
			case 1:help.Survived = (std::stoi(x)); break;
			case 2:help.Pclass = (std::stoi(x)); break;
			case 3: x.erase(0, 1); x.erase(x.size()-1, 1); help.Name = x; break;
			case 4:
				if (x == "male") help.sex = Passenger::sex::male;
				else help.sex = Passenger::sex::female;
				break;
			case 5:help.Age = (std::stoi(x)); break;
			case 6:help.SibSp = (std::stoi(x)); break;
			case 7:help.Parch = (std::stoi(x)); break;
			case 8:help.Ticket = x; break;
			case 9:help.Fare = (std::stod(x)); break;
			case 10:help.Cabin = x; break;
			case 11:help.Embarked = x; break;
			}
		}
		Q.erase(0, pos+1);
	}
	return help;
}

std::istream& operator>> (std::istream& cin, std::vector<Passenger>& A) {
	std::ifstream inf("train.txt");
	Passenger P;
	inf.ignore(256, '\r');
	std::string Q;
	while (inf) {
		getline(inf, Q, '\r');
		if (Q != "") {
			P = Zapolnenie(Q);
			if (P.Pclass == 1 && P.sex == Passenger::sex::female && P.Survived == 1)A.push_back(P);
		}
	}
	return cin;
}

std::ostream& operator<< (std::ostream& out, std::vector<Passenger>& A) {
	std::ofstream outt("train1.txt");
	for (auto i : A) {
		outt << i.PassengerId << "," << i.Survived << "," << i.Pclass << "," << i.Name;
		if ((int)i.sex == 0)
			outt << ",mele";
		else 
			outt << ",femele";
		outt << "," << i.Age << "," << i.SibSp << "," << i.Parch;
		outt << "," << i.Ticket << "," << i.Fare << "," << i.Cabin << "," << i.Embarked << ";"<< std::endl;
	}
	return out;
}
bool operator> (Passenger A1, Passenger A2);
void BozoSort(std::vector <Passenger>& A);

int main() {
	std::vector<Passenger> A;
	std::cin >> A;
	BozoSort(A);
	std::cout << A;
}
bool operator> (Passenger A1, Passenger A2) {
	if (A1.Age > A2.Age)
		return true;
	else
		return false;
}
void BozoSort(std::vector <Passenger>& A) {
	int i = 0, i1 = 0, n = A.size(), po = 0;
	Passenger P;
	bool p = true;
	while (true) {
		i = 0 + rand() % n;
		i1 = i + rand() % (n - i);
		if (A[i] > A[i1]) {
			P = A[i];
			A[i] = A[i1];
			A[i1] = P;
		}
		for (int u = 0; u < (n - 1); u++) {
			if (A[u] > A[u + 1]) {
				p = false;
				break;
			}
		}
		if (p) {
			/*for (int u = 0; u < n; u++) {
				std::cout << A[help[u]];
			}*/
			break;
		}
		p = true;
	}
}