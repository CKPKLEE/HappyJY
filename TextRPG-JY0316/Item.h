#pragma once

#include "MainHeader.h"
#include "Unit.h"

class Item {
public:
	int type; //0:���� 1:���� 2:���� 3:�尩 4:�Ź�
	string name;
	int price;
	string effect;
};

class Weapon : public Item {
public:
	int ad;
	int ap;
	void ShowItem(Weapon weapon);
};

class Armor : public Item {
public:
	int df;
	int mr;
	int dodge;
	void ShowItem(Armor armor);
};