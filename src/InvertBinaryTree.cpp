//Invert a binary tree.
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//to
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
//Trivia:
//This problem was inspired by this original tweet by Max Howell:
//Google: 90% of our engineers use the software you wrote (Homebrew), but you can¡¯t invert a binary tree on a whiteboard so fuck off.


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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) 
			return NULL;
		swap(root->left,root->right);
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		return root;
    }
};

int main()
{
	TreeNode *root =new TreeNode(4);
	TreeNode *rnode =new TreeNode(7);
	TreeNode *rrnode =new TreeNode(9);
	TreeNode *rlnode =new TreeNode(6);
	TreeNode *lnode =new TreeNode(2);
	TreeNode *llnode =new TreeNode(1);
	TreeNode *lrnode =new TreeNode(3);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = rlnode;
	lnode->left = llnode;
	lnode->right = lrnode;

	Solution solution;
	root = solution.invertTree(root);

	return 0;
}