#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType* data;
	int maxSize;
	int length;
}SeqList;

void InitList(SeqList* sl,int maxsize){
	sl->data = (SLDataType*)malloc(sizeof(SLDataType)*maxsize);
	assert(sl->data);
	sl->maxSize = maxsize;
	sl->length = 0;
}

void PrintList(SeqList* sl){
	for (int i = 0; i < sl->length; i++){
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}


bool InsertList(SeqList* sl, int pos,SLDataType x){
	assert(sl);
	if (pos<1 || pos>sl->length + 1){
		return false;
	}
	if (sl->length >= sl->maxSize){
		return false;
	}
	//从最后一个元素开始向后挪动
	for (int i = sl->length; i >= pos; i--){
		sl->data[i] = sl->data[i-1];
	}
	sl->data[pos - 1] = x;
	sl->length++;
	return true;
}


//删除最小值元素（假设唯一），空出的位置由最后一个元素补上
SLDataType DeleteMinNum(SeqList* sl){
	if (sl->length == 0){
		return false;
	}
	int min = sl->data[0];
	int pos = 0;
	for (int i = 1; i < sl->length; i++){
		if (sl->data[i] < min){
			int tmp = sl->data[i];
			sl->data[i] = min;
			min = tmp;
			pos = i;
		}
	}
	sl->data[pos] = sl->data[sl->length - 1];
	sl->length--;
	return min;
}


//时间复杂度O(n),空间复杂度O(1)
void DeleteAllNum1(SeqList* sl, SLDataType x){
	int k = 0;
	//用k记录值为x的元素（即，记录删除元素）
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] == x){
			k++;
		}
		else{
			sl->data[i - k] = sl->data[i];
		}
	}
	sl->length = sl->length - k;
}

void DeleteAllNum2(SeqList* sl, SLDataType x){
	int k = 0;
	//用k记录值不为x的元素
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] != x){
			sl->data[k++] = sl->data[i];
		}
	}
	sl->length = k;
}

//删除x~y之间的元素，要求x<y。
bool DeleteBetween(SeqList* sl, SLDataType x, SLDataType y){
	if (sl->length == 0){
		return false;
	}
	if (x >= y){
		return false;
	}
	int k = 0;
	for (int i = 0; i < sl->length; i++){
		if (sl->data[i] >= x&&sl->data[i] <= y){
			k++;
		}
		else{
			sl->data[i - k] = sl->data[i];
		}
	}
	sl->length = sl->length - k;
	return true;
}



//删除有序顺序表中地所有重复的元素，使表中的元素不相同
void SeqDeleteRepeat(SeqList* sl){
	assert(sl);
	//第一个元素先拿出来，从第二个元素开始对比
	int i, j;
	for (i = 0, j = 1; j < sl->length; j++){
		//记录不重复的值
		if (sl->data[i] != sl->data[j]){
			sl->data[++i] = sl->data[j];
		}
	}
	sl->length = i + 1;
}


//删除有序表中x~y之间的元素，要求x<y
bool SeqDeleteBetween(SeqList* sl, SLDataType x, SLDataType y){
	if (sl->length == 0){
		return false;
	}
	if (x >= y){
		return false;
	}
	int i, j;
	for ( i = 0; i < sl->length; i++){
		if (sl->data[i] >= x){
			break;
		}
	}
	if (i >= sl->length){
		return false;
	}
	for (j = i; j < sl->length; j++){
		if (sl->data[j] > y){
			break;
		}
	}
	while (j < sl->length){
		sl->data[i++] = sl->data[j++];
	}
	sl->length = i;
}

int main( ){
	SeqList sl;
	InitList(&sl,10);
	InsertList(&sl, 1, 8);
	InsertList(&sl, 1, 7);
	InsertList(&sl, 1, 3);
	InsertList(&sl, 1, 3);
	InsertList(&sl, 1, 2);
	InsertList(&sl, 1, 2);
	InsertList(&sl, 1, 1);

	//DeleteMinNum(&sl);

	//DeleteAllNum1(&sl, 2);
	//DeleteAllNum2(&sl, 2);
	//DeleteBetween(&sl, 1, 4);

	//SeqDeleteRepeat(&sl);
	SeqDeleteBetween(&sl, 2, 3);

	PrintList(&sl);




	system("pause");
	return 0;
}