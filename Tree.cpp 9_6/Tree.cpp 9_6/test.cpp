#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		long pre = LONG_MIN;
		//给的范围大点
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (!s.empty() || p != NULL){
			//如果当前结点没有有孩子，栈里还有元素，就再次取栈顶元素
			while (p != NULL){
				s.push(p);
				p = p->left;
				//走到最左结点
			}
			p = s.top();//取栈顶元素
			s.pop();
			if (p->val <= pre)
				return false;
			pre = p->val;
			p = p->right;
		}
		return true;
	}
};


int main(){
	system("pause");
	return 0;
}