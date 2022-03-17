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

	cout << "�̰��� �����Դϴ�. ������ �����Ϸ��� 1, ������ �̿��Ϸ��� 2" << endl;
	cout << "\n���ҷ� ���ư� ü���� ȸ���Ϸ��� 3�� �Է����ּ��� : ";
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
		cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���.";
		Sleep(2000);
		system("cls");
		GoMainSquare(player);
	}
}