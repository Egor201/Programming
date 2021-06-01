#include <iostream>
#include "include/cpp_httplib/httplib.h"
#include "include/nlohmann/json.hpp"

using namespace httplib;
using json = nlohmann::json;


void gen_answer(const Request& req, Response& res) {
	json js = json::parse(req.body);
	std::ifstream i ("C:/Users/Admin/Desktop/Programming/coursework/server/db.json");
	json db;
	i >> db;
	json help = R"(
		[
		  {
			"ActionCode" : 0,	
			"UserId" : 0,
			"Action": false,
			"UserName" : " ",
			"NameArcticl" : " ",
			"Price" : 0
		  }
		]
		)"_json;
	json help6 = R"(
		  {
			"NameArcticl" : " ",
			"PriceInterest" : 0
		  }
		)"_json;
	json help66 = R"(
		[
		  {
			"NameArcticl" : " ",
			"PriceInterest" : 0.0
		  }
		]
		)"_json;
	json stat = R"(
		  {
			"income" : 0.0,	
			"expense" : 0.0,
			"netProfit": 0.0,
			"revenue" : 0.0,
			"purchase" : 0.0,
			"cheating" : 0.0,
			"profitability" : 0.0,
			"Plan" : 0.0,
			"Recomendation" : " "
		  }
		)"_json;
	int q = js["ActionCode"];
	int summ = 0;
	std::ofstream o("C:/Users/Admin/Desktop/Programming/coursework/server/db.json");
	switch (q)
	{
	case 1: db.push_back(js);
		
		o << db;
		//std::cout << db << "\n";
		res.set_content("ok", "text/plain");
		break;
	case 2:
		for (auto j : db) {
			if (js["UserId"] == j["UserId"]) {
				help.push_back(j);
			}
		}
		o << db;
		res.set_content(help.dump(), "text/json");
		break;
	case 3:
		for (auto j : db) {
			if (js["UserId"] != j["UserId"] && j["UserId"] != 0) {
				help.push_back(j);
			}
		}
		o << help;
		res.set_content("ok", "text/plain");
		break;
	case 4:
		o << db;
		for (auto j : db) {
			if (js["UserId"] == j["UserId"] && j["NameArcticl"] == "Z") {
				stat["purchase"] = j["Price"].get<int>();
				//std::cout << stat["purchase"];
				break;
			}
		}
		for (auto j : db) {
			if (js["UserId"] == j["UserId"]) {
				if (j["NameArcticl"] == "N") {
					stat["cheating"] = stat["purchase"].get<float>() * (1 + float(j["Price"].get<int>()) / 100);
					//std::cout << stat["cheating"];
				}
				else {
					if (j["NameArcticl"] == "P") {
						stat["Plan"] = j["Price"];
					}
					else {

						if (j["Action"].get<bool>())
							stat["income"] = stat["income"].get<float>() + j["Price"].get<int>();
						else
							stat["expense"] = stat["expense"].get<float>() + j["Price"].get<int>();
					}
				}
			}
		}
		if (stat["cheating"].get<float>() == 0) {
			res.set_content("oy", "text/plain");
		}
		else {
			//stat["expense"] = stat["expense"].get<float>() + stat["purchase"].get<float>();
			stat["income"] = stat["income"].get<float>() + stat["cheating"].get<float>();
			stat["revenue"] = stat["cheating"];
			stat["netProfit"] = stat["income"].get<float>() - stat["expense"].get<float>();
			stat["profitability"] = (stat["netProfit"].get<float>() / stat["revenue"].get<float>()) * 100;
			if (stat["Plan"] < stat["netProfit"] && stat["profitability"].get<float>() < 15) {
				stat["Recomendation"] = u8"Вы выполняете месячный план, но у вас низская рентабельность. Вам следует увеличить оборот (то есть увеличить закупки)";
			}
			else {
				if (stat["Plan"] >= stat["netProfit"] && stat["profitability"].get<float>() >= 50) {
					stat["Recomendation"] = u8"Возможные пути рещения: Сократить ЗП работникам на 15%\n Поднять процент наценки.\n Пересмотреть план на месяц";
				}
				else {
					if (stat["Plan"] >= stat["netProfit"] && stat["profitability"].get<float>() < 50 && stat["profitability"].get<float>() > 20) {
						stat["Recomendation"] = u8"Возможные пути рещения: Сократить ЗП работникам не менее, чем на 20%\n Поднять процент наценки.\n ";
					}
					else {
						if (stat["Plan"] >= stat["netProfit"] && stat["profitability"].get<float>() < 20 && stat["profitability"].get<float>() > 5) {
							stat["Recomendation"] = u8"Возможные пути рещения: Следует пересмотреть все статьи расходов и попытаться их сократить (по команде /dopStatistics вы сможете посмотреть ваши расходы в процентном соотношении) ";
						}
						else {
							if (stat["profitability"].get<float>() < 5)
								stat["Recomendation"] = u8"Извените, но вам следует серьезно подумать, что делать с вашей организацией";
						}
					}
				}
			}
			res.set_content(stat.dump(), "text/json");
		}
		break;
	case 5:
		o << help;
		for (auto j : db) {
			if (js["UserId"] == j["UserId"]) {
				help.push_back(j);
			}
		}
		res.set_content(help.dump(), "text/json");
		break;
	case 6:
		o << db;
		for (auto j : db) {
			if (js["UserId"] == j["UserId"] && !j["Action"]) {
				help.push_back(j);
				summ = summ + j["Price"].get<int>();
			}
		}
		for (auto j : help) {
			if (j["UserId"] != 0) {
				help6["NameArcticl"] = j["NameArcticl"];
				help6["PriceInterest"] = (float(j["Price"].get<int>()) * 100) / summ;
				help66.push_back(help6);
			}
		}
		res.set_content(help66.dump(), "text/json");
		break;

	case 21:
		for (auto j : db) {
			if (((js["UserId"] == j["UserId"] && js["NameArcticl"] != j["NameArcticl"]) || (js["UserId"] != j["UserId"])) && j["UserId"] != 0) {
				help.push_back(j);
			}
			
		}
		o << help;
		res.set_content("ok", "text/plain");
		break;
	default:res.set_content("aaaaa", "text/plain");
	}

};
void gen_response(const Request& req, Response& res) {

	res.set_content("Hello", "text/plain");
}

int main() {
	Server svr;
	svr.Get("/", gen_response);
	svr.Post("/tt", gen_answer);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 1234);
}