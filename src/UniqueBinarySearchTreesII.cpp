//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//OJ's Binary Tree Serialization:
//The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//
//Here's an example:
//   1
//  / \
// 2   3
//    /
//   4
//    \
//     5
//The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
//Dynamic Programming
//我们可以用一个表来记录所有已解的子问题的答案。不管该子问题以后是否被用到，
//只要它被计算过，就将其结果填入表中。这就是动态规划法的基本思路。具体的动态规划算法多种多样，但它们具有相同的填表格式。

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
    vector<TreeNode *> generateTrees(int n) {
        if(n==0)
			return generateTrees(1,0);
		return generateTrees(1,n);
    }
private:
	vector<TreeNode *> generateTrees(int start,int end){
		vector<TreeNode *> result;
		if(start>end){
			result.push_back(NULL);
			return result;
		}
		for(int k=start;k<=end;k++)  
        {  
            vector<TreeNode *> left = generateTrees(start,k-1);  
            vector<TreeNode *> right = generateTrees(k+1,end);  
            for(int i=0;i<left.size();i++)  
            {  
                for(int j=0;j<right.size();j++)  
                {  
                    TreeNode * root = new TreeNode(k);  
                    root->left = left[i];  
                    root->right = right[j];  
                    result.push_back(root);  
                }  
            }  
        }  
        return result; 		
	}
};

int main()
{
	Solution solute;	
	vector<TreeNode *> result;
	result = solute.generateTrees(3);

	return 0;
}