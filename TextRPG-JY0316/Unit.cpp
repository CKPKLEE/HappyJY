#pragma once

#include "Unit.h"

void Player::MakeInfo(Player* player) {
	int getid;
	cout << ("-------------------------- 짱돌 RPG --------------------------\n\n");
	cout << "게임을 새로 시작하려면 1, 플레이 이력이 있다면 2 를 입력해주세요 : ";
	cin >> getid;

	if (getid == 1) {
		string getname;

		while (1) {
			cout << "\n환영합니다. 당신의 이름을 입력해주세요 (최대 5글자) : ";
			cin.ignore();
			getline(cin, getname);

			if (getname.length() > 10) {
				cout << "너무 깁니다. 다시 입력해주세요\n\n";
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
				player->dodge = 0;  //신규진행시 기본스탯 부여

				player->stonecount = 0; // 총 돌을 몇개 모았는지 카운팅
				player->stonetier10 = 0;
				player->stonetier9 = 0;
				player->stonetier8 = 0;
				player->stonetier7 = 0;
				player->stonetier6 = 0;
				player->stonetier5 = 0;
				player->stonetier4 = 0;
				player->stonetier3 = 0;
				player->stonetier2 = 0;
				player->stonetier1 = 0; // 각각 티어별로 몇 개 모았는지 카운팅

				cout << "\n환영합니다 " << player->name << "님.\n\n5초 후 게임을 시작합니다.\n";
				Sleep(1000);
				cout << "\n4초 후 게임을 시작합니다.\n";
				Sleep(1000);
				cout << "\n3초 후 게임을 시작합니다.\n";
				Sleep(1000);
				cout << "\n2초 후 게임을 시작합니다.\n";
				Sleep(1000);
				cout << "\n1초 후 게임을 시작합니다.\n";
				Sleep(1000);
				break;
			}
		}
	}
	else if (getid == 2) { 
		//string으로 이준영N 20L 200E 500H 200M 300D 50P 300F 300R 20G 50C 00010203040506070809
		//            name	level exp  hp   mp   ad  ap   df  mr dodge stonecount 두자리씩각티어돌 갯수
		//형태로 세이브 기능 제공 (암호화는 안할랭)
		cout << "아직 안만들었어";
		exit(0);
	}

	else {
		cout << "\n잘못된 입력값입니다. 게임을 다시 시작해주세요.\n";
		exit(0);
	}
}

void Player::ShowPlayerInfo(Player* player) {
	cout << "--------------- 내 캐릭터 정보 ---------------\n\n";
	cout << "이름 : " << player->name << "\t보유 골드 : " << player->gold << endl;
	cout << "Lv." << player->level << "\tEXP : " << player->exp << "/" << (player->level * 100) << endl;
	cout << "HP " << player->hp << "/" << player->maxHp << endl;
	cout << "MP " << player->mp << "/" << player->maxMp << endl;
	cout << "공격력 : " << player->ad << "\t물리피해 " << (int)(100 * (float)((float)player->df / (float)(player->df + 100))) << "% 감소" << endl;
	cout << "주문력 : " << player->ap << "\t마법피해 " << (int)(100 * (float)((float)player->mr / (float)(player->mr + 100))) << "% 감소" << endl;
	cout << "물리피해를 " << (int)(100 * ((float)((float)player->dodge / ((float)player->dodge + 100)))) << "% 확률로 회피\n\n";
	cout << "----------------------------------------------\n\n";
}  // 캐릭터 스탯 확인함수. 전투시나 스탯 체크시 사용

void Player::FullHp(Player* player) {
	player->hp = player->maxHp;
	player->mp = player->maxMp;
}

void Player::PlayerLevelUp(Player* player) {
	if (player->exp >= (player->level * 100)) {
		system("cls");
		cout << "레벨업! 모든 스탯이 상승합니다.\n";
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
} // 전투 종료 후 경험치 획득 후 레벨업했는지 체크

void Player::PlayerDie(Player* player) { 
	if (player->hp < 1) {
		cout << "전투에서 패배했습니다. 모든 스탯을 1 잃고 5초후 마을로 돌아갑니다.\n";
		
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
} // 전투시 데미지 입을때마다 죽었는지 체크;

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
	cout << "----------------- 몬스터 정보 ----------------\n\n";
	cout << "이름 : " << monster->name << "\t등급 : " << monster->tier << endl;
	cout << "Lv." << monster->level << endl;
	cout << "HP " << monster->hp << "/" << monster->maxHp << endl;
	cout << "MP " << monster->mp << "/" << monster->maxMp << endl;
	cout << "공격력 : " << monster->ad << "\t물리피해 " << (int)(100*(float)((float)monster->df / (float)(monster->df + 100))) << "% 감소" << endl;
	cout << "주문력 : " << monster->ap << "\t마법피해 " << (int)(100*(float)((float)monster->mr / (float)(monster->mr + 100))) << "% 감소" << endl;
	cout << "물리피해를 " << (int)(100*((float)((float)monster->dodge / ((float)monster->dodge + 100)))) << "% 확률로 회피\n\n";
	cout << "----------------------------------------------\n\n";
}  // 몬스터 스탯 확인함수. 전투시 사용

void Monster::MonsterDie(Monster* monster) {
	cout << monster->name << "을(를) 처치했습니다." << "\n\n";
}