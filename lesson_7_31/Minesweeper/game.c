#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[i][j] = set;
		}
	}
}

void ShowBoard(char board[ROWS][COLS], int row, int col){
	for (int j = 0; j < col-1; j++){
		printf("%d ", j);
	}
	printf("\n");

	for (int i = 1; i < row-1; i++){
		printf("%d ", i);
		for (int j = 1; j < col-1; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int num = MINENUM;
	while (num){
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0'){
			board[x][y] = '1';
			num--;
		}
	}
}

//排雷
void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int win = 0; //记录排查成功的坐标个数
	while (win < row*col-MINENUM){
		printf("请输入坐标-> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col){
			if (board1[x][y] == '1'){
				printf("排雷失败，你被炸死了！\n");
				ShowBoard(board1, ROWS, COLS);
				break;
			}
			else{
				int num = mine_nums(board1, x, y);
				board2[x][y] = num + '0';
				win++;
				ShowBoard(board2, ROWS, COLS);
			}
		}
		else{
			printf("输入坐标不合法，请重新输入...\n");
		}
	}
	if (win == row*col - MINENUM){
		printf("扫雷成功！！！\n");
	}
}



// 某一点坐标周围雷点的个数，为其周围8个坐标点的雷点个数之和
// 字符型减去'0'为该字符所表示的int型数值
int mine_nums(char board[ROWS][COLS], int x, int y){
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1]
		+ board[x][y - 1] + board[x][y + 1]
		+ board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]
		- 8 * '0';
}

