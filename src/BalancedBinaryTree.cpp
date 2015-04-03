//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 


#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
		return Height(root) >= 0;  
    }
private:
	int Height(TreeNode *root){
		if(root==NULL)
			return 0;
		int left = Height(root->left);
		int right = Height(root->right);

		if(left<0||right<0||abs(left-right)>1)
			return -1;
		return max(left,right)+1;
	}
};

int main()
{
	Solution solute;
	bool result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(2);
	TreeNode *lnode =new TreeNode(2);
	
	TreeNode *rrnode =new TreeNode(15);
	
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
//	rrnode->left = llnode;

	result = solute.isBalanced(root);
	//cout<<false&&false;
	//cout<<true&&true;
	return 0;
}