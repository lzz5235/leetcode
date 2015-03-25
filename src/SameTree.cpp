// Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 


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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL)
			return true;
		if(!(p&&q)==true)
			return false;
		return p->val==q->val &&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

int main()
{
	Solution solute;
	bool result;
	TreeNode *root =new TreeNode(3);
	TreeNode *rnode =new TreeNode(20);
	TreeNode *rrnode =new TreeNode(15);
	TreeNode *lnode =new TreeNode(9);
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = llnode;

	result = solute.isSameTree(root,root);
	return 0;
}