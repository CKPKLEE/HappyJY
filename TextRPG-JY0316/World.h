#pragma once

#include "Map.h"

class World
{
public:
	Map* map;
	int type; //0±¤Àå 1´øÀü 2»óÁ¡ 3¼÷¼Ò
	void GoMap(Player* player, int type);
	void GoMainSquare(Player* player);
};
