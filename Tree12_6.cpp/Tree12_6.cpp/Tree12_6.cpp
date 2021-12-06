#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <queue>
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

//层次遍历
void levelOrder(TreeNode *root){
	if (root == NULL)
		return;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);  //根节点先入队

	while (!qu.empty()){
		cur = qu.front();
		printf("%d ", cur->val);
		qu.pop();
		if (cur->left != NULL){
			qu.push(cur->left);
		}
		if (cur->right != NULL){
			qu.push(cur->right);
		}
	}
}


//求二叉树结点个数
int getSize(TreeNode *root){
	if (root == NULL)
		return 0;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	int size = 0;
	qu.push(cur);  //根节点先入队

	while (!qu.empty()){
		cur = qu.front();
		qu.pop();
		size++;
		if (cur->left != NULL){
			qu.push(cur->left);
		}
		if (cur->right != NULL){
			qu.push(cur->right);
		}
	}
	return size;
}

//递归
int getSize2(TreeNode *root){
	if (root == NULL)
		return 0;
	return getSize2(root->left) + getSize2(root->right) + 1;
}


//求二叉树叶子结点个数
int getLeafSize(TreeNode *root){
	if (root == NULL)
		return 0;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	int size = 0;
	qu.push(cur);  //根节点先入队

	while (!qu.empty()){
		cur = qu.front();
		qu.pop();
		if (cur->left != NULL){
			qu.push(cur->left);
		}
		if (cur->right != NULL){
			qu.push(cur->right);
		}
		if (cur->left == NULL && cur->right == NULL){
			size++;
		}
	}
	return size;
}

//递归
int getLeafSize2(TreeNode *root){
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return getLeafSize2(root->left) + getLeafSize2(root->right);
}


//求树的高度
int getDepth(TreeNode *root){
	if (root == NULL)
		return 0;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);  //根节点先入队
	int depth = 0;

	while (!qu.empty()){
		int n = qu.size();  //获取当前队列中含有元素的个数

		for (int i = 0; i < n; i++){
			cur = qu.front();
			qu.pop();
			if (cur->left != NULL){
				qu.push(cur->left);
			}
			if (cur->right != NULL){
				qu.push(cur->right);
			}
		}
		depth++;  //每一层的结点访问完之后，depth加1
		
	}
	return depth;
}

//递归
int getDepth2(TreeNode *root){
	if (root == NULL)
		return 0;
	return getDepth(root->left) > getDepth(root->right) ? getDepth(root->left) + 1 : getDepth(root->right) + 1;

}


int main(){
	TreeNode *root = bulidTree();

	printf("层次遍历序列为：\n");
	levelOrder(root);
	printf("\n");

	int size = getSize(root);
	printf("二叉树结点个数为：%d\n", size);

	int size2 = getSize2(root);
	printf("二叉树结点个数为：%d\n", size2);

	int leafsize = getLeafSize(root);
	printf("二叉树结点个数为：%d\n", leafsize);

	int leafsize2 = getLeafSize2(root);
	printf("二叉树结点个数为：%d\n", leafsize2);

	int depth = getDepth(root);
	printf("二叉树的高度为：%d\n", depth);

	int depth2 = getDepth2(root);
	printf("二叉树的高度为：%d\n", depth2);

	system("pause");
	return 0;

}