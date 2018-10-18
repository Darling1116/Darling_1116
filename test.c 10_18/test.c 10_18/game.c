#define _CRT_SECURE_NO_WARNINGS
#include "game..h"

void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			arr[i][j] = ' ';
	}
}

void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}

		printf("\n");
		if (i < row - 1)
		for (j = 0; j < col;j++)
		{
			printf("___");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}

void ComputerMove(char arr[ROW][COL], int row, int col)
{
	//int x = 0;
	//int y = 0;
	printf("电脑走:>\n");
	int x = rand() % ROW;
	int y = rand() % COL;
	if (arr[x][y] == ' ')
	{
		arr[x][y] = 'X';
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)
{
	printf("玩家走:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (arr[x-1][y-1] == ' ')
			{
				arr[x-1][y-1] = '0';
				break;
			}
			else
				printf("坐标已被占用，请重新输入!\n");
		}
		else
			printf("坐标输入有误，请重新输入！\n");
	}
}

char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]
			&& arr[i][0] != ' ')
		{
			return arr[i][0];
		}

		for (j = 0; j < col; j++)
		{
			if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]
				&& arr[0][j] != ' ')
			{
				return arr[0][j];
			}
		}

		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]
			&& arr[0][0] != ' ')
		{
			return arr[0][0];
		}

		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]
			&& arr[0][2] != ' ')
		{
			return arr[0][2];
		}
		if (IsFull(arr, row, col))
		{
			return 'Q';
		}
	}
	return ' ';//继续
}

int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}