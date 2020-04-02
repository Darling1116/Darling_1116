#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>


int isValid(char* s){
	if (strlen(s) % 2 == 1 ){
		return 2;
	}
	if (s[0] == '}' || s[0] == ']' || s[0] == ')'){
		return 2;
	}
	int slen = strlen(s);
	char* stack = (char*)malloc(sizeof(char)*slen);
	int count = 0;

	for (int i = 0; i < slen; i++){
		if (stack[i] == '(' || stack[i] == '{' || stack[i] == '['){
			stack[count++] = s[i];
		}
		else{
			if (stack[count - 1] == '('&&s[i] == ')' ||
				stack[count - 1] == '{'&&s[i] == '}' ||
				stack[count - 1] == '['&&s[i] == ']'){
				--count;
			}
			else{
				return 2;
			}
		}
	}
	if (count == 0){
		return 1;
	}
	else{
		return 2;
	}
}


int main(){
	char* s = "[]";
	int i = isValid(s);
	printf("%d\n", i);
	system("pause");
	return 0;
}