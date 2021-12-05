#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(){
		val = NULL;
		left = NULL;
		right = NULL;
	}

	TreeNode(int x){
		val = x;
		left = NULL;
		right = NULL;
	}
}TreeNode, Tree;


TreeNode *bulidTree(){
	//手动建立固定的二叉树
	TreeNode *A = new TreeNode(1);
	TreeNode *B = new TreeNode(2);
	TreeNode *C = new TreeNode(3);
	TreeNode *D = new TreeNode(4);
	TreeNode *E = new TreeNode(5);
	TreeNode *F = new TreeNode(6);
	A->left = B;
	A->right = C;
	B->right = D;
	C->right = E;
	D->left = F;
	return A;  //返回根节点
}


//前序遍历
void preorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	printf("%d ", root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

//非递归
void preorderTraversal2(TreeNode *root) {
	if (root == NULL)
		return;
	
	stack<TreeNode*> st;
	TreeNode *cur = root;

	while (cur!=NULL || !st.empty()){
		while (cur != NULL){
			//cur不为空时，输出当前结点，并让当前结点入栈，然后一直往左走
			printf("%d ", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		//取栈顶元素（并删除），让cur指向该栈顶元素的右孩子
		TreeNode *top = st.top();
		st.pop();
		cur = top->right;
	}
}


//中序遍历
void inorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d ", root->val);
	inorderTraversal(root->right);
}

//非递归
void inorderTraversal2(TreeNode *root) {
	if (root == NULL)
		return;

	stack<TreeNode*> st;
	TreeNode *cur = root;

	while (cur != NULL || !st.empty()){
		//cur不为空时，让当前结点入栈,，然后一直往左走
		while (cur != NULL){
			st.push(cur);
			cur = cur->left;
		}

		//取栈顶元素（并删除），然后输出该栈顶元素，并cur指向该栈顶元素的右孩子
		TreeNode *top = st.top();
		st.pop();
		printf("%d ", top->val);
		cur = top->right;

	}

}

//后序遍历
void postorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->val);
}

//非递归
void postorderTraversal2(TreeNode *root) {
	if (root == NULL)
		return;

	stack<TreeNode*> st;
	TreeNode *cur = root;
	TreeNode *prev = NULL;
	while (cur != NULL || !st.empty()){
		while (cur != NULL){
			st.push(cur);
			cur = cur->left;
		}

		cur = st.top();  //取cur为栈顶元素
		if (cur->right == NULL || cur->right == prev){
			//cur的右孩子为空，或者右孩子已经被访问过，就输出cur，栈顶元素出栈，更新prev
			printf("%d ", cur->val);
			st.pop();
			prev = cur;
			cur = NULL;
		}
		else{
			////cur的右孩子不为空，让cur指向其右孩子
			cur = cur->right;
		}
	}
}


int main(){
	Tree t;
	TreeNode *root = bulidTree();

	printf("前序遍历序列为：\n");
	preorderTraversal(root);
	printf("\n");
	preorderTraversal2(root);
	printf("\n");

	printf("中序遍历序列为：\n");
	inorderTraversal(root);
	printf("\n");
	inorderTraversal2(root);
	printf("\n");

	printf("后序遍历序列为：\n");
	postorderTraversal(root);
	printf("\n");
	postorderTraversal2(root);
	printf("\n");
	/*
	stack<TreeNode*> st;
	TreeNode *p = new TreeNode(10);
	st.push(p);
	while (!st.empty()){	
		printf("%d ", st.top()->val);
		st.pop();
	}
	*/

	system("pause");
	return 0;
}

