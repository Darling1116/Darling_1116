#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct MinStack{
	int* array;
	int top;
	int capcaity;
	int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* st = (MinStack*)malloc(sizeof(MinStack));
	st->array = NULL;
	st->top = 0;
	st->capcaity = 0;
	st->min = INT_MAX;
	return st;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top == obj->capcaity){
		if (obj->capcaity == 0){
			obj->capcaity = 10;
		}
		else{
			int newcapacity = obj->capcaity * 2;
			obj->capcaity = newcapacity;
		}
		obj->array = (int*)realloc(obj->array, sizeof(int)*obj->capcaity);
	}
	if (x < obj->min){
		obj->min = x;
	}
	obj->array[obj->top++] = x;
}

void minStackPop(MinStack* obj) {
	if (obj == NULL || obj->top == 0){
		return;
	}
	//int top = obj->array[obj->top-1];
	if (obj->array[obj->top - 1] == obj->min){
		obj->top--;
		int min = INT_MAX;
		for (int i = 0; i<obj->top; i++){
			if (obj->array[i] < min){
				min = obj->array[i];
			}
		}
		obj->min = min;
	}
	else{
		obj->top--;
	}
}

int minStackTop(MinStack* obj) {
	return obj->array[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj->array);
	obj->top = 0;
	obj->capcaity = 0;
	obj->min = 0;
}

int main( ){
	MinStack* st = minStackCreate();
	minStackPush(&st, 1);
	minStackPush(&st, 2);
	//minStackPush(&st, 3);
	//minStackPush(&st, 5);
	//minStackPush(&st, 6);
	printf("%d\n", minStackGetMin(&st));

	//minStackFree(&st);

	system("pause");
	return 0;

}