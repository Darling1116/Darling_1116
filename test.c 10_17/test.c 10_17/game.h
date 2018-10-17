#ifndef _GAME_H__
#define _GAME_H__5

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 9

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


void InitBoard(char arr[ROWS][COLS], int row, int col, char set);
void DisplayBoard(char arr[ROWS][COLS], int row, int col);
void SetMine(char arr[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);


#endif