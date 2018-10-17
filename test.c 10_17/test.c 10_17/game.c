#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char arr[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = rand() % ROW + 1;
	int y = rand() % COL + 1;
	while (count)
	{
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//printf("请输入雷点的坐标:>\n");
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入雷点的坐标:>\n");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("哎呦！你被炸死了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
	else
		{
			printf("输入坐标有误，请重新输入:>\n");
	    }
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("哇塞！扫雷成功！\n");
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y + 1] + mine[x][y - 1] +
		mine[x - 1][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x + 1][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y]
		- 8 * '0';
}