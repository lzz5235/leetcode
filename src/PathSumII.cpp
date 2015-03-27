//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//For example:
//Given the below binary tree and sum = 22,
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//
//return
//
//[
//   [5,4,11,2],
//   [5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > result;
		vector<int> current;//middle state
		pathSum(root,sum,current,result);
		return result;
    }
private:
	void pathSum(TreeNode *root, int sum,vector<int> &current,vector<vector<int> > &result){
		if(root==NULL)
			return;
		
		current.push_back(root->val);

		if(root->left==NULL&&root->right==NULL)
			if(sum == root->val)
				result.push_back(current);
		pathSum(root->left,sum-root->val,current,result);
		pathSum(root->right,sum-root->val,current,result);

		current.pop_back();
//		cout<<"pop_back"<<endl;
	}
};

int main()
{
	Solution solute;
	vector<vector<int> > result;
	TreeNode *root =new TreeNode(3);
	TreeNode *rnode =new TreeNode(20);
	TreeNode *rrnode =new TreeNode(15);
	TreeNode *lnode =new TreeNode(9);
	TreeNode *llnode =new TreeNode(15);

	root->right = rnode;
	root->left = lnode;
	rnode->right = rrnode;
	rnode->left = llnode;

	result = solute.pathSum(root,38);
	return 0;
}