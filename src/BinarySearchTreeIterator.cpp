//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.


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
 
 
class BSTIterator {
public:
	stack<TreeNode *> stk;
	TreeNode *current;
    BSTIterator(TreeNode *root) {
		current = NULL;
		get_leftmost(root);       
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (current != NULL && current->right != NULL) || !stk.empty(); 
    }

    /** @return the next smallest number */
    int next() {
		if (current != NULL && current->right != NULL) {
			get_leftmost(current->right);
			if (!stk.empty()) {
				current = stk.top();
				stk.pop();
			}
		} else {
			current = stk.top();
			stk.pop();
		}
		return current->val;
	}
private:
	void get_leftmost(TreeNode * node){
		TreeNode * ptr;
		ptr = node;
		while(ptr != NULL) {
			stk.push(ptr);
			ptr = ptr->left;
		}
	}
};
//   10
//   / \
//  9  20
//    /  \
//   15   23
int main()
{
	TreeNode *root =new TreeNode(10);
	TreeNode *rnode =new TreeNode(20);
	TreeNode *rrnode =new TreeNode(23);
	TreeNode *lnode =new TreeNode(9);
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = llnode;


	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) 
		cout << i.next()<<" ";

	return 0;
}