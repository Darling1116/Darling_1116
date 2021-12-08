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


//������p��q���������������
TreeNode *ComAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
	if (root == NULL)
		return NULL;
	if (p == root || q == root)
		return root;
	//�ֱ������������в���p��q
	TreeNode *leftNode = ComAncestor(root->left, p, q);
	TreeNode *rightNode = ComAncestor(root->right, p, q);
	if (leftNode != NULL && rightNode != NULL) //���������ж��ҵ���
		return root;
	else if (leftNode != NULL) //�����������ҵ���
		return leftNode;
	else if (rightNode != NULL) //�����������ҵ���
		return rightNode;
	else  //��û�ҵ�
		return NULL;
}


//��ӡ����ֵΪx��Ԫ�ؽ����������ȣ����ú������+ջ��
void printAllAncestor(TreeNode *root, int x){
	if (root == NULL)
		return;

	TreeNode *cur = root;
	TreeNode *prev = NULL;
	stack<TreeNode*> st;

	while (cur != NULL || !st.empty()){
		while (cur != NULL){
			st.push(cur);
			cur = cur->left;
		}
		
		cur = st.top();
		if (cur->val == x){ //��ǰ����ֵΪx�����ջ�����е�Ԫ�أ������ý������й������ȣ�
			st.pop();//�ȴ�ǰֵΪx�Ľ���ջ��ȡ��
			while (!st.empty()){
				printf("%d ", st.top()->val);
				st.pop();
			}
		}
		else if (cur->right == NULL || cur->right == prev){
			st.pop();
			prev = cur;
			cur = NULL;
		}
		else{
			cur = cur->right;
		}
	}

}

int main(){

	TreeNode *root = bulidTree();
	printf("������1�Ĳ�α�������Ϊ��\n");
	levelOrder(root);
	printf("\n");

	/*
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(3);
	printf("%d", ComAncestor(root, p, q)->val);
	*/

	printf("������1��5����������Ϊ��\n");
	printAllAncestor(root, 5);

	system("pause");
	return 0;
}
