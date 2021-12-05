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


//ǰ�����
void preorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	printf("%d ", root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

//�ǵݹ�
void preorderTraversal2(TreeNode *root) {
	if (root == NULL)
		return;
	
	stack<TreeNode*> st;
	TreeNode *cur = root;

	while (cur!=NULL || !st.empty()){
		while (cur != NULL){
			//cur��Ϊ��ʱ�������ǰ��㣬���õ�ǰ�����ջ��Ȼ��һֱ������
			printf("%d ", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		//ȡջ��Ԫ�أ���ɾ��������curָ���ջ��Ԫ�ص��Һ���
		TreeNode *top = st.top();
		st.pop();
		cur = top->right;
	}
}


//�������
void inorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d ", root->val);
	inorderTraversal(root->right);
}

//�ǵݹ�
void inorderTraversal2(TreeNode *root) {
	if (root == NULL)
		return;

	stack<TreeNode*> st;
	TreeNode *cur = root;

	while (cur != NULL || !st.empty()){
		//cur��Ϊ��ʱ���õ�ǰ�����ջ,��Ȼ��һֱ������
		while (cur != NULL){
			st.push(cur);
			cur = cur->left;
		}

		//ȡջ��Ԫ�أ���ɾ������Ȼ�������ջ��Ԫ�أ���curָ���ջ��Ԫ�ص��Һ���
		TreeNode *top = st.top();
		st.pop();
		printf("%d ", top->val);
		cur = top->right;

	}

}

//�������
void postorderTraversal(TreeNode *root) {
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->val);
}

//�ǵݹ�
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

		cur = st.top();  //ȡcurΪջ��Ԫ��
		if (cur->right == NULL || cur->right == prev){
			//cur���Һ���Ϊ�գ������Һ����Ѿ������ʹ��������cur��ջ��Ԫ�س�ջ������prev
			printf("%d ", cur->val);
			st.pop();
			prev = cur;
			cur = NULL;
		}
		else{
			////cur���Һ��Ӳ�Ϊ�գ���curָ�����Һ���
			cur = cur->right;
		}
	}
}


int main(){
	Tree t;
	TreeNode *root = bulidTree();

	printf("ǰ���������Ϊ��\n");
	preorderTraversal(root);
	printf("\n");
	preorderTraversal2(root);
	printf("\n");

	printf("�����������Ϊ��\n");
	inorderTraversal(root);
	printf("\n");
	inorderTraversal2(root);
	printf("\n");

	printf("�����������Ϊ��\n");
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

