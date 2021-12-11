#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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


//层序遍历
void level_Order(TreeNode *root){
	if (root == NULL)
		return;

	TreeNode *cur = root;
	queue<TreeNode*> qu;
	qu.push(cur);
	while (!qu.empty()){
		cur = qu.front();
		printf("%d ", cur->val);
		qu.pop();
		if (cur->left != NULL)
			qu.push(cur->left);
		if (cur->right != NULL)
			qu.push(cur->right);
	}
}

//二叉搜索树的插入
bool BST_Insert(TreeNode *root, int key){
	if (root == NULL){
		TreeNode *newroot = new TreeNode(key);
		return newroot;
	}
	if (key < root->val){
		return BST_Insert(root->left, key);
	}
	else if (key > root->val){
		return BST_Insert(root->right, key);
	}
	return false;
}


//二叉搜索树的查找
TreeNode *BST_Search(TreeNode *root, int key){
	if (root == NULL)
		return NULL;
	if (root->val == key)
		return root;
	if (key < root->val)
		return BST_Search(root->left, key);
	else if (key > root->val)
		return BST_Search(root->right, key);
	else
		return NULL;
}

//构造二叉搜索树
TreeNode *BST_Create(TreeNode *root, int *arr, int n){
	for (int i = 0; i < n; i++){
		BST_Insert(root, arr[i]);
	}
	return root;
}

int main(){
	TreeNode *root = NULL;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	TreeNode *t = BST_Create(root, arr, 6);
	level_Order(t);
	system("pause");
	return 0;
}