#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p;
//�ýṹ��Ĵ�СΪ20���ֽ�

void main1(){

	/*
	char* p = "abcdef";
	printf("%d\n", sizeof(p));  //4��8 �������ָ�����p�Ĵ�С
	printf("%d\n", sizeof(p + 1));  //4��8 �õ������ַ�b�ĵ�ַ
	printf("%d\n", sizeof(*p));  //1 ��һ���ַ��Ĵ�С
	printf("%d\n", sizeof(p[0]));  //1  p[0]==*(p+0)  ��һ��Ԫ�صĴ�С
	printf("%d\n", sizeof(&p));  //4��8 ����ĵ�ַ
	printf("%d\n", sizeof(&p + 1));  //4��8 �������������ĵ�ַ
	printf("%d\n", sizeof(&p[0] + 1));  //4��8 �ڶ���Ԫ�صĵ�ַ


	printf("%d\n", strlen(p));  //6
	printf("%d\n", strlen(p + 1));  //5
	printf("%d\n", strlen(&p));  //���ֵ
	printf("%d\n", strlen(&p + 1));  //���ֵ
	printf("%d\n", strlen(&p[0] + 1));  //5
	*/

	
	/*
	int a[3][4] = { 0 };
	printf("%p\n", &a[0][0]);  //����ĵ�ַ
	printf("%p\n", a[0] + 1);  //��һ�еڶ���Ԫ�صĵ�ַ
	printf("%p\n", a + 1);  //�ڶ�����Ԫ�صĵ�ַ
	printf("%p\n", &a[0] + 1);  //�ڶ�����Ԫ�صĵ�ַ
	*/

	
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));  //48
	printf("%d\n", sizeof(a[0][0]));  //4

	printf("%d\n", sizeof(a[0]));  
	//16  a[0]�ǵ�һ�е���������������ǵ�һ�еĴ�С
	printf("%d\n", sizeof(a[0]+1));  
	//4��8  a[0]�ǵ�һ�е�������������Ԫ�صĵ�ַ,a[0]+1������ǵ�һ�еڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));  
	//4  ��һ�еڶ���Ԫ�صĴ�С��int�ͣ�Ϊ4���ֽ�

	printf("%d\n", sizeof(a+1));  
	//4��8  a�Ƕ�ά�����������������Ԫ�صĵ�ַ����һ�У�,a+1������ǵڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a + 1)));  
	//16    ������ǵڶ��еĴ�С 4x4=16�ֽ�
	printf("%d\n", sizeof(&a[0] + 1));  
	//4��8  �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));  
	//16    �ڶ��еĴ�С

	printf("%d\n", sizeof(*a));  
	//16  a�Ƕ�ά��������������ǵ�һ�еĵ�ַ,*a������ǵ�һ�еĴ�С
	printf("%d\n", sizeof(a[3]));  //16


	system("pause");
	return 0;
}

