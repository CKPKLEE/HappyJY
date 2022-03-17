#pragma once

#include "Item.h"

void Weapon::ShowItem(Weapon weapon) {
	cout << weapon.name << "\n";
	cout << "�ǸŰ� : " << weapon.price << "���\n\n";
	cout << "���ݷ� + " << weapon.ad << endl;
	if (weapon.ap != 0) {
		cout << "�ֹ��� + " << weapon.ap << "\n\n";
	}
	else {
		cout << "\n\n";
	}
	cout << "���� : " << weapon.effect << "\n\n";
}

void Armor::ShowItem(Armor armor) {
	cout << armor.name << "\tŸ�� : ";
	switch (armor.type) {
	case '1':
		cout << "����\n";
	case '2':
		cout << "����\n";
	case '3':
		cout << "�尩\n";
	case '4':
		cout << "�Ź�\n";
	}
	cout << "�ǸŰ� : " << armor.price << "���\n\n";
	cout << "���� + " << armor.df << endl;
	if (armor.mr != 0) {
		cout << "�������׷� + " << armor.mr << "\n";
	}
	if (armor.dodge != 0) {
		cout << "ȸ���� + " << armor.dodge << "\n\n";
	}
	else {
		cout << "\n\n";
	}
	cout << "���� : " << armor.effect << "\n\n";
}
