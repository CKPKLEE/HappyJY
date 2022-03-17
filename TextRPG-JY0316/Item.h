#pragma once

#include "MainHeader.h"
#include "Unit.h"

class Item {
public:
	int type; //0:¹«±â 1:¸ðÀÚ 2:°©¿Ê 3:Àå°© 4:½Å¹ß
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