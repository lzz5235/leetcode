// Given a binary tree
//
//    struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//    }
//
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//    You may only use constant extra space.
//    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//
//For example,
//Given the following perfect binary tree,
//
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//
//After calling your function, the tree should look like:
//
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL


#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode *> current_level,next_level;
		if(root==NULL)
			return;
		current_level.push(root);

		while(!current_level.empty()){
			while(!current_level.empty()){
				auto temp = current_level.front();
				current_level.pop();
				if(!current_level.empty())
					temp->next = current_level.front();
				if(temp->left)
					next_level.push(temp->left);
				if(temp->right)
					next_level.push(temp->right);
			}
			swap(current_level,next_level);			
		}
    }
};

int main()
{
	Solution solute;
	int result;
	TreeLinkNode *root =new TreeLinkNode(1);
	TreeLinkNode *rnode =new TreeLinkNode(3);
	TreeLinkNode *lnode =new TreeLinkNode(2);
	
	TreeLinkNode *rrnode =new TreeLinkNode(7);
	TreeLinkNode *rlnode =new TreeLinkNode(6);
	TreeLinkNode *llnode =new TreeLinkNode(4);
	TreeLinkNode *lrnode =new TreeLinkNode(5);

	root->right = rnode;
	root->left = lnode;
	rnode->left = rlnode;
	rnode->right = rrnode;
	lnode->left = llnode;
	lnode->right = lrnode;

	solute.connect(root);

	return 0;
}