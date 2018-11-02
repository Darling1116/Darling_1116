#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Find_difer(int arr[], int sz)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];
	}
	printf("%d ", ret);
}
int main()
{
	int arr[7] = { 1, 2, 3, 5, 3, 2, 1 };
	int sz = sizeof (arr) / sizeof(arr[0]);
	Find_difer(arr, sz);
	return 0;
}



//int main()
//{
//	int a = 0;
//	int b = 0;
//	int aver = 0;
//	scanf("%d%d", &a, &b);
//	aver = b + ((a - b) / 2);
//	printf("%d ", aver);
//	return 0;
//}


//unsigned int reserve_bit(unsigned int value)
//{
//	int result = 0;
//    int sum = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		result = value % 2;  //result =value&1;
//		sum = sum + (result*pow( 2,(31 - i)));
//		value = value / 2;  //value=value>>1;
//	}
//	return sum;
//}
//int main(  )
//{
//
//    unsigned  int ret = 0;
//	unsigned  int value = 0;
//	scanf("%d",&value);
//	ret = reserve_bit(value);
//	printf("%u ", ret);
//	system("pause");
//	return 0;
//}