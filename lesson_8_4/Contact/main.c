#include "contact.h"

void menu(){
	printf("**************************\n");
	printf("****1.add     2.del   ****\n");
	printf("****3.search  4.modify****\n");
	printf("****5.print   0.exit  ****\n");
	printf("**************************\n");
}


void test(){
	//����һ��ͨѶ¼
	Contact con; 
	init_contact(&con);

	int input = 0;
	do{
		menu();
		printf("��ѡ��-> ");
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
			printf("�˳�ͨѶ¼...\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);
}

int main(){

	test();

	return 0;
}