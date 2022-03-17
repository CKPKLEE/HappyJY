#pragma once

#include "Item.h"

void Weapon::ShowItem(Weapon weapon) {
	cout << weapon.name << "\n";
	cout << "판매가 : " << weapon.price << "골드\n\n";
	cout << "공격력 + " << weapon.ad << endl;
	if (weapon.ap != 0) {
		cout << "주문력 + " << weapon.ap << "\n\n";
	}
	else {
		cout << "\n\n";
	}
	cout << "설명 : " << weapon.effect << "\n\n";
}

void Armor::ShowItem(Armor armor) {
	cout << armor.name << "\t타입 : ";
	switch (armor.type) {
	case '1':
		cout << "모자\n";
	case '2':
		cout << "갑옷\n";
	case '3':
		cout << "장갑\n";
	case '4':
		cout << "신발\n";
	}
	cout << "판매가 : " << armor.price << "골드\n\n";
	cout << "방어력 + " << armor.df << endl;
	if (armor.mr != 0) {
		cout << "마법저항력 + " << armor.mr << "\n";
	}
	if (armor.dodge != 0) {
		cout << "회피율 + " << armor.dodge << "\n\n";
	}
	else {
		cout << "\n\n";
	}
	cout << "설명 : " << armor.effect << "\n\n";
}
