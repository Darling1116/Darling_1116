#include "contact.h"

void menu(){
	printf("**************************\n");
	printf("****1.add     2.del   ****\n");
	printf("****3.search  4.modify****\n");
	printf("****5.print   0.exit  ****\n");
	printf("**************************\n");
}


void test(){
	//创建一个通讯录
	Contact con; 
	init_contact(&con);

	int input = 0;
	do{
		menu();
		printf("请选择-> ");
		scanf("%d", &input);

		switch (input){
		case 1:
			add_contact(&con);
			break;
		case 2:
			del_contact(&con);
			break;
		case 3:
			search_contact(&con);
			break;
		case 4:
			modify_contact(&con);
			break;
		case 5:
			print_contact(&con);
			break;
		case 0:
			printf("退出通讯录...\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
}

int main(){

	test();

	return 0;
}