#pragma once

#include "Map.h"
#include "Unit.h"

random_device rd;
mt19937 gen(rd());

uniform_int_distribution<int> bonus(0, 100);
uniform_int_distribution<int> atk(80, 120);

void Map::GoDungeon(Player* player) {

}

void Map::GoStore(Player* player) {

}

void Map::GoHouse(Player* player) {

}

MainSquare::MainSquare(){

}

Dungeon::Dungeon() {

}

void Dungeon::GoDungeon(Player* player) {
	int level;

	system("cls");
	cout << "던전에 진입합니다.\n\n";

	cout << "들어가고 싶은 던전의 레벨을 선택해주세요\n";
	cout << "등장하는 몬스터는 다음과 같습니다.\n\n";

	cout << "레벨 1 고블린 마을\t1. 고블린\t2. 고블린 마법사\tBOSS 고블린 족장\n\n";
	cout << "레벨 2 골렘의 사원\t1. 스톤 골렘\t2. 아이언 골렘\t\tBOSS 골렘 킹\n\n";
	cout << "레벨 3 마계\t\t1. 하급 악마\t2. 서큐버스\t\tBOSS 마왕\n\n";
	cout << "레벨 4 드래곤의 레어\t1. 레드 드래곤\t2. 블루 드래곤\t\tBOSS 골드 드래곤\n\n";

	cout << "들어가고자 하는 던전의 레벨을 입력해주세요 : ";
	cin.ignore();
	cin >> level;

	if (level == 1) {
		cout << "\n고블린 마을로 진입합니다.";
		Sleep(5000);
		system("cls");
		DungeonLevel(level, player);
	}
	else if (level == 2) {
		cout << "\n골렘의 사원으로 진입합니다.";
		Sleep(5000);
		system("cls");
		DungeonLevel(level, player);
	}
	else if (level == 3) {
		cout << "\n마계로 진입합니다.";
		Sleep(5000);
		system("cls");
		DungeonLevel(level, player);
	}
	else if (level == 4) {
		cout << "\n드래곤의 레어로 진입합니다.";
		Sleep(5000);
		system("cls");
		DungeonLevel(level, player);
	}
	else {
		cout << "\n잘못된 값을 입력하셨습니다. 5초후 광장으로 이동합니다.";
		Sleep(5000);
		system("cls");
	}
}

