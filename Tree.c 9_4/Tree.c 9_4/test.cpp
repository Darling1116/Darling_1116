#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stdlib.h>
#include <Query.h>
using namespace std;

//判断一棵树是否为完全二叉树

//无论当前结点有没有孩子，都让其左右孩子入队列
//当得到第一个为NULL的结点时，判断队列里有没有非空结点
//如果有的话就不是完全二叉树
bool LevelOrder(Tree& T){
	if (T == NULL){
		return 0;
	}
	queue<TreeNode*> q;
	q.push(T);
	while (!q.empty()){
		TreeNode* node = q.front();
		q.pop();
		if (node != NULL){
			q.push(node->left);
			q.push(node->right);
		}
		else{//当node为空时，检测队列中是否有非空结点
			while (!q.empty()){
				node = q.front();
				q.pop();
				if (node != NULL)
		//队列中有非空结点，不是完全二叉树
					return false;
			}
		}
	}
	return true;

}

int main(){

	system("pause");
	return 0;
}