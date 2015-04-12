//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(begin(preorder),end(preorder),begin(inorder),end(inorder));
    }
private:
	TreeNode *buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_end,
		vector<int>::iterator inorder_first,vector<int>::iterator inorder_end)
	{
		if(pre_first==pre_end)
			return NULL;
		if(inorder_first==inorder_end)
			return NULL;
		TreeNode *root = new TreeNode(*pre_first);

		auto in_rootPos = find(inorder_first,inorder_end,*pre_first);
		auto left_size = distance(inorder_first,in_rootPos);

		root->left = buildTree(next(pre_first),next(pre_first,left_size+1),inorder_first,
			next(inorder_first,left_size));
		root->right = buildTree(next(pre_first,left_size+1),pre_end,next(inorder_first,left_size+1)
			,inorder_end);

		return root;
	}
};
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//
int main()
{
	int pre[]={1,2,3,4,5,6};
	int inorder[]={3,2,4,1,5,6};
	vector<int> pre_order(pre,pre+sizeof(pre)/sizeof(pre[0]));
	vector<int> in_order(inorder,inorder+sizeof(inorder)/sizeof(inorder[0]));
	TreeNode *root=NULL;
	Solution solute;
	bool result;

	root = solute.buildTree(pre_order,in_order);

	return 0;
}