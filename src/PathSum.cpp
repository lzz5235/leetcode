//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//For example:
//Given the below binary tree and sum = 22,
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
//
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

//http://en.wikipedia.org/wiki/Tree_traversal


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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
			return false;
		if(root->left==NULL&&root->right==NULL)
			return root->val==sum;
		
		return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
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

	result = solute.hasPathSum(root,38);
	return 0;
}