#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
char *my_strcat(char *dest, const char *src)
{
	char *ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}


char *my_strcpy(char *dest, const char *src)
{
	char *ret = dest;
	assert(*dest != NULL);
	assert(*src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char a[] = "abhujh";
	char b[] = "guijkk";
	//my_strcpy(a, b);
	my_strcat(a, b);
	printf("%s", a);
	system("pause");
	return 0;
}

int main()
{
	int money = 0;
	scanf("%d", &money);
	int total = money;
	int empty = money;
	while (empty>1)
	{
		total = total + empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d ", total);
	system("pause");
	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 2, 1 };
	int ret = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	int i = 0;
	int len = sizeof (arr) / sizeof (arr[0]);
	for (i = 0; i < len; i++)
	{
		ret = ret^arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < 32; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x = x^arr[i];
		}
		else
		{
			y = y^arr[i];
		}
	}
	printf("%d %d\n", x, y);
	system("pause");
	return 0;

}

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC


//void reverse(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
//void left_rotate(char *str, int k)
//{
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}
//
//int is_rotate(char *dest, char *rotate)
//{
//	if (strlen(dest) != strlen(rotate))
//	{
//		return 0;
//	}
//
//	strncat(dest, dest,strlen (dest));//先运用拼接
//	if (strstr(dest, rotate) != NULL)//然后运用判断子串的方法
//	{
//		return 1;
//	}
	//每次左旋一次，判断一次，共旋转strlen(str)次
	//若有符合结果的，返回1，否则，返回0.
	//int len = strlen(rotate);
	//while (len--)
	//{
	//	left_rotate(rotate, 1);
	//	if (!strcpy(dest, rotate))
	//	{
	//		return 1;
	//	}
	//}
//	return 0;
//}
//
//int main()
//{
//	char a[] = { 0 };
//	char b[] = { 0 };
//	scanf("%s", &a);
//	scanf("%s", &b);
//	int ret=is_rotate(a, b);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//
//}


//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//左旋一次：ABCD----->BCDA
//左旋两次：ABCD----->CDAB
//void left_rotate(char *str, int k)
//{
//	char *cur = str;
//	char temp = *str;
//	while (*(cur + 1) != '\0')
//	{
//		*cur = *(cur + 1);
//		cur++;
//	}
//	*cur = temp;
//}

//左旋k次：ABCDEF----->EFABCD
//第一次：逆转前n个数
//第二次：逆转剩余的数
//第三次：整体逆转
//
//void reverse(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
//void left_rotate(char *str, int k)
//{
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}


//int main()
//{
//	char arr[] = { 0 };
//	int k = 0;
//	scanf("%s", &arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}




//char * my_strcpy(char *dest, char *src)
//{
//	char *ret = dest;
//	assert(*dest != NULL);
//	assert(*src != NULL);
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//
//	}
//	dest = '\0';
//	return ret;
//}
//int main()
//{
//	char a[] = "abcgy";
//	char b[] = "shbui";
//	my_strcpy(a, b);
//	printf("%s", a);
//	system("pause");
//	return 0;
//}



//int strlen(const char *str)
//{
//	int count = 0;
//	assert(*str != NULL);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse_r(char *start, char *end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void reverse(char *str)
//{
//	//char arr[] = "student a am i";
//	char *cur = str;
//	char *left = str;
//	char *right = str + strlen(str) - 1;
//	reverse_r(left, right);
//
//	while (*cur)
//	{
//		char *start = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}
//		reverse_r(start, cur - 1);
//		if (*cur == ' ')
//		{
//			cur++;
//		}
//
//	}
//
//}
//int main()
//{
//	//char arr[] = "student a am i";
//	char arr[] = { 0 };
//	gets(arr);
//	reverse(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}




//int rearch(int arr[3][3], int row, int col, int k, int x, int y, int *px, int *py)
//{
//	if (x < 0 || (y >= col))
//	{
//		*px = -1;
//		*py = -1;
//		return 0;
//	}
//	if (arr[x][y] == k)
//	{
//		*px = x;
//		*py = y;
//		return 1;
//	}
//	else if (arr[x][y] > k)
//	{
//		rearch(arr, 3, 3, k, x - 1, y, px, py);
//	}
//	else if (arr[x][y] < k)
//	{
//		rearch(arr, 3, 3, k, x, y + 1, px, py);
//	}
//}
//
//int main()
//{
//	int px = 0;
//	int py = 0;
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	rearch(arr, 3, 3, 6, 2, 0, &px, &py);
//	printf("%d %d\n", px, py);
//	system("pause");
//	return 0;
//}









