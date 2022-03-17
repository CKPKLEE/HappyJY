#pragma once

#include "Unit.h"

void Player::MakeInfo(Player* player) {
	int getid;
	cout << ("-------------------------- ¯�� RPG --------------------------\n\n");
	cout << "������ ���� �����Ϸ��� 1, �÷��� �̷��� �ִٸ� 2 �� �Է����ּ��� : ";
	cin >> getid;

	if (getid == 1) {
		string getname;

		while (1) {
			cout << "\nȯ���մϴ�. ����� �̸��� �Է����ּ��� (�ִ� 5����) : ";
			cin.ignore();
			getline(cin, getname);

			if (getname.length() > 10) {
				cout << "�ʹ� ��ϴ�. �ٽ� �Է����ּ���\n\n";
			}
			else {
				player->name = getname;

				player->gold = 0;

				player->level = 1;
				player->exp = 0;
				player->maxHp = 100;
				player->hp = player->maxHp;
				player->maxMp = 10;
				player->mp = player->maxMp;

				player->ad = 10;
				player->ap = 0;
				player->df = 10;
				player->mr = 0;
				player->dodge = 0;  //�ű������ �⺻���� �ο�

				player->stonecount = 0; // �� ���� � ��Ҵ��� ī����
				player->stonetier10 = 0;
				player->stonetier9 = 0;
				player->stonetier8 = 0;
				player->stonetier7 = 0;
				player->stonetier6 = 0;
				player->stonetier5 = 0;
				player->stonetier4 = 0;
				player->stonetier3 = 0;
				player->stonetier2 = 0;
				player->stonetier1 = 0; // ���� Ƽ��� �� �� ��Ҵ��� ī����

				cout << "\nȯ���մϴ� " << player->name << "��.\n\n5�� �� ������ �����մϴ�.\n";
				Sleep(1000);
				cout << "\n4�� �� ������ �����մϴ�.\n";
				Sleep(1000);
				cout << "\n3�� �� ������ �����մϴ�.\n";
				Sleep(1000);
				cout << "\n2�� �� ������ �����մϴ�.\n";
				Sleep(1000);
				cout << "\n1�� �� ������ �����մϴ�.\n";
				Sleep(1000);
				break;
			}
		}
	}
	else if (getid == 2) { 
		//string���� ���ؿ�N 20L 200E 500H 200M 300D 50P 300F 300R 20G 50C 00010203040506070809
		//            name	level exp  hp   mp   ad  ap   df  mr dodge stonecount ���ڸ�����Ƽ� ����
		//���·� ���̺� ��� ���� (��ȣȭ�� ���ҷ�)
		cout << "���� �ȸ������";
		exit(0);
	}

	else {
		cout << "\n�߸��� �Է°��Դϴ�. ������ �ٽ� �������ּ���.\n";
		exit(0);
	}
}

void Player::ShowPlayerInfo(Player* player) {
	cout << "--------------- �� ĳ���� ���� ---------------\n\n";
	cout << "�̸� : " << player->name << "\t���� ��� : " << player->gold << endl;
	cout << "Lv." << player->level << "\tEXP : " << player->exp << "/" << (player->level * 100) << endl;
	cout << "HP " << player->hp << "/" << player->maxHp << endl;
	cout << "MP " << player->mp << "/" << player->maxMp << endl;
	cout << "���ݷ� : " << player->ad << "\t�������� " << (int)(100 * (float)((float)player->df / (float)(player->df + 100))) << "% ����" << endl;
	cout << "�ֹ��� : " << player->ap << "\t�������� " << (int)(100 * (float)((float)player->mr / (float)(player->mr + 100))) << "% ����" << endl;
	cout << "�������ظ� " << (int)(100 * ((float)((float)player->dodge / ((float)player->dodge + 100)))) << "% Ȯ���� ȸ��\n\n";
	cout << "----------------------------------------------\n\n";
}  // ĳ���� ���� Ȯ���Լ�. �����ó� ���� üũ�� ���

void Player::FullHp(Player* player) {
	player->hp = player->maxHp;
	player->mp = player->maxMp;
}

void Player::PlayerLevelUp(Player* player) {
	if (player->exp >= (player->level * 100)) {
		system("cls");
		cout << "������! ��� ������ ����մϴ�.\n";
		player->exp = (player->exp - (player->level * 100));
		player->level++;

		player->maxHp += 10;
		player->maxMp += 5;

		player->ad += 5;
		player->ap += 1;
		player->df += 1;
		player->mr += 1;
		player->dodge += 1;

		FullHp(player);
	}
} // ���� ���� �� ����ġ ȹ�� �� �������ߴ��� üũ

void Player::PlayerDie(Player* player) { 
	if (player->hp < 1) {
		cout << "�������� �й��߽��ϴ�. ��� ������ 1 �Ұ� 5���� ������ ���ư��ϴ�.\n";
		
		player->maxHp -= 1;
		player->maxMp -= 1;

		player->ad -= 1;
		player->ap -= 1;
		player->df -= 1;
		player->mr -= 1;
		player->dodge -= 1;
		
		player->hp = player->maxHp;
		player->mp = player->maxMp;

		Sleep(5000);
		system("cls");
	}
} // ������ ������ ���������� �׾����� üũ;

void Player::GetStone(Player* player, Stone* stone) {
	player->maxHp += stone->maxHp;
	player->maxMp += stone->maxMp;

	player->ad += stone->ad;
	player->ap += stone->ap;
	player->df += stone->df;
	player->mr += stone->mr;
	player->dodge += stone->dodge;
}

void Monster::ShowMonsterInfo(Monster* monster) {
	cout << "----------------- ���� ���� ----------------\n\n";
	cout << "�̸� : " << monster->name << "\t��� : " << monster->tier << endl;
	cout << "Lv." << monster->level << endl;
	cout << "HP " << monster->hp << "/" << monster->maxHp << endl;
	cout << "MP " << monster->mp << "/" << monster->maxMp << endl;
	cout << "���ݷ� : " << monster->ad << "\t�������� " << (int)(100*(float)((float)monster->df / (float)(monster->df + 100))) << "% ����" << endl;
	cout << "�ֹ��� : " << monster->ap << "\t�������� " << (int)(100*(float)((float)monster->mr / (float)(monster->mr + 100))) << "% ����" << endl;
	cout << "�������ظ� " << (int)(100*((float)((float)monster->dodge / ((float)monster->dodge + 100)))) << "% Ȯ���� ȸ��\n\n";
	cout << "----------------------------------------------\n\n";
}  // ���� ���� Ȯ���Լ�. ������ ���

void Monster::MonsterDie(Monster* monster) {
	cout << monster->name << "��(��) óġ�߽��ϴ�." << "\n\n";
}