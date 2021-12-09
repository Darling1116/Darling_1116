#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <queue>

using namespace std;

typedef struct TreeNode{
	char val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(){
		val = NULL;
		left = NULL;
		right = NULL;
	}

	TreeNode(char x){
		val = x;
		left = NULL;
		right = NULL;
	}
}TreeNode, Tree;


void levelOrder(TreeNode *root){
	if (root == NULL)
		return;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);
	while (!qu.empty()){
		cur = qu.front();
		printf("%c ", cur->val);
		qu.pop();
		if (cur->left != NULL)
			qu.push(cur->left);
		if (cur->right != NULL)
			qu.push(cur->right);
	}
}


void Print(int *order, int n){
	for (int i = 0; i < n; i++)
		printf("%c ", order[i]);
	printf("\n");
}



//�����������������й��������
int findIndexOfInorder(int *inorder, int inbegin, int inend, char x){
	for (int i = inbegin; i <= inend; i++){
		if (inorder[i] == x)
			return i;
	}
	return -1; //û������������������ҵ��ý��
}


int preIndex = 0;

struct TreeNode* buildTreeChild(int *preorder, int *inorder, int inbegin, int inend){
	if (inbegin>inend)
		return NULL;

	//1.����ȡǰ������ĵ�һ��������������
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[preIndex];


	//2.Ȼ��ȥ���������Ѱ�Ҹý�㣬����Ϊ����������������㣬����Ϊ�����������������
	int rootIndex = findIndexOfInorder(inorder, inbegin, inend, preorder[preIndex]);
	preIndex++;
	if (rootIndex == -1)
		return NULL;

	//3.���ν���root����������������
	root->left = buildTreeChild(preorder, inorder, inbegin, rootIndex - 1);
	root->right = buildTreeChild(preorder, inorder, rootIndex + 1, inend);
	return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if (preorder == NULL || inorder == NULL)
		return NULL;
	if (preorderSize <= 0 || inorderSize <= 0)
		return NULL;
	return buildTreeChild(preorder, inorder, 0, inorderSize - 1);
}




//������ͺ���������й��������
int postIndex = 0;

struct TreeNode* buildTreeChild2(int *postorder, int *inorder, int inbegin, int inend){
	if (inbegin>inend)
		return NULL;

	//1.����ȡ��������ĵ�һ��������������
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[postIndex];


	//2.Ȼ��ȥ���������Ѱ�Ҹý��
	int inIndex = findIndexOfInorder(inorder, inbegin, inend, postorder[postIndex]);
	postIndex--;
	if (inIndex == -1)
		return NULL;

	//3.���ν���root����������������
	root->right = buildTreeChild2(postorder, inorder, inIndex + 1, inend);
	root->left = buildTreeChild2(postorder, inorder, inbegin, inIndex - 1);
	return root;
}


struct TreeNode* buildTree2(int* postorder, int postorderSize, int* inorder, int inorderSize){
	if (postorder == NULL || inorder == NULL)
		return NULL;
	if (postorderSize <= 0 || inorderSize <= 0)
		return NULL;
	postIndex = postorderSize - 1;
	return buildTreeChild2(postorder, inorder, 0, inorderSize - 1);
}

 

int main(){
	
	int preorder[8] = {'A', 'B', 'D', 'E', 'G', 'C', 'F', 'H'};
	int inorder[8] = { 'D', 'B', 'E', 'G', 'A', 'F', 'H', 'C'};
	printf("preorder������Ϊ��");
	Print(preorder, 8);
	printf("inorder������Ϊ��");
	Print(inorder, 8);

	TreeNode *root = buildTree(preorder, 8, inorder, 8);
	printf("�Ӹ����������������й���Ķ�����Ϊ��");
	levelOrder(root);

	printf("\n");
	
	
	int inorder2[4] = { 'B', 'C', 'A', 'D' };
	int postorder2[4] = { 'C', 'B', 'D', 'A' };
	printf("inorder������Ϊ��");
	Print(inorder2, 4);
	printf("postorder������Ϊ��");
	Print(postorder2, 4);

	TreeNode *root2 = buildTree2(postorder2, 4, inorder2, 4);
	printf("�Ӹ�����ͺ���������й���Ķ�����Ϊ��");
	levelOrder(root2);
	
	system("pause");
	return 0;
}