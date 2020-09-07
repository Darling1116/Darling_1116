#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//编写算法求左孩子右兄弟表示的树的高度


//孩子兄弟表示法的根节点没有右孩子
//所以其高度就是左子树的高度加1
//第一个孩子的右子树（兄弟）的高度和第一个孩子的高度是相同的
//所以比较左子树的高度+1  与 右子树的高度关系
//若左子树的高度+1 > 右子树的高度，取前者；否则取右者
int Height(TreeNode* root){
	if (root == NULL)
		return 0;
	return Height(root->left) + 1 > Height(root->right) ? Height(root->left) + 1 : Height(root->right);

}

int main(){
	system("pause");
	return 0;
}