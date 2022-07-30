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


//�������ϵĿո�����
void PlayerMove(char board[ROW][COL], int row, int col){
//��֤�������ʱ����ĺϷ���
//�����겻�Ϸ������һֱ���룬ֱ���кϷ�����
	int x = 0;
	int y = 0; 
	printf("�������\n");
	while (1){
		printf("����������-> ");
		scanf("%d %d", &x, &y);
		if (x - 1<0 || x - 1 > 2 || y - 1<0 || y - 1 > 2){
			printf("�������벻�Ϸ������������룡\n");
		}
		else if (board[x - 1][y - 1] != ' '){
			printf("�����ѱ�ռ�ã����������룡\n");
		}
		else{
			board[x - 1][y - 1] = '*';
			break;
		}
	}

}


void ComputerMove(char board[ROW][COL], int row, int col){
	printf("��������->\n");
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
	//Ӯ�������1.ĳһ�л�һ�����(����Ԫ����������Ҳ�Ϊ��)
	//2. �Խ���Ԫ����ȣ�Ȼ�󷵻���ȵ�Ԫ��
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
	//����Ҫôƽ�֣�Ҫô��������
}