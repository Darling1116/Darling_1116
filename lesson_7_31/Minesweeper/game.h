#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS 11
#define COLS 11

#define MINENUM 10


void InitBoard(char board[ROWS][COLS], int row, int col, char set);

void ShowBoard(char board[ROWS][COLS], int row, int col);

// �����׵�
void SetMine(char board[ROWS][COLS], int row, int col);

//���ף���mine���Ų��׵��������show����ʾ�Ų���
void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col);

//�����׵㣬ͳ������Χ�׵����
int mine_nums(char board[ROWS][COLS], int row, int col);

