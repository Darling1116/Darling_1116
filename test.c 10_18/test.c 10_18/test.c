#define _CRT_SECURE_NO_WARNINGS
#include "game..h"

void menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");
}

void game()
{
	char arr[ROW][COL] = { 0 };
	int ret = 0;
	InitBoard(arr,ROW,COL);
	DisplayBoard(arr,ROW,COL);
	while (1)
	{

		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
	
		 ret = IsWin(arr, ROW, COL);
		if (ret != ' ')
			break;
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
	    ret = IsWin(arr, ROW, COL);
		if (ret != ' ')
			break;
	}

	if (ret == 'X')
		printf("电脑赢！\n");
	else if (ret == '0')
		printf("玩家赢！\n");
	else if (ret == 'Q')
		printf("平局！\n");

}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu( );
	printf("请选择:>\n");
	do{
		//printf("请选择:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game( );
			break;
		case 0:
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}
