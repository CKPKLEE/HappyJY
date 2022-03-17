#pragma once

#include "MainHeader.h"
#include "Unit.h"
#include "Item.h"
#include "Stone.h"
#include "Map.h"
#include "World.h"

void prologue(Player player) {
	cout << "당신의 이름은 " << player.name << endl;
	Sleep(2000);
	cout << "\n20년간 헬스장에서 먹고 자며 3대 900을 훌쩍 넘기고\n";
	Sleep(2000);
	cout << "\n이제 성인이 되어 세상으로 나아갈 시간입니다.\n";
	Sleep(2000);
	cout << "\n이곳은 마력이 깃든 돌멩이가 넘치는 세계입니다.\n";
	Sleep(2000);
	cout << "\n전사 마법사 할 것 없이 중량만 잔뜩 쳐서 \n";
	Sleep(2000);
	cout << "\n공격력이 깃든 돌멩이를 지니고 다니면 전사가 되고 \n";
	Sleep(2000);
	cout << "\n주문력이 깃든 돌멩이를 지니고 다니면 마법사가 되고 \n";
	Sleep(2000);
	cout << "\n전사 마법사 할 것 없이 근력만 잔뜩 키워서 \n";
	Sleep(2000);
	cout << "\n최대한 좋은 돌들을 많이 지닐수록 강해지는 세계입니다. \n";
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