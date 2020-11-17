#include<iostream>
#include<fstream>
#include <iomanip>
#include"json.hpp"
#include<map>

using nlohmann::json;

int main() {
	std::map <int, int> ap;
	json inq;
	std::ifstream in ("in.json");
	in >> inq;
	for (auto& i : inq) {
		if (i["completed"])
			ap[i["userId"]]++;
	}
	json outq = json::array();
	for (auto i : ap) {
		json object;
		object["task_completed"] = i.second;
		object["userId"] = i.first;
		outq.push_back(object);
	}
	std::ofstream op("out.json");
	op << std::setw(2) << outq << std::endl;
}