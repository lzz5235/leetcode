//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//
//But the following is not:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
//
//Note:
//Bonus points if you could solve it both recursively and iteratively. 


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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
			return true;
		stack<TreeNode *> stk;
		stk.push(root->left);
		stk.push(root->right);

		while(!stk.empty()){
			TreeNode *p = stk.top();stk.pop();
			TreeNode *q = stk.top();stk.pop();

			if(!p && !q) //p q not exist,continue
				continue;
			if(!p || !q) // p exist while q not exist or reverse
				return false;
			if(p->val!=q->val)
				return false;

			stk.push(p->left);
			stk.push(q->right);

			stk.push(p->right);
			stk.push(q->left);
		}
		return true;
    }
};


int main()
{
	Solution solute;
	bool result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(2);
	TreeNode *lnode =new TreeNode(2);
	
	TreeNode *rrnode =new TreeNode(15);
	
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	lnode->left = llnode;

//	result = solute.isSymmetric(root);
	//cout<<false&&false;
	//cout<<true&&true;
	return 0;
}