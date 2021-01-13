#include<iostream>
#include<vector> 
#include<random>
#include<string>

struct Coin
{
	int count = 0;
};
struct Rune
{
	int level = 0;
	enum class element {
		FIRE,
		WATER,
		EARTH,
		AIR
	}element = element::AIR;
};
struct Weapon
{
	int damage = 0;
	int critical = 0;
	int durability = 0;
};
struct Armor
{
	int guard = 0;
	int durability = 0;
};
struct Item
{
	enum class ItemType {
		ÑOIN,
		RUNE,
		WEAPON,
		ARMOR
	};
	ItemType qwe = ItemType::ÑOIN;
	union OBED {
		Coin a{1000};
		Rune b;
		Weapon c;
		Armor d;
	};
	OBED obed;
};
typedef std::vector<Item> LootBox;
void operator<< (LootBox& x, Item y);
std::ostream& operator<< (std::ostream& out, Item x);
Item generateItem(Item A);
LootBox generateLootBox();
Item operator++ (Item q);

int main() {
	std::string s;
	LootBox Q;
	setlocale(LC_ALL, "Russian");
	while (true) {
		std::cout << "Îòêðûòü ëóòáîêñ ? Yes / No" << std::endl;
		std::cin >> s;
		if (s == "Yes" || s == "Y" || s == "y" || s == "yes") {
			Q = generateLootBox();
			for (int i = 0; i < 3; i++) {
				std::cout << Q[i] << std::endl;
			}
		}
		if (s == "No" || s == "N" || s == "n" || s == "no") {
			break;
		}
		std::cout << std::endl;
	}
}

void operator<< (LootBox& x, Item y) {
	x.push_back(y);
}

std::ostream& operator<< (std::ostream& out, Item x) {
	switch ((int)x.qwe)
	{
	case 0: out << "1000 gold"; break;
	case 1:
		switch ((int)x.obed.b.element)
		{
		case 0:
			out << "Rune of " << "FIRE " << x.obed.b.level << " lvl";
			break;
		case 1:
			out << "Rune of " << "WATER " << x.obed.b.level << " lvl";
			break;
		case 2:
			out << "Rune of " << "EARTH " << x.obed.b.level << " lvl";
			break;
		case 3:
			out << "Rune of " << "AIR " << x.obed.b.level << " lvl";
			break;
		}break;
	case 2:
		if (x.obed.c.damage == 100) {
			out << "God Killer";
		}
		else {
			out << "Demon Slayer";
		}
		break;
	case 3:
		out << "Bronezhiletka";
		break;
	}
	return out;
}

Item generateItem(Item A) {
	/*Item A;*/
	int q;
	q = rand() % 100;
	if (q < 50) {
		A.qwe = (Item::ItemType)0;
		A.obed.a.count = 1000;
	}
	else {
		if (q >= 50 && q < 64) {
			A.qwe = (Item::ItemType)1;
			A.obed.b.level = 1;
			A.obed.b.element = Rune::element::AIR;
		}
		else {
			if (q >= 64 && q <= 76) {
				A.qwe = (Item::ItemType)1;
				A.obed.b.level = 1;
				A.obed.b.element = Rune::element::WATER;
			}
			else {
				if (q >= 77 && q <= 83) {
					A.qwe = (Item::ItemType)1;
					A.obed.b.level = 1;
					A.obed.b.element = Rune::element::EARTH;
				}
				else {
					if (q >= 84 && q <= 89) {
						A.qwe = (Item::ItemType)1;
						A.obed.b.level = 1;
						A.obed.b.element = Rune::element::FIRE;
					}
					else {
						if (q >= 90 && q <= 96) {
							q = rand() % 5;
							switch (q)
							{
							case 0:
							case 1:
								A.qwe = (Item::ItemType)3;
								A.obed.d.durability = 100;
								A.obed.d.guard = 50;
								break;
							case 2:
								A.qwe = (Item::ItemType)1;
								A.obed.b.level = 5;
								A.obed.b.element = Rune::element::AIR;
								break;
							case 3:
								A.qwe = (Item::ItemType)2;
								A.obed.c.critical = 0;
								A.obed.c.damage = 100;
								A.obed.c.durability = 100;
								break;
							case 4:
								A.qwe = (Item::ItemType)2;
								A.obed.c.critical = 50;
								A.obed.c.damage = 75;
								A.obed.c.durability = 100;
								break;
							}
						}
						else {
							switch (q)
							{
							case 97:
							case 98:
								q = rand() % 20;
								if (q <= 6) {
									A.qwe = (Item::ItemType)1;
									A.obed.b.level = 5;
									A.obed.b.element = Rune::element::EARTH;
								}
								else {
									A.qwe = (Item::ItemType)1;
									A.obed.b.level = 5;
									A.obed.b.element = Rune::element::AIR;
								}
								break;
							case 99:
								q = rand() % 100;
								if (q <= 59) {
									A.qwe = (Item::ItemType)1;
									A.obed.b.level = 5;
									A.obed.b.element = Rune::element::FIRE;
								}
								else {
									if (q >= 60 && q <= 73) {
										A.qwe = (Item::ItemType)1;
										A.obed.b.level = 10;
										A.obed.b.element = Rune::element::AIR;
									}
									else {
										if (q >= 74 && q <= 86) {
											A.qwe = (Item::ItemType)1;
											A.obed.b.level = 10;
											A.obed.b.element = Rune::element::WATER;
										}
										else {
											if (q >= 87 && q <= 93) {
												A.qwe = (Item::ItemType)1;
												A.obed.b.level = 10;
												A.obed.b.element = Rune::element::EARTH;
											}
											else {
												A.qwe = (Item::ItemType)1;
												A.obed.b.level = 10;
												A.obed.b.element = Rune::element::FIRE;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return A;
}

LootBox generateLootBox() {
	LootBox B(1);
	for (int i = 1; i < 4; i++) {
		B << generateItem(B[0]);
	}
	return B;
}

Item operator++ (Item q) {
	return generateItem(q);
}