#pragma once

#include "Map.h"

class World
{
public:
	Map* map;
	int type; //0���� 1���� 2���� 3����
	void GoMap(Player* player, int type);
	void GoMainSquare(Player* player);
};
