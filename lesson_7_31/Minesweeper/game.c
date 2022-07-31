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

//����
void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int win = 0; //��¼�Ų�ɹ����������
	while (win < row*col-MINENUM){
		printf("����������-> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col){
			if (board1[x][y] == '1'){
				printf("����ʧ�ܣ��㱻ը���ˣ�\n");
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
			printf("�������겻�Ϸ�������������...\n");
		}
	}
	if (win == row*col - MINENUM){
		printf("ɨ�׳ɹ�������\n");
	}
}



// ĳһ��������Χ�׵�ĸ�����Ϊ����Χ8���������׵����֮��
// �ַ��ͼ�ȥ'0'Ϊ���ַ�����ʾ��int����ֵ
int mine_nums(char board[ROWS][COLS], int x, int y){
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1]
		+ board[x][y - 1] + board[x][y + 1]
		+ board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]
		- 8 * '0';
}

