#include <iostream>
#include <fstream>
#include "include/cpp_httplib/httplib.h"
#include "include/nlohmann/json.hpp"
#include <vector>
#include<filesystem>
#include<string>

using namespace httplib;
using json = nlohmann::json;
using namespace std;
namespace fs = std::filesystem;


const string file_name = "file.json";
const string webpage_file_name = "webhooks.html";
const string webhook_template = u8R"(
                    <div class="form-row align-items-center">
                      <div class="col">
                        <input type="text" value="	https://webhook.site/4fab2dd1-e7d4-4d95-b9b9-36883b6b7e4b" class="form-control mb-2" disabled>
                      </div>
                      <div class="col">
                        <button type="submit" name="del" value="https://webhook.site/4fab2dd1-e7d4-4d95-b9b9-36883b6b7e4b" class="btn btn-danger mb-2">�������</button>
                      </div>
                    </div>)";

void web(string& data, const string& to, const string& from)
{
	size_t find = data.find(to);
	while (find != string::npos)
	{
		data.replace(find, to.size(), from);
		find = data.find(to, find + from.size());
	}
}

json get_from_web()
{
	ifstream open_file(file_name);
	json f;

	if (open_file.is_open())
	{
		open_file >> f;
		open_file.close();
	}

	return f;
}
void save(json f)
{
	ofstream file(file_name);

	if (file.is_open())
	{
		file << f.dump(2);
		file.close();
	}
	else
	{
		cout << "������ ���� ��� ���� �������" << endl;
	}
}

string h()
{
	ifstream webpage_file(webpage_file_name);
	string webpage;
	if (webpage_file.is_open())
	{
		getline(webpage_file, webpage, '\0');
		webpage_file.close();
	}
	else return "";

	json f = get_from_web();
	if (!f["webhooks"].empty()) {
		for (int i = 0; i < f["webhooks"].size(); i++)
		{
			int use = webpage.find("{webhooks_list}") - 1;
			string templ = webhook_template;
			web(templ, "https://webhook.site/4fab2dd1-e7d4-4d95-b9b9-36883b6b7e4b", f["webhooks"][i].get<std::string>());
			webpage.insert(webpage.begin() + use, templ.begin(), templ.end());
		}
	}
	web(webpage, "{webhooks_list}", "");
	return webpage;
}

void h_get(const Request& req, Response& res)
{
	res.set_content(h(), "text/html; charset=UTF-8");
}

void h_post(const Request& req, Response& res)
{
	json f = get_from_web();
	if (req.has_param("del"))
	{
		string value = req.get_param_value("del"); 
		if (!f["webhooks"].empty())
		{
			for (auto ptr = f["webhooks"].begin(); ptr != f["webhooks"].end(); ++ptr)
			{
				if (ptr->is_string() && ptr->get<string>() == value)
				{
					f["webhooks"].erase(ptr);
					break;
				}
			}
		}
	}
	else if (req.has_param("set"))
	{
		string value = req.get_param_value("set");

		if (value == "")
		{
		}
		else
		{
			if (!f["webhooks"].empty())
			{
				bool found = false;
				for (auto ptr = f["webhooks"].begin(); ptr != f["webhooks"].end(); ++ptr)
				{
					if (ptr->is_string() && ptr->get<std::string>() == value)
					{
						found = true;
					}
				}
				if (!found) {
					f["webhooks"].push_back(value);
				}
			}
			else
			{
				f["webhooks"].push_back(value);
			}
		}
	}
	save(f);
	res.set_content(h(), "text/html; charset=UTF-8");
	std::cout << std::endl;
}

std::string str = u8R"(
{
"request": {
    "command": "",
        "original_utterance" : "ping",
        "type" : "SimpleUtterance",
})";

enum voice_mode
{
	silent_mode,
	speak_mode
};
enum skill_mode
{
	help_mode,
	exit_mode
};
json s_array = json::array();

json silent_button
{
		{"title", u8"�������"},
		{"hide", true}
};

json speak_button
{

		{"title", u8"��������"},
		{"hide", true}

};

json exit_button =
{
		{"title", u8"������"},
		{"hide", true}
};

