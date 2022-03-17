#pragma once

#include "MainHeader.h"

class Stone
{
public:
	int maxHp;
	int maxMp;
	int ad;
	int ap;
	int df;
	int mr;
	int dodge; // 부여할 능력치들
	// 게임의 주 성장수단. 무한정 착용 가능한 악세사리 개념

	int tier;

	void StoneDrop(Stone* stone, int tier);
};