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
	int dodge; // �ο��� �ɷ�ġ��
	// ������ �� �������. ������ ���� ������ �Ǽ��縮 ����

	int tier;

	void StoneDrop(Stone* stone, int tier);
};