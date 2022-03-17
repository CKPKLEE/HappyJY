#pragma once

#include "MainHeader.h"
#include "Unit.h"
#include "Item.h"
#include "Stone.h"
#include "Map.h"
#include "World.h"

void prologue(Player player) {
	cout << "����� �̸��� " << player.name << endl;
	Sleep(2000);
	cout << "\n20�Ⱓ �ｺ�忡�� �԰� �ڸ� 3�� 900�� ��½ �ѱ��\n";
	Sleep(2000);
	cout << "\n���� ������ �Ǿ� �������� ���ư� �ð��Դϴ�.\n";
	Sleep(2000);
	cout << "\n�̰��� ������ ��� �����̰� ��ġ�� �����Դϴ�.\n";
	Sleep(2000);
	cout << "\n���� ������ �� �� ���� �߷��� �ܶ� �ļ� \n";
	Sleep(2000);
	cout << "\n���ݷ��� ��� �����̸� ���ϰ� �ٴϸ� ���簡 �ǰ� \n";
	Sleep(2000);
	cout << "\n�ֹ����� ��� �����̸� ���ϰ� �ٴϸ� �����簡 �ǰ� \n";
	Sleep(2000);
	cout << "\n���� ������ �� �� ���� �ٷ¸� �ܶ� Ű���� \n";
	Sleep(2000);
	cout << "\n�ִ��� ���� ������ ���� ���Ҽ��� �������� �����Դϴ�. \n";
	Sleep(4000);

	system("cls");
}


int main() {
	Player player;
	player.MakeInfo(&player);

	system("cls");

	prologue(player);
	player.ShowPlayerInfo(&player);

	while (1) {
		World MainSquare;
		MainSquare.GoMainSquare(&player);
	}

	return 0;
}