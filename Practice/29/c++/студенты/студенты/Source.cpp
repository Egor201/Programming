#include<iostream>
#include<vector>
#include<map>
#include<string>

std::vector <int> help(10);

struct Student
{
	int S_group = 0;
	std::string S_name = "Persson Ì";
	std::map<std::string, int> S_exams;

};

void Zapolarray(Student& A, int gr, std::string name, std::vector <int> qw);

std::ostream& operator<< (std::ostream& out, Student A);

std::ostream& operator<< (std::ostream& out, std::vector<Student> A);

bool operator> (Student q, Student q1);

std::vector <int> BozoSort(std::vector<Student> A);

int main() {
	std::vector <Student> A(10);
	std::vector <int> qw(4);
	int q;
	for (int i = 0; i < 10; i++)
		help[i] = i;
	for (int i = 0; i < 10; i++) {
		q = 1 + rand() % 7;
		qw[0] = 2 + rand() % 3;
		qw[1] = 2 + rand() % 3;
		qw[2] = 2 + rand() % 3;
		qw[3] = 2 + rand() % 3;
		Zapolarray(A[i], q, " ", qw);
	}
	A[0].S_name = "Akihiko K ";
	A[1].S_name = "Carmack J ";
	A[2].S_name = "Kojiman H ";
	A[3].S_name = "Persson M ";
	A[4].S_name = "Laykova P ";
	A[5].S_name = "Baklazh E ";
	A[6].S_name = "Kristin A ";
	A[7].S_name = "Mustava D ";
	A[8].S_name = "Novikov O ";
	A[9].S_name = "Petrova M ";
	BozoSort(A);
	bool z = false;
	for (int i = 0; i < 10; i++) {
		for (auto j : A[i].S_exams)
			if (j.second == 2) {
				z = true;
				break;
			}
		if (z) break;
	}
	if (z) {
		std::cout << A;
		std::cout << "Expulsion" << std::endl;
		q = rand() % 7;
		std::cout << A[q];
	}
	else
		std::cout << "Not found";
}
// fun*/*
bool operator> (Student q, Student q1) {
	if (q.S_name > q1.S_name) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<< (std::ostream& out, std::vector<Student> A) {
	out << "+----------+-------+------+------+------+------+" << std::endl;
	out << "| Name     | Group | Math | Phys | Hist | Prog |" << std::endl;
	out << "+----------+-------+------+------+------+------+" << std::endl;
	for (int i = 0; i < 10; i++) {
		bool z = false;
		for (auto j : A[help[i]].S_exams)
			if (j.second == 2) {
				z = true;
				break;
			}
		if (z) {
			out << "|" << A[help[i]].S_name << "| ";
			out << A[help[i]].S_group << "     | ";
			for (auto i : A[help[i]].S_exams) {
				out << i.second << "    | ";
			}
			out << std::endl << "+----------+-------+------+------+------+------+" << std::endl;
		}
	}
	return out;
}

std::ostream& operator<< (std::ostream& out, Student A) {
	out << "+----------+-------+------+------+------+------+" << std::endl;
	out << "| Name     | Group | Math | Phys | Hist | Prog |" << std::endl;
	out << "+----------+-------+------+------+------+------+" << std::endl;
	out << '|' << A.S_name << "| ";
	out << A.S_group << "     | ";
	for (auto i : A.S_exams) {
		out << i.second << "    | ";
	}
	out << std::endl << "+----------+-------+------+------+------+------+" << std::endl;
	return out;
}

void Zapolarray(Student& A, int gr, std::string name, std::vector <int> qw) {
	A.S_group = gr;
	A.S_name = name;
	A.S_exams["mathematics"] = qw[0];
	A.S_exams["physics"] = qw[1];
	A.S_exams["history"] = qw[2];
	A.S_exams["programming"] = qw[3];
}

#if 1
std::vector <int> BozoSort(std::vector <Student> A) {
	int i = 0, i1 = 0, n = 10, po = 0;
	bool p = true;
	while (true) {
		i = 0 + rand() % n;
		i1 = i + rand() % (n - i);
		if (A[help[i]] > A[help[i1]]) {
			po = help[i];
			help[i] = help[i1];
			help[i1] = po;
		}
		for (int u = 0; u < (n-1); u++) {
			if (A[help[u]]>A[help[u + 1]]) {
				p = false;
				break;
			}
		}
		if (p) {
			/*for (int u = 0; u < n; u++) {
				std::cout << A[help[u]];
			}*/
			return help;
			break;
		}
		p = true;
	}
}
#endif