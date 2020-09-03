#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//判断是否为平衡二叉树
int Height(TreeNode* root){
	if (root == NULL)
		return 0;
	return //max(Height(root->left), Height(root->right)) + 1;
	//左右子树的高度差不大于1
	Height(root->left)>Height(root->right)?Height(root->left)+1:Height(root->right)+1;
}

int isBalanced(TreeNode* root) {
	if (root == NULL)
		return 1;
	return abs(Height(root->left) - Height(root->right)) <= 1
		&& isBalanced(root->left) && isBalanced(root->right);
}

int main(){

}