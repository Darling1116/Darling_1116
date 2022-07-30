#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	for (i = 0; i < row; i++){
		int j = 0;
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}


void DisplayBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	for (i = 0; i < row; i++){
		int j = 0;
		for (j = 0; j < col; j++){
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1){
			for (j = 0; j < col; j++){
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");	
		}
	}
}


//在棋盘上的空格处下棋
void PlayerMove(char board[ROW][COL], int row, int col){
//保证玩家下棋时坐标的合法性
//若坐标不合法，玩家一直输入，直到有合法坐标
	int x = 0;
	int y = 0; 
	printf("玩家下棋\n");
	while (1){
		printf("请输入坐标-> ");
		scanf("%d %d", &x, &y);
		if (x - 1<0 || x - 1 > 2 || y - 1<0 || y - 1 > 2){
			printf("坐标输入不合法，请重新输入！\n");
		}
		else if (board[x - 1][y - 1] != ' '){
			printf("坐标已被占用，请重新输入！\n");
		}
		else{
			board[x - 1][y - 1] = '*';
			break;
		}
	}

}


void ComputerMove(char board[ROW][COL], int row, int col){
	printf("电脑下棋->\n");
	while (1){
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' '){
			board[x][y] = '#';
			break;
		}
	}
}


int is_full(char board[ROW][COL], int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col){
	//赢的情况：1.某一行或一列相等(三个元素两两相等且不为空)
	//2. 对角线元素相等，然后返回相等的元素
	int i = 0;
	for (i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]
			&& board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&& board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ')
		return board[0][0];
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
		&& board[0][2] != ' ')
		return board[0][2];
	else if (is_full(board, row, col))
		return 'Q';
	else
		return 'C';
	//否则，要么平局，要么继续下棋
}