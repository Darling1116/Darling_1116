#include "game.h"


//显示菜单
void menu(){
	printf("#######三子棋游戏######\n");
	printf("########1. play #######\n");
	printf("########0. exit #######\n");
	printf("#######################\n");
}

//玩游戏
void game(){
	//存放下棋的数据
	char board[ROW][COL] = { 0 };

	//初始化棋盘
	InitBoard(board, ROW, COL);
	//DisplayBoard(board, ROW, COL);

	//实现人机交替下棋
	int ret = 0;
	while (1){
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if(ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢...\n");
	else if (ret == '#')
		printf("电脑赢...\n");
	else
		printf("平局...\n");
}

//测试游戏
void test(){
	int input = 0;
	srand((unsigned int)time(NULL));  //随机种子

	do{
		menu();
		printf("请选择->:");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			//printf("开始游戏\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入出错\n");
			break;
		}
	} while (input);

}

int main(){
	test();

	system("pause");
	return 0;
}