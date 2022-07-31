#include "game.h"

void menu(){
	printf("#######扫雷#######\n");
	printf("######1.play######\n");
	printf("######0.exit######\n");
	printf("##################\n");
}

void game(){
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	InitBoard(mineboard, ROWS, COLS, '0');
	InitBoard(showboard, ROWS, COLS, '*');
	SetMine(mineboard, ROW, COL);
	ShowBoard(mineboard, ROWS, COLS);
	ShowBoard(showboard, ROWS, COLS);

	FindMine(mineboard, showboard, ROW, COL);
	
}

int main(){
	menu();
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		printf("请选择->: ");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			//printf("开始游戏...\n");
			break;
		case 0:
			printf("退出游戏...\n");
			break;
		default:
			printf("输入错误，请重新输入...\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}