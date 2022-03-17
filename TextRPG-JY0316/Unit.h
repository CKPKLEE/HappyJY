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
	int mp;  //���¿� ����
	int gold; //���� ���

	int maxHp;  //������ ����
	int maxMp;
	int ad;
	int ap;
	int df;  //���� ���� (����)/(����+100) % ���ҵ� ��������
	int mr;  //�������׷� ���� (����)/(����+100) % ���ҵ� ��������
	int dodge; //ȸ���� ���� (ȸ����)/(ȸ����+100) % Ȯ���� ȸ��

	//vector<Item> inventory[5];
};

class Player : public Unit {
public:
	void MakeInfo(Player* player);

	int stonecount = 0; // �� ���� � ��Ҵ��� ī����
	int stonetier10 = 0;
	int stonetier9 = 0;
	int stonetier8 = 0;
	int stonetier7 = 0;
	int stonetier6 = 0;
	int stonetier5 = 0;
	int stonetier4 = 0;
	int stonetier3 = 0;
	int stonetier2 = 0;
	int stonetier1 = 0; // ���� Ƽ��� �� �� ��Ҵ��� ī����
	void ShowPlayerInfo(Player* player);
	void PlayerLevelUp(Player* player); 
	void PlayerDie(Player* player);
	void FullHp(Player* player);
	void GetStone(Player* player, Stone* stone);
	//void ShowEqpItem(Player* player);
};

class Monster : public Unit {
public:
	int tier; // �ڽ��� ��޿� �´� �� ���
	void ShowMonsterInfo(Monster* monster);
	void MonsterDie(Monster* monster);
};