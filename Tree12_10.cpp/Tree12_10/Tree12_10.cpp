#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <queue>
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
	//�ֶ������̶��Ķ�����
	TreeNode *A = new TreeNode(4);
	TreeNode *B = new TreeNode(1);
	TreeNode *C = new TreeNode(5);
	TreeNode *D = new TreeNode(3);
	TreeNode *E = new TreeNode(6);
	TreeNode *F = new TreeNode(2);
	A->left = B;
	A->right = C;
	B->right = D;
	C->right = E;
	D->left = F;
	return A;  //���ظ��ڵ�
}


void levelOrder(TreeNode *root){
	if (root == NULL)
		return;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
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


//�ж��Ƿ�Ϊ����������
int last = LONG_MIN;
bool isValidBST2(TreeNode* root){
	if (root == NULL)
		return true;

	stack<TreeNode*> st;
	TreeNode *cur = root;
	while (cur != NULL || !st.empty()){
		while (cur != NULL){
			st.push(cur);
			cur = cur->left;
		}

		cur = st.top();
		st.pop();
		if (cur->val <= last){
			return false;
		}
		last = cur->val;
		cur = cur->right;
	}
	return true;
}

//�ݹ�
bool isValidBST(TreeNode* root){
	if (root == NULL)
		return true;
	if (isValidBST(root->left)){
		if (last < root->val){
			last = root->val;
			return isValidBST(root->right);
		}
	}
	return false;
}


//����һ������������, �ҵ�����������ָ���ڵ�������������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL)
		return NULL;
	if (p == root || q == root)
		return root;
	if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);
	if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}


int main(){
	TreeNode *root = bulidTree();
	//printf("�Ƿ�Ϊ������������%d\n", isValidBST(root));
	printf("�Ƿ�Ϊ������������%d\n", isValidBST2(root));

	TreeNode *p = new TreeNode(1);
	TreeNode *q = new TreeNode(6);
	printf("1��6�������������Ϊ��%d\n", lowestCommonAncestor(root, p, q)->val);
	system("pause");
	return 0;
}