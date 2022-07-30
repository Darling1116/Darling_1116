#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘:一格一格的打印
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋:用*号
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋：随机下，用#号
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢情况：玩家赢--*  电脑赢--#  平局--Q  继续下棋--C
char is_win(char board[ROW][COL], int row, int col);

//判断是否平局：棋盘满了
int is_full(char board[ROW][COL], int row, int col);

