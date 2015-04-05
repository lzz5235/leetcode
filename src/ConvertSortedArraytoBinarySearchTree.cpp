//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST(num.begin(),num.end());
    }
private:
	TreeNode *sortedArrayToBST(vector<int>::iterator begin,vector<int>::iterator end)
	{
		auto dis = distance(begin,end);
		if(dis <=0) 
			return NULL;
		auto mid = begin + dis/2;
		TreeNode *root = new TreeNode(*mid);
		root->left = sortedArrayToBST(begin,mid);
		root->right = sortedArrayToBST(mid+1,end);

		return root;
	}
};

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	Solution solute;	
	bool result;
	
	TreeNode *root ;

	root = solute.sortedArrayToBST(num);

	return 0;
}