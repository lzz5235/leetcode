//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,2,3].
//
//Note: Recursive solution is trivial, could you do it iteratively?
//先序遍历：中-左-右

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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		TreeNode *temp;
		stack<TreeNode *> stk;

		temp = root;
		if(temp!=NULL)
			stk.push(temp);

		while(!stk.empty())
		{
			temp = stk.top();
			stk.pop();
			result.push_back(temp->val);
			
			if(temp->right!=NULL) 
				stk.push(temp->right);
			if(temp->left!=NULL) 
				stk.push(temp->left);
			//先序遍历：中-左-右
			//入栈顺序是：中入-中出-右-左
			//出栈顺序是：左出-...右出
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

	result = solute.preorderTraversal(root);
	return 0;
}