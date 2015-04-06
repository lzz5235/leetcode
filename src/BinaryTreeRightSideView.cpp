//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//For example:
//Given the following binary tree,
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
//You should return [1, 3, 4].
//
//Credits:
//Special thanks to @amrsaqr for adding this problem and creating all test cases.


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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
		if(root==NULL)
			return result;
		queue<TreeNode *> current_level,next_level;
		vector<int> level;

		current_level.push(root);
		while(!current_level.empty()){
			result.push_back(current_level.back()->val);
			while(!current_level.empty()){
				TreeNode * temp = current_level.front();
				current_level.pop();

				if(temp->left!=NULL)next_level.push(temp->left);
				if(temp->right!=NULL)next_level.push(temp->right);
				//将当前层的值压入stack
				//将子节点压入下一层队列
			}
			swap(current_level,next_level);//交换下一层队列与当前队列
		}
		return result;
    }
};

int main()
{
	Solution solute;
	vector<int> result;
	TreeNode *root =new TreeNode(1);
	TreeNode *rnode =new TreeNode(3);
	TreeNode *lnode =new TreeNode(2);
	
	TreeNode *rrnode =new TreeNode(7);
//	TreeNode *rlnode =new TreeNode(6);
	TreeNode *llnode =new TreeNode(4);
	TreeNode *lrnode =new TreeNode(5);

	root->right = rnode;
	root->left = lnode;
//	rnode->left = rlnode;
	rnode->right = rrnode;
	lnode->left = llnode;
	lnode->right = lrnode;

	result = solute.rightSideView(root);

	return 0;
}