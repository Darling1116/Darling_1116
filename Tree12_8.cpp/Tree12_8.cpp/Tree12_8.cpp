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


//找树中p，q结点的最近公共祖先
TreeNode *ComAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
	if (root == NULL)
		return NULL;
	if (p == root || q == root)
		return root;
	//分别在左右子树中查找p，q
	TreeNode *leftNode = ComAncestor(root->left, p, q);
	TreeNode *rightNode = ComAncestor(root->right, p, q);
	if (leftNode != NULL && rightNode != NULL) //左右子树中都找到了
		return root;
	else if (leftNode != NULL) //在左子树中找到了
		return leftNode;
	else if (rightNode != NULL) //在右子树中找到了
		return rightNode;
	else  //都没找到
		return NULL;
}


//打印树中值为x的元素结点的所有祖先（采用后序遍历+栈）
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
		if (cur->val == x){ //当前结点的值为x，输出栈中所有的元素（即，该结点的所有公共祖先）
			st.pop();//先打当前值为x的结点从栈中取出
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
	printf("二叉树1的层次遍历序列为：\n");
	levelOrder(root);
	printf("\n");

	/*
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(3);
	printf("%d", ComAncestor(root, p, q)->val);
	*/

	printf("二叉树1中5的所有祖先为：\n");
	printAllAncestor(root, 5);

	system("pause");
	return 0;
}
