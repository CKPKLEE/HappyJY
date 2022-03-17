 #pragma once

#include "MainHeader.h"
#include "Item.h"
#include "Stone.h"

class Unit {
public:
	string name;
	int level;
	int exp;
	int hp;
	int mp;  //상태용 스텟
	int gold; //보유 골드

	int maxHp;  //전투용 스텟
	int maxMp;
	int ad;
	int ap;
	int df;  //방어력 로직 (방어력)/(방어력+100) % 감소된 물리피해
	int mr;  //마법저항력 로직 (마저)/(마저+100) % 감소된 물리피해
	int dodge; //회피율 로직 (회피율)/(회피율+100) % 확률로 회피

	//vector<Item> inventory[5];
};

class Player : public Unit {
public:
	void MakeInfo(Player* player);

	int stonecount = 0; // 총 돌을 몇개 모았는지 카운팅
	int stonetier10 = 0;
	int stonetier9 = 0;
	int stonetier8 = 0;
	int stonetier7 = 0;
	int stonetier6 = 0;
	int stonetier5 = 0;
	int stonetier4 = 0;
	int stonetier3 = 0;
	int stonetier2 = 0;
	int stonetier1 = 0; // 각각 티어별로 몇 개 모았는지 카운팅
	void ShowPlayerInfo(Player* player);
	void PlayerLevelUp(Player* player); 
	void PlayerDie(Player* player);
	void FullHp(Player* player);
	void GetStone(Player* player, Stone* stone);
	//void ShowEqpItem(Player* player);
};

class Monster : public Unit {
public:
	int tier; // 자신의 등급에 맞는 돌 드랍
	void ShowMonsterInfo(Monster* monster);
	void MonsterDie(Monster* monster);
};