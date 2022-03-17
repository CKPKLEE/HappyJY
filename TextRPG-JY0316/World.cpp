#include "World.h"

void World::GoMap(Player* player, int type) {
	if (type == 0) {
		GoMainSquare(player);
	}
	else if (type == 1) {
		map = new Dungeon;
		map->GoDungeon(player);
	}
	else if (type == 2) {
		map = new Store;
		map->GoStore(player);
	}
	else if (type == 3) {
		map = new House;
		map->GoHouse(player);
	}
}

void World::GoMainSquare(Player* player)
{
	int input;

	system("cls");

	cout << "이곳은 광장입니다. 던전에 입장하려면 1, 상점을 이용하려면 2" << endl;
	cout << "\n숙소로 돌아가 체력을 회복하려면 3을 입력해주세요 : ";
	cin >> input;

	if (input == 1) {
		GoMap(player, 1);
	}
	else if (input == 2) {
		GoMap(player, 2);
	}
	else if (input == 3) {
		GoMap(player, 3);
	}
	else {
		cout << "잘못된 값입니다. 다시 입력해주세요.";
		Sleep(2000);
		system("cls");
		GoMainSquare(player);
	}
}