//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//return its bottom-up level order traversal as:
//
//[
//  [15,7],
//  [9,20],
//  [3]
//]



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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
		if(root==NULL)
			return result;
		queue<TreeNode *> current_level,next_level;
		vector<int> level;

		current_level.push(root);
		while(!current_level.empty()){
			while(!current_level.empty()){
				TreeNode * temp = current_level.front();
				current_level.pop();
				level.push_back(temp->val);
				if(temp->left!=NULL)next_level.push(temp->left);
				if(temp->right!=NULL)next_level.push(temp->right);
				//将当前层的值压入stack
				//将子节点压入下一层队列
			}
			result.push_back(level);//backup
			level.clear();
			swap(current_level,next_level);//交换下一层队列与当前队列
		}
		reverse(result.begin(),result.end());//逆序输出
		return result;
    }
};

int main()
{
	Solution solute;
	vector<vector<int> > result;
	TreeNode *root =new TreeNode(3);
	TreeNode *rnode =new TreeNode(20);
	TreeNode *rrnode =new TreeNode(7);
	TreeNode *lnode =new TreeNode(9);
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = llnode;

	result = solute.levelOrder(root);
	return 0;
}