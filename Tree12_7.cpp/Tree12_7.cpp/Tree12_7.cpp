
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

TreeNode *bulidTree2(){
	//手动建立固定的二叉树
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


//判断一棵树是不是完全二叉树
bool isComplementTree(TreeNode *root){
	//若根节点为空或者是只有一个根节点，都为完全二叉树
	if (root == NULL)
		return true;

	queue<TreeNode*> qu;
	TreeNode *cur = root;
	qu.push(cur);  //根节点先入队

	while (!qu.empty()){
		cur = qu.front();
		qu.pop();
		if (cur != NULL){
			qu.push(cur->left);
			qu.push(cur->right);
		}
		else{
			break;  //遇到了空结点，退出循环
		}
	}

	//如果是因为出队结点为空才返回的，就要判断队列中是否还有非空元素
	while (!qu.empty()){
		TreeNode *p = qu.front();
		if (p != NULL)
			return false;
		else
			qu.pop();
	}
	return true;
}


//递归算法
int Hight(TreeNode *root){
	if (root == NULL)
		return 0;
	return Hight(root->left) > Hight(root->right) ? Hight(root->left) + 1 : Hight(root->right) + 1;
}

bool isComplementTree2(TreeNode *root){
	//1. 若根节点为空或者是只有一个根节点，都为完全二叉树
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	//2. 该结点的左右子树都是完全二叉树，并且左右子树的高度差等于1
	return isComplementTree2(root->left) && isComplementTree2(root->right) &&
		abs(Hight(root->left) - Hight(root->right)) == 1;

}


//判断一棵树是否是满二叉树
bool isFullTree(TreeNode *root){
	//1. 若根节点为空或者是只有一个根节点，都为满二叉树
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	//2. 该结点的左右子树都是满二叉树，并且左右子树的高度相等
	return isFullTree(root->left) && isFullTree(root->right) &&
		Hight(root->left) == Hight(root->right);
}


//判断是不是相似二叉树
bool isSimilarTree(TreeNode *t1, TreeNode *t2){
	if (t1 == NULL && t2 == NULL) //都为空树
		return true;
	if (t1 == NULL&&t2 != NULL || t1 != NULL&&t2 == NULL) //一棵树为空，另一棵树非空
		return false;
	return isSimilarTree(t1->left, t2->left) && isSimilarTree(t1->right, t2->right);
}


//判断是不是相同二叉树
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

	printf("二叉树1的层次遍历为：\n");
	levelOrder(root);
	printf("\n");
	printf("二叉树2的层次遍历为：\n");
	levelOrder(root2);
	printf("\n");

	printf("二叉树1是否为完全二叉树：%d\n", isComplementTree(root));
	
	printf("二叉树1是否为完全二叉树：%d\n", isComplementTree2(root));

	printf("二叉树1是否为满二叉树：%d\n", isFullTree(root));

	printf("是否是相似二叉树：%d\n", isSimilarTree(root, root2));

	printf("是否是相同二叉树：%d\n", isSameTree(root, root2));

	system("pause");
	return 0;

}