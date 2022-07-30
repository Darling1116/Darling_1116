#include "game.h"


//��ʾ�˵�
void menu(){
	printf("#######��������Ϸ######\n");
	printf("########1. play #######\n");
	printf("########0. exit #######\n");
	printf("#######################\n");
}

//����Ϸ
void game(){
	//������������
	char board[ROW][COL] = { 0 };

	//��ʼ������
	InitBoard(board, ROW, COL);
	//DisplayBoard(board, ROW, COL);

	//ʵ���˻���������
	int ret = 0;
	while (1){
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if(ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���Ӯ...\n");
	else if (ret == '#')
		printf("����Ӯ...\n");
	else
		printf("ƽ��...\n");
}

//������Ϸ
void test(){
	int input = 0;
	srand((unsigned int)time(NULL));  //�������

	do{
		menu();
		printf("��ѡ��->:");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			//printf("��ʼ��Ϸ\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);

}

int main(){
	test();

	system("pause");
	return 0;
}