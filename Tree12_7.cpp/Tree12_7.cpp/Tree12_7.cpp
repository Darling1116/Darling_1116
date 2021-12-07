
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

TreeNode *bulidTree2(){
	//�ֶ������̶��Ķ�����
	TreeNode *A = new TreeNode(1);
	TreeNode *B = new TreeNode(2);
	TreeNode *C = new TreeNode(3);
	TreeNode *D = new TreeNode(4);
	TreeNode *E = new TreeNode(5);
	TreeNode *F = new TreeNode(8);
	A->left = B;
	A->right = C;
	B->right = D;
	C->right = E;
	D->left = F;
	return A;  //���ظ��ڵ�
}


//��α���
void levelOrder(TreeNode *root){
	if (root == NULL)
		return;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);  //���ڵ������

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


//�ж�һ�����ǲ�����ȫ������
bool isComplementTree(TreeNode *root){
	//�����ڵ�Ϊ�ջ�����ֻ��һ�����ڵ㣬��Ϊ��ȫ������
	if (root == NULL)
		return true;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);  //���ڵ������

	while (!qu.empty()){
		cur = qu.front();
		qu.pop();
		if (cur != NULL){
			qu.push(cur->left);
			qu.push(cur->right);
		}
		else{
			break;  //�����˿ս�㣬�˳�ѭ��
		}
	}

	//�������Ϊ���ӽ��Ϊ�ղŷ��صģ���Ҫ�ж϶������Ƿ��зǿ�Ԫ��
	while (!qu.empty()){
		TreeNode *p = qu.front();
		if (p != NULL)
			return false;
		else
			qu.pop();
	}
	return true;
}


//�ݹ��㷨
int Hight(TreeNode *root){
	if (root == NULL)
		return 0;
	return Hight(root->left) > Hight(root->right) ? Hight(root->left) + 1 : Hight(root->right) + 1;
}

bool isComplementTree2(TreeNode *root){
	//1. �����ڵ�Ϊ�ջ�����ֻ��һ�����ڵ㣬��Ϊ��ȫ������
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	//2. �ý�����������������ȫ���������������������ĸ߶Ȳ����1
	return isComplementTree2(root->left) && isComplementTree2(root->right) &&
		abs(Hight(root->left) - Hight(root->right)) == 1;

}


//�ж�һ�����Ƿ�����������
bool isFullTree(TreeNode *root){
	//1. �����ڵ�Ϊ�ջ�����ֻ��һ�����ڵ㣬��Ϊ��������
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	//2. �ý��������������������������������������ĸ߶����
	return isFullTree(root->left) && isFullTree(root->right) &&
		Hight(root->left) == Hight(root->right);
}


//�ж��ǲ������ƶ�����
bool isSimilarTree(TreeNode *t1, TreeNode *t2){
	if (t1 == NULL && t2 == NULL) //��Ϊ����
		return true;
	if (t1 == NULL&&t2 != NULL || t1 != NULL&&t2 == NULL) //һ����Ϊ�գ���һ�����ǿ�
		return false;
	return isSimilarTree(t1->left, t2->left) && isSimilarTree(t1->right, t2->right);
}


//�ж��ǲ�����ͬ������
bool isSameTree(TreeNode *t1, TreeNode *t2){
	if (t1 == NULL && t2 == NULL)
		return true;
	if ((t1 == NULL&&t2 != NULL || t1 != NULL&&t2 == NULL) || (t1->val != t2->val))
		return false;
	return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

int main(){
	TreeNode *root = bulidTree();
	TreeNode *root2 = bulidTree2();

	printf("������1�Ĳ�α���Ϊ��\n");
	levelOrder(root);
	printf("\n");
	printf("������2�Ĳ�α���Ϊ��\n");
	levelOrder(root2);
	printf("\n");

	printf("������1�Ƿ�Ϊ��ȫ��������%d\n", isComplementTree(root));
	
	printf("������1�Ƿ�Ϊ��ȫ��������%d\n", isComplementTree2(root));

	printf("������1�Ƿ�Ϊ����������%d\n", isFullTree(root));

	printf("�Ƿ������ƶ�������%d\n", isSimilarTree(root, root2));

	printf("�Ƿ�����ͬ��������%d\n", isSameTree(root, root2));

	system("pause");
	return 0;

}