void Dungeon::DungeonLevel(int level, Player* player) {
	srand((unsigned int)time(NULL)); // 회피율용 랜덤값
	//레벨1던전
	if (level == 1) {
		Monster Goblin;
		Monster GoblinMage;
		Monster GoblinBoss;

		Goblin.name = "고블린";
		Goblin.level = 1;
		Goblin.tier = 1;
		Goblin.maxHp = 50;
		Goblin.hp = Goblin.maxHp;
		Goblin.maxMp = 0;
		Goblin.mp = Goblin.maxMp;
		Goblin.ad = 10;
		Goblin.ap = 0;
		Goblin.df = 10;
		Goblin.mr = 5;
		Goblin.dodge = 2;

		GoblinMage.name = "고블린 마법사";
		GoblinMage.level = 3;
		GoblinMage.tier = 2;
		GoblinMage.maxHp = 30;
		GoblinMage.hp = GoblinMage.maxHp;
		GoblinMage.maxMp = 50;
		GoblinMage.mp = GoblinMage.maxMp;
		GoblinMage.ad = 10;
		GoblinMage.ap = 10;
		GoblinMage.df = 5;
		GoblinMage.mr = 10;
		GoblinMage.dodge = 5;

		GoblinBoss.name = "고블린 족장";
		GoblinBoss.level = 5;
		GoblinBoss.tier = 3;
		GoblinBoss.maxHp = 100;
		GoblinBoss.hp = GoblinBoss.maxHp;
		GoblinBoss.maxMp = 20;
		GoblinBoss.mp = GoblinBoss.maxMp;
		GoblinBoss.ad = 30;
		GoblinBoss.ap = 30;
		GoblinBoss.df = 20;
		GoblinBoss.mr = 20;
		GoblinBoss.dodge = 10;

		cout << "--------------- 고블린 마을 ---------------\n\n";
		Stone stoneA;
		Stone stoneB;
		Stone stoneC;

		while (1) { //1-1번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				Goblin.ShowMonsterInfo(&Goblin);

				float mdg = (float)100 * ((float)Goblin.dodge / ((float)Goblin.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {

					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * Goblin.df / (Goblin.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						Goblin.hp -= (int)pdmg;
					}
					else {
						cout << Goblin.name<<"이(가) 물리피해를 회피했습니다!\n";
					}
				
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (Goblin.hp <= 0) {
						int getgold = (Goblin.level * 100) + (Goblin.level * bonus(gen));
						int getexp = (Goblin.level * 100);

						Goblin.MonsterDie(&Goblin);
						stoneA.StoneDrop(&stoneA, Goblin.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneA);
						player->stonecount++;
						player->stonetier1++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Goblin.mr / (Goblin.mr + 100));

						Goblin.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Goblin.hp <= 0) {
							int getgold = (Goblin.level * 100) + (Goblin.level * bonus(gen));
							int getexp = (Goblin.level * 100);

							Goblin.MonsterDie(&Goblin);
							stoneA.StoneDrop(&stoneA, Goblin.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneA);
							player->stonecount++;
							player->stonetier1++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
							}
						}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Goblin.df / (Goblin.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							Goblin.hp -= (int)pdmg;
						}
						else {
							cout << Goblin.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Goblin.hp <= 0) {
							int getgold = (Goblin.level * 100) + (Goblin.level * bonus(gen));
							int getexp = (Goblin.level * 100);

							Goblin.MonsterDie(&Goblin);
							stoneA.StoneDrop(&stoneA, Goblin.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);
	
							player->GetStone(player, &stoneA);
							player->stonecount++;
							player->stonetier1++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}

				float mdmg = ((float)Goblin.ad * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->df / (player->df + 100));

				float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

				if ((int)pdg < rand() % 100) {
					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
				}
				else {
					cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(2000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {  
					player->PlayerDie(player);	
					break;
				}
				system("cls");
			}
			//1-2번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				GoblinMage.ShowMonsterInfo(&GoblinMage);

				float mdg = (float)100 * ((float)GoblinMage.dodge / ((float)GoblinMage.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * GoblinMage.df / (GoblinMage.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						GoblinMage.hp -= (int)pdmg;
					}
					else {
						cout << GoblinMage.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (GoblinMage.hp <= 0) {
						int getgold = (GoblinMage.level * 100) + (GoblinMage.level * bonus(gen));
						int getexp = (GoblinMage.level * 100);

						GoblinMage.MonsterDie(&GoblinMage);
						stoneB.StoneDrop(&stoneB, GoblinMage.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier2++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GoblinMage.mr / (GoblinMage.mr + 100));

						GoblinMage.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (GoblinMage.hp <= 0) {
							int getgold = (GoblinMage.level * 100) + (GoblinMage.level * bonus(gen));
							int getexp = (GoblinMage.level * 100);

							GoblinMage.MonsterDie(&GoblinMage);
							stoneB.StoneDrop(&stoneB, GoblinMage.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier2++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GoblinMage.df / (GoblinMage.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							GoblinMage.hp -= (int)pdmg;
						}
						else {
							cout << GoblinMage.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Goblin.hp <= 0) {
							int getgold = (GoblinMage.level * 100) + (GoblinMage.level * bonus(gen));
							int getexp = (GoblinMage.level * 100);

							GoblinMage.MonsterDie(&GoblinMage);
							stoneB.StoneDrop(&stoneB, GoblinMage.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier2++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}
				
				if (GoblinMage.mp >= 10) {
					GoblinMage.mp -= 10;
					float mdmg = (float)GoblinMage.ad + (float)GoblinMage.ap + ((float)GoblinMage.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)GoblinMage.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			//1-3번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				GoblinBoss.ShowMonsterInfo(&GoblinBoss);

				float mdg = (float)100 * ((float)GoblinBoss.dodge / ((float)GoblinBoss.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * GoblinBoss.df / (GoblinBoss.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						GoblinBoss.hp -= (int)pdmg;
					}
					else {
						cout << GoblinBoss.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (GoblinBoss.hp <= 0) {
						int getgold = (GoblinBoss.level * 100) + (GoblinBoss.level * bonus(gen));
						int getexp = (GoblinBoss.level * 100);

						GoblinBoss.MonsterDie(&GoblinBoss);
						stoneC.StoneDrop(&stoneC, GoblinBoss.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneC);
						player->stonecount++;
						player->stonetier3++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GoblinBoss.mr / (GoblinBoss.mr + 100));

						GoblinBoss.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (GoblinBoss.hp <= 0) {
							int getgold = (GoblinBoss.level * 100) + (GoblinBoss.level * bonus(gen));
							int getexp = (GoblinBoss.level * 100);

							GoblinBoss.MonsterDie(&GoblinBoss);
							stoneC.StoneDrop(&stoneC, GoblinBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier3++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GoblinBoss.df / (GoblinBoss.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							GoblinBoss.hp -= (int)pdmg;
						}
						else {
							cout << GoblinBoss.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Goblin.hp <= 0) {
							int getgold = (GoblinBoss.level * 100) + (GoblinBoss.level * bonus(gen));
							int getexp = (GoblinBoss.level * 100);

							GoblinBoss.MonsterDie(&GoblinBoss);
							stoneC.StoneDrop(&stoneC, GoblinBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier3++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					Sleep(1000);
					break;
				}

				if (GoblinBoss.mp >= 10) {
					GoblinBoss.mp -= 10;
					float mdmg = GoblinBoss.ad + GoblinBoss.ap + ((float)GoblinBoss.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)GoblinBoss.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			cout << "고블린 마을 탈출!\n5초뒤 마을로 돌아갑니다.";
			Sleep(5000);
			break;
		}
	}
	//레벨2던전
	else if (level == 2) {
		Monster StoneGolem;
		Monster IronGolem;
		Monster GolemBoss;

		StoneGolem.name = "스톤 골렘";
		StoneGolem.level = 10;
		StoneGolem.tier = 4;
		StoneGolem.maxHp = 1500;
		StoneGolem.hp = StoneGolem.maxHp;
		StoneGolem.maxMp = 0;
		StoneGolem.mp = StoneGolem.maxMp;
		StoneGolem.ad = 100;
		StoneGolem.ap = 0;
		StoneGolem.df = 100;
		StoneGolem.mr = 0;
		StoneGolem.dodge = 15;

		IronGolem.name = "아이언 골렘";
		IronGolem.level = 15;
		IronGolem.tier = 5;
		IronGolem.maxHp = 3000;
		IronGolem.hp = IronGolem.maxHp;
		IronGolem.maxMp = 0;
		IronGolem.mp = IronGolem.maxMp;
		IronGolem.ad = 120;
		IronGolem.ap = 0;
		IronGolem.df = 200;
		IronGolem.mr = 0;
		IronGolem.dodge = 20;

		GolemBoss.name = "골렘 킹";
		GolemBoss.level = 20;
		GolemBoss.tier = 6;
		GolemBoss.maxHp = 5000;
		GolemBoss.hp = GolemBoss.maxHp;
		GolemBoss.maxMp = 0;
		GolemBoss.mp = GolemBoss.maxMp;
		GolemBoss.ad = 200;
		GolemBoss.ap = 0;
		GolemBoss.df = 300;
		GolemBoss.mr = 0;
		GolemBoss.dodge = 30;

		cout << "--------------- 골렘의 사원 ---------------";
		
		Stone stoneA;
		Stone stoneB;
		Stone stoneC;

		while (1) { //2-1번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				StoneGolem.ShowMonsterInfo(&StoneGolem);

				float mdg = (float)100 * ((float)StoneGolem.dodge / ((float)StoneGolem.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * StoneGolem.df / (StoneGolem.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						StoneGolem.hp -= (int)pdmg;
					}
					else {
						cout << StoneGolem.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (StoneGolem.hp <= 0) {
						int getgold = (StoneGolem.level * 100) + (StoneGolem.level * bonus(gen));
						int getexp = (StoneGolem.level * 100);

						StoneGolem.MonsterDie(&StoneGolem);
						stoneA.StoneDrop(&stoneA, StoneGolem.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneA);
						player->stonecount++;
						player->stonetier4++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * StoneGolem.mr / (StoneGolem.mr + 100));

						StoneGolem.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (StoneGolem.hp <= 0) {
							int getgold = (StoneGolem.level * 100) + (StoneGolem.level * bonus(gen));
							int getexp = (StoneGolem.level * 100);

							StoneGolem.MonsterDie(&StoneGolem);
							stoneA.StoneDrop(&stoneA, StoneGolem.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneA);
							player->stonecount++;
							player->stonetier4++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * StoneGolem.df / (StoneGolem.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							StoneGolem.hp -= (int)pdmg;
						}
						else {
							cout << StoneGolem.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (IronGolem.hp <= 0) {
							int getgold = (StoneGolem.level * 100) + (StoneGolem.level * bonus(gen));
							int getexp = (StoneGolem.level * 100);

							StoneGolem.MonsterDie(&StoneGolem);
							stoneA.StoneDrop(&stoneA, StoneGolem.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneA);
							player->stonecount++;
							player->stonetier4++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}
				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}

				if (StoneGolem.mp >= 10) {
					StoneGolem.mp -= 10;
					float mdmg = (float)StoneGolem.ad + (float)StoneGolem.ap + ((float)StoneGolem.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)StoneGolem.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			//2-2번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				IronGolem.ShowMonsterInfo(&IronGolem);

				float mdg = (float)100 * ((float)IronGolem.dodge / ((float)IronGolem.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * IronGolem.df / (IronGolem.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						IronGolem.hp -= (int)pdmg;
					}
					else {
						cout << IronGolem.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (IronGolem.hp <= 0) {
						int getgold = (IronGolem.level * 100) + (IronGolem.level * bonus(gen));
						int getexp = (IronGolem.level * 100);

						IronGolem.MonsterDie(&IronGolem);
						stoneB.StoneDrop(&stoneB, IronGolem.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier5++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * IronGolem.mr / (IronGolem.mr + 100));

						IronGolem.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (IronGolem.hp <= 0) {
							int getgold = (IronGolem.level * 100) + (IronGolem.level * bonus(gen));
							int getexp = (IronGolem.level * 100);

							IronGolem.MonsterDie(&IronGolem);
							stoneB.StoneDrop(&stoneB, IronGolem.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier5++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * IronGolem.df / (IronGolem.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							IronGolem.hp -= (int)pdmg;
						}
						else {
							cout << IronGolem.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (IronGolem.hp <= 0) {
							int getgold = (IronGolem.level * 100) + (IronGolem.level * bonus(gen));
							int getexp = (IronGolem.level * 100);

							IronGolem.MonsterDie(&IronGolem);
							stoneB.StoneDrop(&stoneB, IronGolem.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier5++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}
				// 몬스터 마법공격
				if (IronGolem.mp >= 10) {
					IronGolem.mp -= 10;
					float mdmg = (float)IronGolem.ad + (float)IronGolem.ap + ((float)IronGolem.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)IronGolem.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			//2-3번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				GolemBoss.ShowMonsterInfo(&GolemBoss);

				float mdg = (float)100 * ((float)GolemBoss.dodge / ((float)GolemBoss.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * GolemBoss.df / (GolemBoss.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						GolemBoss.hp -= (int)pdmg;
					}
					else {
						cout << GolemBoss.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (GolemBoss.hp <= 0) {
						int getgold = (GolemBoss.level * 100) + (GolemBoss.level * bonus(gen));
						int getexp = (GolemBoss.level * 100);

						GolemBoss.MonsterDie(&GolemBoss);
						stoneC.StoneDrop(&stoneC, GolemBoss.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneC);
						player->stonecount++;
						player->stonetier6++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GolemBoss.mr / (GolemBoss.mr + 100));

						GolemBoss.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (GolemBoss.hp <= 0) {
							int getgold = (GolemBoss.level * 100) + (GolemBoss.level * bonus(gen));
							int getexp = (GolemBoss.level * 100);

							GolemBoss.MonsterDie(&GolemBoss);
							stoneC.StoneDrop(&stoneC, GolemBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier6++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * GolemBoss.df / (GolemBoss.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							GolemBoss.hp -= (int)pdmg;
						}
						else {
							cout << GolemBoss.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (GolemBoss.hp <= 0) {
							int getgold = (GolemBoss.level * 100) + (GolemBoss.level * bonus(gen));
							int getexp = (GolemBoss.level * 100);

							GolemBoss.MonsterDie(&GolemBoss);
							stoneC.StoneDrop(&stoneC, GolemBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier6++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					Sleep(1000);
					break;
				}

				if (GolemBoss.mp >= 10) {
					GolemBoss.mp -= 10;
					float mdmg = (float)GolemBoss.ad + (float)GolemBoss.ap + ((float)GolemBoss.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)GolemBoss.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			cout << "골렘의 사원 클리어!\n5초뒤 마을로 돌아갑니다.";
			Sleep(5000);
			break;
		}
	}
	//레벨3던전
	else if (level == 3) {
		Monster Devil;
		Monster Succubus;
		Monster DevilBoss;

		Devil.name = "하급 악마";
		Devil.level = 25;
		Devil.tier = 7;
		Devil.maxHp = 1500;
		Devil.hp = Devil.maxHp;
		Devil.maxMp = 30;
		Devil.mp = Devil.maxMp;
		Devil.ad = 50;
		Devil.ap = 200;
		Devil.df = 50;
		Devil.mr = 200;
		Devil.dodge = 50;

		Succubus.name = "서큐버스";
		Succubus.level = 30;
		Succubus.tier = 8;
		Succubus.maxHp = 2000;
		Succubus.hp = Succubus.maxHp;
		Succubus.maxMp = 50;
		Succubus.mp = Succubus.maxMp;
		Succubus.ad = 30;
		Succubus.ap = 500;
		Succubus.df = 50;
		Succubus.mr = 500;
		Succubus.dodge = 100;

		DevilBoss.name = "마왕";
		DevilBoss.level = 45;
		DevilBoss.tier = 9;
		DevilBoss.maxHp = 5000;
		DevilBoss.hp = DevilBoss.maxHp;
		DevilBoss.maxMp = 100;
		DevilBoss.mp = DevilBoss.maxMp;
		DevilBoss.ad = 100;
		DevilBoss.ap = 700;
		DevilBoss.df = 200;
		DevilBoss.mr = 1000;
		DevilBoss.dodge = 150;

		cout << "------------------- 마계 ------------------";

		Stone stoneA;
		Stone stoneB;
		Stone stoneC;

		while (1) { //3-1번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				Devil.ShowMonsterInfo(&Devil);

				float mdg = (float)100 * ((float)Devil.dodge / ((float)Devil.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * Devil.df / (Devil.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						Devil.hp -= (int)pdmg;
					}
					else {
						cout << Devil.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (Devil.hp <= 0) {
						int getgold = (Devil.level * 100) + (Devil.level * bonus(gen));
						int getexp = (Devil.level * 100);

						Devil.MonsterDie(&Devil);
						stoneA.StoneDrop(&stoneA, Devil.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneA);
						player->stonecount++;
						player->stonetier7++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Devil.mr / (Devil.mr + 100));

						Devil.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Devil.hp <= 0) {
							int getgold = (Devil.level * 100) + (Devil.level * bonus(gen));
							int getexp = (Devil.level * 100);

							Devil.MonsterDie(&Devil);
							stoneB.StoneDrop(&stoneB, Devil.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier7++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Devil.df / (Devil.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							Devil.hp -= (int)pdmg;
						}
						else {
							cout << Devil.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Devil.hp <= 0) {
							int getgold = (Devil.level * 100) + (Devil.level * bonus(gen));
							int getexp = (Devil.level * 100);

							Devil.MonsterDie(&Devil);
							stoneA.StoneDrop(&stoneA, Devil.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneA);
							player->stonecount++;
							player->stonetier7++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}
				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}

				if (Devil.mp >= 10) {
					Devil.mp -= 10;
					float mdmg = (float)Devil.ad + (float)Devil.ap + ((float)Devil.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)Devil.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			//3-2번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				Succubus.ShowMonsterInfo(&Succubus);

				float mdg = (float)100 * ((float)Succubus.dodge / ((float)Succubus.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * Succubus.df / (Succubus.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						Succubus.hp -= (int)pdmg;
					}
					else {
						cout << Succubus.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (Succubus.hp <= 0) {
						int getgold = (Succubus.level * 100) + (Succubus.level * bonus(gen));
						int getexp = (Succubus.level * 100);

						Succubus.MonsterDie(&Succubus);
						stoneB.StoneDrop(&stoneB, Succubus.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier8++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Succubus.mr / (Succubus.mr + 100));

						Succubus.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Succubus.hp <= 0) {
							int getgold = (Succubus.level * 100) + (Succubus.level * bonus(gen));
							int getexp = (Succubus.level * 100);

							Succubus.MonsterDie(&Succubus);
							stoneB.StoneDrop(&stoneB, Succubus.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier8++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * Succubus.df / (Succubus.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							Succubus.hp -= (int)pdmg;
						}
						else {
							cout << Succubus.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (Succubus.hp <= 0) {
							int getgold = (Succubus.level * 100) + (Succubus.level * bonus(gen));
							int getexp = (Succubus.level * 100);

							Succubus.MonsterDie(&Succubus);
							stoneB.StoneDrop(&stoneB, Succubus.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneB);
							player->stonecount++;
							player->stonetier8++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					break;
				}

				if (Succubus.mp >= 10) {
					Succubus.mp -= 10;
					float mdmg = (float)Succubus.ad + (float)Succubus.ap + ((float)Succubus.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)Succubus.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}

					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			//3-3번몹상대
			while (1) {
				player->ShowPlayerInfo(player);
				DevilBoss.ShowMonsterInfo(&DevilBoss);

				float mdg = (float)100 * ((float)DevilBoss.dodge / ((float)DevilBoss.dodge + (float)100));

				int action;
				cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
				cin.ignore();
				cin >> action;

				if (action == 1) {
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * DevilBoss.df / (DevilBoss.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						DevilBoss.hp -= (int)pdmg;
					}
					else {
						cout << DevilBoss.name << "이(가) 물리피해를 회피했습니다!\n";
					}

					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (DevilBoss.hp <= 0) {
						int getgold = (DevilBoss.level * 100) + (DevilBoss.level * bonus(gen));
						int getexp = (DevilBoss.level * 100);

						DevilBoss.MonsterDie(&DevilBoss);
						stoneC.StoneDrop(&stoneC, DevilBoss.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneC);
						player->stonecount++;
						player->stonetier9++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				if (action == 2) {
					if (player->mp >= 10) {
						player->mp -= 10;
						float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * DevilBoss.mr / (DevilBoss.mr + 100));

						DevilBoss.hp -= (int)pdmg;
						cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (DevilBoss.hp <= 0) {
							int getgold = (DevilBoss.level * 100) + (DevilBoss.level * bonus(gen));
							int getexp = (DevilBoss.level * 100);

							DevilBoss.MonsterDie(&DevilBoss);
							stoneC.StoneDrop(&stoneC, DevilBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier9++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}

					else {
						cout << "마나가 부족해 물리공격을 실행합니다.\n";
						float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

						pdmg = pdmg - (pdmg * DevilBoss.df / (DevilBoss.df + 100));

						if ((int)mdg < rand() % 100) {
							cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
							DevilBoss.hp -= (int)pdmg;
						}
						else {
							cout << DevilBoss.name << "이(가) 물리피해를 회피했습니다!\n";
						}
						Sleep(1000);
						// 플레이어의 선공격후 몹이 죽었는지 확인
						if (DevilBoss.hp <= 0) {
							int getgold = (DevilBoss.level * 100) + (DevilBoss.level * bonus(gen));
							int getexp = (DevilBoss.level * 100);

							DevilBoss.MonsterDie(&DevilBoss);
							stoneC.StoneDrop(&stoneC, DevilBoss.tier);

							Sleep(2000);
							system("cls");

							cout << getgold << "골드를 획득했습니다." << endl;
							cout << "경험치를 " << getexp << " 획득했습니다." << endl;

							player->exp += getexp;
							player->gold += getgold;

							Sleep(1000);

							player->PlayerLevelUp(player);

							player->GetStone(player, &stoneC);
							player->stonecount++;
							player->stonetier9++;

							player->ShowPlayerInfo(player);

							cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

							Sleep(5000);
							system("cls");
							break;
						}
					}
				}

				else if (action == 3) {
					cout << "출구를 향해 전력질주합니다.\n";
					Sleep(1000);
					break;
				}

				if (DevilBoss.mp >= 10) {
					DevilBoss.mp -= 10;
					float mdmg = (float)DevilBoss.ad + (float)DevilBoss.ap + ((float)DevilBoss.ap * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
				else {
					float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

					float mdmg = ((float)DevilBoss.ad * (float)atk(gen)) / (float)100;

					mdmg = mdmg - (mdmg * player->df / (player->df + 100));

					if ((int)pdg < rand() % 100) {
						player->hp -= (int)mdmg;
						cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
					}
					else {
						cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					//몬스터의 후공 후 플레이어 죽었는지 체크
					if (player->hp <= 0) {
						player->PlayerDie(player);
						break;
					}
					system("cls");
				}
			}
			cout << "마계 클리어!\n5초뒤 마을로 돌아갑니다.";
			Sleep(5000);
			break;
		}
	}
	//레벨4던전
	else if (level == 4) {
	Monster RedDragon;
	Monster BlueDragon;
	Monster GoldDragon;

	RedDragon.name = "레드 드래곤";
	RedDragon.level = 50;
	RedDragon.tier = 10;
	RedDragon.maxHp = 10000;
	RedDragon.hp = RedDragon.maxHp;
	RedDragon.maxMp = 100;
	RedDragon.mp = RedDragon.maxMp;
	RedDragon.ad = 1000;
	RedDragon.ap = 2000;
	RedDragon.df = 1000;
	RedDragon.mr = 1000;
	RedDragon.dodge = 200;

	BlueDragon.name = "블루 드래곤";
	BlueDragon.level = 75;
	BlueDragon.tier = 10;
	BlueDragon.maxHp = 20000;
	BlueDragon.hp = BlueDragon.maxHp;
	BlueDragon.maxMp = 150;
	BlueDragon.mp = BlueDragon.maxMp;
	BlueDragon.ad = 1500;
	BlueDragon.ap = 5000;
	BlueDragon.df = 1500;
	BlueDragon.mr = 1500;
	BlueDragon.dodge = 300;

	GoldDragon.name = "골드 드래곤";
	GoldDragon.level = 100;
	GoldDragon.tier = 10;
	GoldDragon.maxHp = 50000;
	GoldDragon.hp = GoldDragon.maxHp;
	GoldDragon.maxMp = 200;
	GoldDragon.mp = GoldDragon.maxMp;
	GoldDragon.ad = 2000;
	GoldDragon.ap = 7000;
	GoldDragon.df = 2000;
	GoldDragon.mr = 2000;
	GoldDragon.dodge = 400;

	cout << "-------------- 드래곤의 레어 -------------";

	Stone stoneA;
	Stone stoneB;
	Stone stoneC;

	while (1) { //3-1번몹상대
		while (1) {
			player->ShowPlayerInfo(player);
			RedDragon.ShowMonsterInfo(&RedDragon);

			float mdg = (float)100 * ((float)RedDragon.dodge / ((float)RedDragon.dodge + (float)100));

			int action;
			cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
			cin.ignore();
			cin >> action;

			if (action == 1) {
				float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

				pdmg = pdmg - (pdmg * RedDragon.df / (RedDragon.df + 100));

				if ((int)mdg < rand() % 100) {
					cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
					RedDragon.hp -= (int)pdmg;
				}
				else {
					cout << RedDragon.name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(1000);
				// 플레이어의 선공격후 몹이 죽었는지 확인
				if (RedDragon.hp <= 0) {
					int getgold = (RedDragon.level * 100) + (RedDragon.level * bonus(gen));
					int getexp = (RedDragon.level * 100);

					RedDragon.MonsterDie(&RedDragon);
					stoneA.StoneDrop(&stoneA, RedDragon.tier);

					Sleep(2000);
					system("cls");

					cout << getgold << "골드를 획득했습니다." << endl;
					cout << "경험치를 " << getexp << " 획득했습니다." << endl;

					player->exp += getexp;
					player->gold += getgold;

					Sleep(1000);

					player->PlayerLevelUp(player);

					player->GetStone(player, &stoneA);
					player->stonecount++;
					player->stonetier10++;

					player->ShowPlayerInfo(player);

					cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

					Sleep(5000);
					system("cls");
					break;
				}
			}

			if (action == 2) {
				if (player->mp >= 10) {
					player->mp -= 10;
					float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * RedDragon.mr / (RedDragon.mr + 100));

					RedDragon.hp -= (int)pdmg;
					cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (RedDragon.hp <= 0) {
						int getgold = (RedDragon.level * 100) + (RedDragon.level * bonus(gen));
						int getexp = (RedDragon.level * 100);

						RedDragon.MonsterDie(&RedDragon);
						stoneB.StoneDrop(&stoneB, RedDragon.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				else {
					cout << "마나가 부족해 물리공격을 실행합니다.\n";
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * RedDragon.df / (RedDragon.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						RedDragon.hp -= (int)pdmg;
					}
					else {
						cout << RedDragon.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (RedDragon.hp <= 0) {
						int getgold = (RedDragon.level * 100) + (RedDragon.level * bonus(gen));
						int getexp = (RedDragon.level * 100);

						RedDragon.MonsterDie(&RedDragon);

						stoneA.StoneDrop(&stoneA, RedDragon.tier);

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneA);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}
			}
			else if (action == 3) {
				cout << "출구를 향해 전력질주합니다.\n";
				break;
			}

			if (RedDragon.mp >= 10) {
				RedDragon.mp -= 10;
				float mdmg = (float)RedDragon.ad + (float)RedDragon.ap + ((float)RedDragon.ap * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

				player->hp -= (int)mdmg;
				cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
			else {
				float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

				float mdmg = ((float)RedDragon.ad * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->df / (player->df + 100));

				if ((int)pdg < rand() % 100) {
					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
				}
				else {
					cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
		}
		//3-2번몹상대
		while (1) {
			player->ShowPlayerInfo(player);
			BlueDragon.ShowMonsterInfo(&BlueDragon);

			float mdg = (float)100 * ((float)BlueDragon.dodge / ((float)BlueDragon.dodge + (float)100));

			int action;
			cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
			cin.ignore();
			cin >> action;

			if (action == 1) {
				float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

				pdmg = pdmg - (pdmg * BlueDragon.df / (BlueDragon.df + 100));

				if ((int)mdg < rand() % 100) {
					cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
					BlueDragon.hp -= (int)pdmg;
				}
				else {
					cout << BlueDragon.name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(1000);
				// 플레이어의 선공격후 몹이 죽었는지 확인
				if (BlueDragon.hp <= 0) {
					int getgold = (BlueDragon.level * 100) + (BlueDragon.level * bonus(gen));
					int getexp = (BlueDragon.level * 100);

					BlueDragon.MonsterDie(&BlueDragon);
					stoneB.StoneDrop(&stoneB, BlueDragon.tier);

					Sleep(2000);
					system("cls");

					cout << getgold << "골드를 획득했습니다." << endl;
					cout << "경험치를 " << getexp << " 획득했습니다." << endl;

					player->exp += getexp;
					player->gold += getgold;

					Sleep(1000);

					player->PlayerLevelUp(player);

					player->GetStone(player, &stoneB);
					player->stonecount++;
					player->stonetier10++;

					player->ShowPlayerInfo(player);

					cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

					Sleep(5000);
					system("cls");
					break;
				}
			}

			if (action == 2) {
				if (player->mp >= 10) {
					player->mp -= 10;
					float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * BlueDragon.mr / (BlueDragon.mr + 100));

					BlueDragon.hp -= (int)pdmg;
					cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (BlueDragon.hp <= 0) {
						int getgold = (BlueDragon.level * 100) + (BlueDragon.level * bonus(gen));
						int getexp = (BlueDragon.level * 100);

						BlueDragon.MonsterDie(&BlueDragon);
						stoneB.StoneDrop(&stoneB, BlueDragon.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				else {
					cout << "마나가 부족해 물리공격을 실행합니다.\n";
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * BlueDragon.df / (BlueDragon.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						BlueDragon.hp -= (int)pdmg;
					}
					else {
						cout << BlueDragon.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (BlueDragon.hp <= 0) {
						int getgold = (BlueDragon.level * 100) + (BlueDragon.level * bonus(gen));
						int getexp = (BlueDragon.level * 100);

						BlueDragon.MonsterDie(&BlueDragon);
						stoneB.StoneDrop(&stoneB, BlueDragon.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneB);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}
			}

			else if (action == 3) {
				cout << "출구를 향해 전력질주합니다.\n";
				break;
			}

			if (BlueDragon.mp >= 10) {
				BlueDragon.mp -= 10;
				float mdmg = (float)BlueDragon.ad + (float)BlueDragon.ap + ((float)BlueDragon.ap * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

				player->hp -= (int)mdmg;
				cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
			else {
				float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

				float mdmg = ((float)BlueDragon.ad * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->df / (player->df + 100));

				if ((int)pdg < rand() % 100) {
					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
				}
				else {
					cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
		}
		//3-3번몹상대
		while (1) {
			player->ShowPlayerInfo(player);
			GoldDragon.ShowMonsterInfo(&GoldDragon);

			float mdg = (float)100 * ((float)GoldDragon.dodge / ((float)GoldDragon.dodge + (float)100));

			int action;
			cout << "행동을 선택해주세요 (1 : 물리공격, 2: 마법공격, 3: 도망가기) : ";
			cin.ignore();
			cin >> action;

			if (action == 1) {
				float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

				pdmg = pdmg - (pdmg * GoldDragon.df / (GoldDragon.df + 100));

				if ((int)mdg < rand() % 100) {
					cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
					GoldDragon.hp -= (int)pdmg;
				}
				else {
					cout << GoldDragon.name << "이(가) 물리피해를 회피했습니다!\n";
				}

				Sleep(1000);
				// 플레이어의 선공격후 몹이 죽었는지 확인
				if (GoldDragon.hp <= 0) {
					int getgold = (GoldDragon.level * 100) + (GoldDragon.level * bonus(gen));
					int getexp = (GoldDragon.level * 100);

					GoldDragon.MonsterDie(&GoldDragon);
					stoneC.StoneDrop(&stoneC, GoldDragon.tier);

					Sleep(2000);
					system("cls");

					cout << getgold << "골드를 획득했습니다." << endl;
					cout << "경험치를 " << getexp << " 획득했습니다." << endl;

					player->exp += getexp;
					player->gold += getgold;

					Sleep(1000);

					player->PlayerLevelUp(player);

					player->GetStone(player, &stoneC);
					player->stonecount++;
					player->stonetier10++;

					player->ShowPlayerInfo(player);

					cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

					Sleep(5000);
					system("cls");
					break;
				}
			}

			if (action == 2) {
				if (player->mp >= 10) {
					player->mp -= 10;
					float pdmg = (float)player->ad + (float)player->ap + ((float)player->ap * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * GoldDragon.mr / (GoldDragon.mr + 100));

					GoldDragon.hp -= (int)pdmg;
					cout << (int)pdmg << " 데미지의 마법피해 공격!\n";
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (GoldDragon.hp <= 0) {
						int getgold = (GoldDragon.level * 100) + (GoldDragon.level * bonus(gen));
						int getexp = (GoldDragon.level * 100);

						GoldDragon.MonsterDie(&GoldDragon);
						stoneC.StoneDrop(&stoneC, GoldDragon.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneC);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}

				else {
					cout << "마나가 부족해 물리공격을 실행합니다.\n";
					float pdmg = ((float)player->ad * (float)atk(gen)) / (float)100;

					pdmg = pdmg - (pdmg * GoldDragon.df / (GoldDragon.df + 100));

					if ((int)mdg < rand() % 100) {
						cout << (int)pdmg << " 데미지의 물리피해 공격!\n";
						GoldDragon.hp -= (int)pdmg;
					}
					else {
						cout << GoldDragon.name << "이(가) 물리피해를 회피했습니다!\n";
					}
					Sleep(1000);
					// 플레이어의 선공격후 몹이 죽었는지 확인
					if (GoldDragon.hp <= 0) {
						int getgold = (GoldDragon.level * 100) + (GoldDragon.level * bonus(gen));
						int getexp = (GoldDragon.level * 100);

						GoldDragon.MonsterDie(&GoldDragon);
						stoneC.StoneDrop(&stoneC, GoldDragon.tier);

						Sleep(2000);
						system("cls");

						cout << getgold << "골드를 획득했습니다." << endl;
						cout << "경험치를 " << getexp << " 획득했습니다." << endl;

						player->exp += getexp;
						player->gold += getgold;

						Sleep(1000);

						player->PlayerLevelUp(player);

						player->GetStone(player, &stoneC);
						player->stonecount++;
						player->stonetier10++;

						player->ShowPlayerInfo(player);

						cout << "전투에서 승리했습니다. 5초후 다음 지역으로 진입합니다.\n";

						Sleep(5000);
						system("cls");
						break;
					}
				}
			}

			else if (action == 3) {
				cout << "출구를 향해 전력질주합니다.\n";
				Sleep(1000);
				break;
			}

			if (GoldDragon.mp >= 10) {
				GoldDragon.mp -= 10;
				float mdmg = (float)GoldDragon.ad + (float)GoldDragon.ap + ((float)GoldDragon.ap * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->mr / (player->mr + 100));

				player->hp -= (int)mdmg;
				cout << (int)mdmg << " 데미지의 마법피해를 입었습니다!\n";
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
			else {
				float pdg = (float)100 * ((float)player->dodge / ((float)player->dodge + (float)100));

				float mdmg = ((float)GoldDragon.ad * (float)atk(gen)) / (float)100;

				mdmg = mdmg - (mdmg * player->df / (player->df + 100));

				if ((int)pdg < rand() % 100) {
					player->hp -= (int)mdmg;
					cout << (int)mdmg << " 데미지의 물리피해를 입었습니다!\n";
				}
				else {
					cout << player->name << "이(가) 물리피해를 회피했습니다!\n";
				}
				Sleep(1000);
				//몬스터의 후공 후 플레이어 죽었는지 체크
				if (player->hp <= 0) {
					player->PlayerDie(player);
					break;
				}
				system("cls");
			}
		}
		cout << "마계 클리어!\n5초뒤 마을로 돌아갑니다.";
		Sleep(5000);
		break;
	}
		}
}

Store::Store() 
{
	
}
void Store::GoStore(Player* player) {
	system("cls");

	int input;
	Stone stoneC;

	cout << "상점에 들어왔습니다.\n당신에 운에 따라 폭발적인 성장이 가능합니다.\n\n";
	cout << "1~100 능력치 랜덤 돌 상자 : 10000골드\n구매하시려면 1, 그냥 나가시려면 2를 입력해주세요 : ";
	cin >> input;

	if (input == 1) {
		if (player->gold >= 10000) {
			stoneC.StoneDrop(&stoneC, 100);

			player->GetStone(player, &stoneC);
			player->stonecount++;
			player->gold -= 10000;

			player->ShowPlayerInfo(player);
		}
		else {
			cout << "골드가 부족합니다.\n";
		}
	}
	else {
		cout << "상점을 나갑니다.\n";
	}

	cout << "5초 뒤 마을로 돌아갑니다.\n";
	Sleep(5000);

	system("cls");
}
House::House()
{

}
void House:: GoHouse(Player* player) {
	system("cls");
	cout << "숙소로 돌아왔습니다. 잠시 누워 휴식을 취해 체력이 회복됩니다.\n세이브기능추가해야함\n";

	player->FullHp(player);
	player->ShowPlayerInfo(player);

	cout << "총 모은 돌 갯수 : " << player->stonecount << endl;
	cout << "1티어 돌 갯수 : " << player->stonetier1 << endl;
	cout << "2티어 돌 갯수 : " << player->stonetier2 << endl;
	cout << "3티어 돌 갯수 : " << player->stonetier3 << endl;
	cout << "4티어 돌 갯수 : " << player->stonetier4 << endl;
	cout << "5티어 돌 갯수 : " << player->stonetier5 << endl;
	cout << "6티어 돌 갯수 : " << player->stonetier6 << endl;
	cout << "7티어 돌 갯수 : " << player->stonetier7 << endl;
	cout << "8티어 돌 갯수 : " << player->stonetier8 << endl;
	cout << "9티어 돌 갯수 : " << player->stonetier9 << endl;
	cout << "10티어 돌 갯수 : " << player->stonetier10 << endl;

	Sleep(5000);

	system("cls");
}