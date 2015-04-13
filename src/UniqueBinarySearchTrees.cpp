//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

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
    int numTrees(int n) {
		vector<int> f(n+1,0);

		f[0]=1;
		f[1]=1;
		for(int i = 2;i<=n;i++){
			for(int k = 1;k<=i;k++){
				f[i] += f[k-1]*f[i-k];
			}
		}
		return f[n];
    }
};

int main()
{
	Solution solute;	

	int result = solute.numTrees(3);
	assert(result==5);

	return 0;
}