//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
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
    bool isValidBST(TreeNode *root) {
		return check(root,INT32_MIN,INT32_MAX);
    }
private:
	bool check(TreeNode *root,int left,int right)
	{
		if(root==NULL)
			return true;
		return root->val < right && root->val > left && check(root->left,left,root->val)
			&& check(root->right,root->val,right);
	}
};

int main()
{
	Solution solute;	
	bool result;
	
	TreeNode *root =new TreeNode(3);
	TreeNode *rnode =new TreeNode(20);
	TreeNode *rrnode =new TreeNode(7);
	TreeNode *lnode =new TreeNode(9);
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = llnode;
	result = solute.isValidBST(root);

	return 0;
}