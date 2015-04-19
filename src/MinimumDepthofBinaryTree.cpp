//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
		return minDepth(root,false);
    }
private:
	int minDepth(TreeNode *root,bool hasBro){
		if(root==NULL)
			return hasBro?INT_MAX:0;
		return 1+min(minDepth(root->left,root->right!=NULL),minDepth(root->right,
			root->left!=NULL));
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

	result = solute.minDepth(root);
	//cout<<false&&false;
	//cout<<true&&true;
	return 0;
}