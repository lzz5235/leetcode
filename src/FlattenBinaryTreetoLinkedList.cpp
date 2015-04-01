// Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//
//The flattened tree should look like:
//
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6


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
//preoreder tree!
class Solution {
public:
    void flatten(TreeNode *root) {
		stack<TreeNode *> stk;
		if(root==NULL)
			return;
		stk.push(root);

		while(!stk.empty()){
			auto temp = stk.top();
			stk.pop();

			if(temp->right!=NULL)
				stk.push(temp->right);
			if(temp->left!=NULL)
				stk.push(temp->left);

			temp->left=NULL;
			if(!stk.empty())
				temp->right = stk.top();
		}        
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
	Solution solute;
	bool result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(5);
	TreeNode *lnode =new TreeNode(2);
	TreeNode *llnode =new TreeNode(3);
	TreeNode *lrnode =new TreeNode(4);
	TreeNode *rrnode =new TreeNode(6);
	
	

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	lnode->left = llnode;
	lnode->right = lrnode;
	rnode->right = rrnode;

	solute.flatten(root);

	return 0;
}