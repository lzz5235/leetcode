//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    int countNodes(TreeNode* root) {
		if(!root) 
			return 0;
		int hl=0, hr=0;
		TreeNode *left=root, *right=root;
		while(left) {
			hl++;
			left=left->left;
		}
		while(right){
			hr++;
			right=right->right;
		}

		if(hl==hr) 
			return pow(2,hl)-1;
		return 1+countNodes(root->left)+countNodes(root->right);       
    }

TreeNode *buildTree(vector<int>::iterator inorder_first,vector<int>::iterator inorder_end,
	vector<int>::iterator postorder_first,vector<int>::iterator postorder_end)
	{
		if(postorder_first==postorder_end)
			return NULL;
		if(inorder_first==inorder_end)
			return NULL;
		int val = *prev(postorder_end);
		TreeNode *root = new TreeNode(val);

		auto in_rootPos = find(inorder_first,inorder_end,val);
		auto left_size = distance(inorder_first,in_rootPos);

		root->left = buildTree(inorder_first,next(inorder_first,left_size),postorder_first,
			next(postorder_first,left_size));
		root->right = buildTree(next(inorder_first,left_size+1),inorder_end,next(postorder_first,left_size)
			,prev(postorder_end));

		return root;
	}
};


//
//         1
//        /  \
//       2    5
//      / \   /
//     3  4  6  
//
int main()
{
	int pre[]={1,2,3,4,5,6};
	int inorder[]={3,2,4,1,6,5};
	int postorder[]={3,4,2,6,5,1};
	vector<int> pre_order(pre,pre+sizeof(pre)/sizeof(pre[0]));
	vector<int> in_order(inorder,inorder+sizeof(inorder)/sizeof(inorder[0]));
	vector<int> post_order(postorder,postorder+sizeof(postorder)/sizeof(postorder[0]));
	TreeNode *root=NULL;
	Solution solute;
	bool result;

	root = solute.buildTree(in_order.begin(),in_order.end(),post_order.begin(),post_order.end());
	int sum = solute.countNodes(root);
	return 0;
}