json help_button =
{

		{"title", u8"������"},
		{"hide", true},

		{"title", u8"��������"},
		{"hide", true},

		{"title", u8"�������"},
		{"hide", true},

		{"title", u8"����� �� ������"},
		{"hide", true},

		{"title", u8"�������"},
		{"hide", true},

		{"title", u8"������� ���������"},
		{"hide", true},
};

//json get_config();
json gen_response(const std::string& text, const std::string& tts, const json& buttons, const json* session_now = nullptr, const bool end_session = false)
{
	json response = {
		{"response", {
			{"buttons", {buttons}},
			{"end_session", end_session}
		}},
		{"version", "1.0"}
	};
	if (text != "")
	{
		response["response"]["text"] = text;
	}
	if (session_now != nullptr && (*session_now)["voice_mode"] == speak_mode)//nullptr - ��������� ���� json, �� �� ��������� 0, * - �������� ���������
	{
		if (tts != "")
		{
			response["response"]["tts"] = tts;
		}
		response["response"]["buttons"].push_back(silent_button);
	}
	else if (session_now != nullptr && (*session_now)["voice_mode"] == silent_mode)
	{
		response["response"]["buttons"].push_back(speak_button);
	}
	return response;
}

void alice(const Request& req, Response& res)
{
	json request = json::parse(req.body);

	string user_id = request["session"]["application"]["application_id"];
	json response;
	json* session_now = nullptr;

	for (auto& session : s_array)
	{
		if (session["user_id"] == user_id)
		{
			session_now = &session;
			break;
		}
	}
	//����� ������

	string text;
	string tts;

	if (request["session"]["new"].get<bool>())
	{
		if (session_now == nullptr)
		{
			json session =
			{
				{"user_id", user_id},
				{"skill_mode", exit_mode},
				{"voice_mode", silent_mode},
				{"korzina", json::array()}
			};
			s_array.push_back(session);
			session_now = &s_array[s_array.size() - 1];
		}
		else
		{
			(*session_now)["skill_mode"] = exit_mode;
			(*session_now)["voice_mode"] = silent_mode;
		}

		json response = gen_response(
			text = u8"������������",
			tts = u8"���+���������",
			exit_button,
			session_now);

		res.set_content(response.dump(2), "text/json; charset=UTF-8");
		return;
	}

	if (session_now == nullptr)
	{
		json response = gen_response(
			text = u8"��������, ��������� ������",
			tts = u8"�����+���, ��������+� ��+����",
			exit_button,
			session_now,
			true);
		res.set_content(response.dump(2), "text/json; charset=UTF-8");
		return;
	}

	string command = request["request"]["command"];
	if ((*session_now)["skill_mode"] == help_mode)
	{

		if (command == u8"�������")
		{
			text = u8"������� ��� ��� ����� � � �� ���� ���������� ���� ���������.";
			tts = u8"������� ��� ��� ����� � � �� ���� ���������� ���� ���������.";
		}
		else if (command == u8"��������")
		{
			text = u8"������� ��� �������� � � ���� ���������� ��� ���� ���������";
			tts = u8"������� ��� �������� � � ���� ���������� ��� ���� ���������";
		}
		else if (command == u8"������")
		{
			text = u8"��� ��, ��� �� ������ ����������. "
				u8"� ���� ������ � �������� ��� �������� � ����� ������������.";
			tts = u8"��� ��, ��� �� ������ ����������. "
				u8"� ���� ������ � �������� ��� �������� � ����� ������������.";
		}
		else if (command == u8"�������")
		{
			text = u8"� �������, ��� �� ������ ��������� ��� ������� �� �������.\n"
				u8"����� �������� ���-��, ������� \"�������� � ������� ��� 5 ������\".\n"
				u8"����� ������� ���-��, ������� \"������� �� ������� ���\".";
			tts = u8"� �������, ��� �� ������ ��������� ��� ������� �� �������.\n"
				u8"����� �������� ���-��, ������� \"�������� � ������� ��� 5 ������\".\n"
				u8"����� ������� ���-��, ������� \"������� �� ������� ���\".";
		}
		else if (command == u8"�����")
		{
			text = u8"� ��������� ��������� ���� ������� � ����� ������� � ������ �� ����� ���������.";
			tts = u8"� ��������� ��������� ���� ������� � ����� ������� � ������ �� ����� ���������.";
		}
		else if (command == u8"������� ���������")
		{
			text = u8"� ������� ������ ����� ������� � ����� �������.";
			tts = u8"� ������� ������ ����� ������� � ����� �������.";
		}
		else if (command == u8"����� �� ������")
		{
			text = u8"������. ����� ����� ������ - �����������.";
			tts = u8"������. ����� ����� ������ - �����������.";
			(*session_now)["skill_mode"] = exit_mode;
		}
		else
		{
			text = u8"� ���� � �� ���� ��� ������.";
			tts = u8"� +���� � �� ���+� ��� ���+���.";
		}

		json response;
		if ((*session_now)["skill_mode"] == help_mode)
		{
			response = gen_response(text, tts, help_button, session_now);
		}
		else
		{
			response = gen_response(text, tts, exit_button, session_now);
		}
		res.set_content(response.dump(2), "text/json; charset=UTF-8");
	}
	else
	{
		if (command == u8"�������")
		{
			string text = u8"�����, �����";
			string tts;
			(*session_now)["voice_mode"] = silent_mode;
			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");//������� � ����� json response
		}
		else if (command == u8"��������")
		{
			string text = u8"������.";
			string tts = u8"�����+�.";
			(*session_now)["voice_mode"] = speak_mode;
			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command == u8"������")
		{
			string text =
				u8"�������� ��� �������. �������� � ��������� ��������� �����.\n"
				u8"�������. ��������� ����� ������ �������, � ��� �� �� ���������.\n"
				u8"������. ������������ � ������������ ����� ������.\n"
				u8"��������� �������. ������� ������� � ��������� ������ � ������� ������.\n"
				u8"�����. ������� ����� ������� � �������� � ���.\n"
				u8"� ��� ���������� ���������?";
			string tts =
				u8"�������� ��� �������. �������� � ��������� ��������� �����.\n"
				u8"�������. ��������� ����� ������ �������.\n"
				u8"������. ������������ � ������������ ����� ������.\n"
				u8"��������� �������. ������� �������.\n"
				u8"�����. ������� ����� �������.\n"
				u8"� ��� ���������� ���������?";
			json response = gen_response(
				text,
				tts,
				help_button,
				session_now);
			(*session_now)["skill_mode"] = help_mode;
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command == u8"�������� �������")
		{
			string text = u8"������� �����.";
			string tts = u8"�����+��� ����+�.";
			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			(*session_now).erase("cart");
			(*session_now)["cart"] = json::array();
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command == u8"��� � �������")
		{
			cout << "cart: " << (*session_now)["cart"] << std::endl;

			string text;
			string tts;

			if ((*session_now)["cart"].empty())
			{
				text = u8"�� ������ ������ ���� ������� �����.";
				tts = u8"�� ������ ������ ���� ������� �����.";
			}
			else
			{
				text = u8"�� ������ ������ � ����� �������:";
				for (auto& elem : (*session_now)["cart"])
				{
					int price = elem["price"].get<int>();

					text += "\n"
						+ elem["item"].get<std::string>()
						+ u8" ����� "
						+ to_string(price);

					if (price % 10 == 0)
					{
						text += u8" ������,";
					}
					else if (price % 10 == 1)
					{
						text += u8" �����,";
					}
					else if (price % 10 < 5 && price % 10 > 0)
					{
						text += u8" �����,";
					}
					else
					{
						text += u8" ������,";
					}
				}
				text.pop_back();
				tts = text;
			}

			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command == u8"������� ���������")
		{
			string text = u8"�������� ���!";
			string tts = u8"�����+��� ��+�!";

			json output =
			{
				{"user_id", user_id},
				{"cart", (*session_now)["cart"]}
			};

			json file = get_from_web();

			for (string link : file["webhooks"])
			{
				cout << "link " << link << endl;
				int index = link.find('/', static_cast<string>("https://").size());
				Client cli(link.substr(0, index).c_str());
				cli.Post(link.substr(index, -1).c_str(), output.dump(2), "application/json; charset=UTF-8");

			}

			(*session_now).erase("cart");
			(*session_now)["cart"] = json::array();

			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now,
				true);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command == u8"�����")
		{
			string text = "";
			string tts = "";

			size_t size = request["request"]["nlu"]["tokens"].size();
			int sum = 0;
			for (auto& cart_item : (*session_now)["cart"])
			{
				sum += cart_item["price"].get<int>();
			}
			if (sum == 0)
			{
				text = u8"� ��� � ������� ��� �������.";
				tts = u8"� ��� � ����+��� ��� ���+����.";
			}
			else
			{
				text = u8"� ����� ����� � ��� ������� �� " + std::to_string(sum);
				tts = u8"� +����� �+���� � ��� ���+���� �� " + std::to_string(sum);
				if (sum % 10 == 0)
				{
					text += u8" ������.";
					tts += u8" ����+��.";
				}
				else if (sum % 10 == 1)
				{
					text += u8" �����.";
					tts += u8" �����.";
				}
				else if (sum % 10 < 5 && sum % 10 > 0)
				{
					text += u8" �����.";
					tts += u8" ����+�.";
				}
				else
				{
					text += u8" ������.";
					tts += u8" ����+��.";
				}
			}

			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command.find(u8"�������� � �������") == 0)
		{
			size_t size = request["request"]["nlu"]["tokens"].size();
			std::string text = u8"��.";
			std::string tts = u8"��+��.";
			std::string item_name;
			int			item_price = 0;
			int			number_index = 0;
			bool			number_index_set = false;

			for (auto entity : request["request"]["nlu"]["entities"])
			{
				if (entity["type"].get<string>() == "YANDEX.NUMBER")
				{
					number_index = entity["tokens"]["start"];
					std::cout << entity["value"].type_name() << std::endl;
					int val = entity["value"];
					if (val < 0)
					{
						text = u8"�� ��� ����� ������?!";
						tts = u8"�� ��� ����� �+�����?!";
					}
					else if (val == 0)
					{
						text = u8"��������?";
						tts = u8"��������?";
					}
					else
					{
						item_price = val;
					}
					number_index_set = true;
					break;
				}
			}
			if (size == 3)
			{
				text = u8"��� ���������?";
				tts = u8"��� ���������?";
			}
			else if (!number_index_set)
			{
				text = u8"����� ����������, �������� �� ��������? �����, ������. ";
				tts = u8"����� ���+�������, ����+���� �� ����+����? ��+���, ��+����.";
			}
			else if (number_index == 3)
			{
				text = u8"����������, ������� �������� ������.";
				tts = u8"���+�������, ����+��� ����+���� ���+���.";
			}
			else
			{
				for (int i = 3; i < number_index; ++i)
				{
					item_name += request["request"]["nlu"]["tokens"][i].get<std::string>();
					item_name += " ";
				}
				item_name.pop_back();
				json item = {
					{"item",  item_name},
					{"price", item_price}
				};
				(*session_now)["cart"].push_back(item);
			}

			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);

			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else if (command.find(u8"������� �� �������") == 0)
		{
			cout << (*session_now)["cart"] << std::endl;
			size_t size = request["request"]["nlu"]["tokens"].size();

			string text;
			string tts;
			string item_name = "";

			for (int i = 3; i < size; ++i)
			{
				cout << request["request"]["nlu"]["tokens"][i].get<std::string>() << endl;
				item_name += request["request"]["nlu"]["tokens"][i].get<std::string>();
				item_name += " ";
			}
			bool found_item = false;
			int	item_index = 0;

			if (item_name == "")
			{
				text = u8"��� ����������� �������.";
				tts = u8"��� �����+������ ����+���.";
			}
			else
			{
				item_name.pop_back();
				for (auto& cart_item : (*session_now)["cart"])
				{
					if (cart_item["item"].get<std::string>() == item_name)
					{
						found_item = true;
						break;
					}
					++item_index;
				}
				if (!found_item)
				{
					text = u8"������ � ����� ������� ���";
					tts = u8"���+��� � �+���� ����+��� �+��.";
				}
				else
				{
					text = u8"����, ������!";
					tts = u8"�+���, ���+���!";
					(*session_now)["cart"].erase((*session_now)["cart"].begin() + item_index);
				}
			}
			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);
			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
		else
		{
			string text = u8"��� ��� �� �������?";
			string tts = u8"��� ��� �� �������?";

			json response = gen_response(
				text,
				tts,
				exit_button,
				session_now);

			res.set_content(response.dump(2), "text/json; charset=UTF-8");
		}
	}
}



int main()
{
	Server svr;
	svr.Get("/webhooks", h_get);
	svr.Post("/webhooks", h_post);
	svr.Post("/alice", alice);
	svr.listen("localhost", 1234);
}