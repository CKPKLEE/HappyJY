#pragma once

#include "Unit.h"
#include "Stone.h"

class Map {
public:
	virtual void GoDungeon(Player* player);
	virtual void GoStore(Player* player);
	virtual void GoHouse(Player* player);
};

class MainSquare : public Map {
public:
	MainSquare();
}; 

class Dungeon : public Map {
public:
	Dungeon();
	void GoDungeon(Player* player);
	void DungeonLevel(int level, Player* player);
};

class Store : public Map {
public:
	Store();
	void GoStore(Player* player);
};
class House : public Map {
public:
	House();
	void GoHouse(Player* player);
};
