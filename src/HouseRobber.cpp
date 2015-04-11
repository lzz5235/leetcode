//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//Credits:
//Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
		int i = num.size();
		if(i<=0)
			return 0;
		if(i==1)
			return num[0];
		vector<int> result(i,0);
		result[0] = num[0];
		result[1] = max(num[0],num[1]);
		
		for(int k=2;k<i;k++){
			result[k] = max(result[k-2]+num[k],result[k-1]);
		}
		return result[i-1];
    }
};

int main()
{

	int a[5]={1,9,3,4,5};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	int result = 0;
	Solution solute;
	result = solute.rob(num);
	assert(result==9);
	return 0;
}