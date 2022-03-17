#pragma once

#include "Stone.h"

void Stone::StoneDrop(Stone* stone, int tier) {
	srand((unsigned int)time(NULL));

	stone->maxHp = 1 + rand() % tier;
	stone->maxMp = rand() % tier;
	stone->ad = rand() % tier;
	stone->ap = rand() % tier;
	stone->df = rand() % tier;
	stone->mr = rand() % tier;
	stone->dodge = rand() % tier;

	cout << "\n-----------------------------------\n\t" << tier << "등급 돌 획득!\n\n\t최대 체력 + " << stone->maxHp
		<< "\n\t최대 마나 + " << stone->maxMp << "\n\t공격력 + " << stone->ad
		<< "\n\t주문력 + " << stone->ap << "\n\t방어력 + " << stone->df
		<< "\n\t마법 저항력 + " << stone->mr << "\n\t회피율 + " << stone->dodge << 
		"\n-----------------------------------\n";
}