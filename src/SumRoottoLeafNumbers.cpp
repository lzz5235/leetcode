//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode *root) {
		return DFS(root,0);        
    }
	int DFS(TreeNode *root,int sum)
	{
		if(root==NULL)
			return 0;
		if(root->left==NULL&&root->right==NULL)
			return sum*10+root->val;
		return DFS(root->left,sum*10+root->val)+
			DFS(root->right,sum*10+root->val);
	}
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(begin(inorder),end(inorder),begin(postorder),end(postorder));
    }
private:
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
//        / \
//       2   5
//      / \   \
//     3   4   6
//
int main()
{
	int pre[]={1,2,3,4,5,6};
	int inorder[]={3,2,4,1,5,6};
	int postorder[]={3,4,2,6,5,1};
	vector<int> pre_order(pre,pre+sizeof(pre)/sizeof(pre[0]));
	vector<int> in_order(inorder,inorder+sizeof(inorder)/sizeof(inorder[0]));
	vector<int> post_order(postorder,postorder+sizeof(postorder)/sizeof(postorder[0]));
	TreeNode *root=NULL;
	Solution solute;
	bool result;

	root = solute.buildTree(in_order,post_order);
	int sum = solute.sumNumbers(root);
	return 0;
}