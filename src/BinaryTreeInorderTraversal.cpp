//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,3,2].
//
//Note: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <algorithm>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
		TreeNode *temp;
		stack<TreeNode *> stk;

		temp = root;
		
		while(!stk.empty()||temp!=NULL)
		{
			if(temp!=NULL)
			{
				stk.push(temp);
				temp = temp->left;
			}
			else{
				temp = stk.top();
				stk.pop();
				result.push_back(temp->val);
				temp = temp->right;
			}
		}
		return result;
    }
};

int main()
{
	Solution solute;
	vector<int> result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(2);
	TreeNode *lnode =new TreeNode(3);

	root->right = rnode;
	rnode->left = lnode;

	result = solute.inorderTraversal(root);
	return 0;
}