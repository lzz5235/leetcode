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
//���ǿ�����һ��������¼�����ѽ��������Ĵ𰸡����ܸ��������Ժ��Ƿ��õ���
//ֻҪ������������ͽ�����������С�����Ƕ�̬�滮���Ļ���˼·������Ķ�̬�滮�㷨���ֶ����������Ǿ�����ͬ������ʽ��

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