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

	cout << "\n-----------------------------------\n\t" << tier << "��� �� ȹ��!\n\n\t�ִ� ü�� + " << stone->maxHp
		<< "\n\t�ִ� ���� + " << stone->maxMp << "\n\t���ݷ� + " << stone->ad
		<< "\n\t�ֹ��� + " << stone->ap << "\n\t���� + " << stone->df
		<< "\n\t���� ���׷� + " << stone->mr << "\n\tȸ���� + " << stone->dodge << 
		"\n-----------------------------------\n";
}