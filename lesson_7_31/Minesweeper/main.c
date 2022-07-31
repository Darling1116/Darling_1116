#include "game.h"

void menu(){
	printf("#######ɨ��#######\n");
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
		printf("��ѡ��->: ");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			//printf("��ʼ��Ϸ...\n");
			break;
		case 0:
			printf("�˳���Ϸ...\n");
			break;
		default:
			printf("�����������������...\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}