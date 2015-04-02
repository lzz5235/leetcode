//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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
    int maxDepth(TreeNode *root) {
		if(root==NULL)
			return 0;
		return  max(maxDepth(root->left),maxDepth(root->right))+1;   
    }
};

int main()
{
	Solution solute;
	int result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(2);
	TreeNode *lnode =new TreeNode(2);
	
	TreeNode *rrnode =new TreeNode(15);
	
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	lnode->left = llnode;

	result = solute.maxDepth(root);
	//cout<<false&&false;
	//cout<<true&&true;
	return 0;
}