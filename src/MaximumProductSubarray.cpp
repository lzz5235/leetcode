//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lastMin = nums.front(), lastMax = nums.front(), result = lastMax;
		for(int i = 1; i<nums.size(); i++) {
			int tempMin = lastMin, tempMax = lastMax;
			lastMin = min(nums[i], min(tempMin * nums[i], tempMax * nums[i]));
			lastMax = max(nums[i], max(tempMin * nums[i], tempMax * nums[i]));
			result = max(result, lastMax);
		}
		return result;
    }
};


int main()
{
	int result;
	Solution solute;	
	int num[]={2,3,-2,4};
	vector<int> nums(num,num+4);
	result = solute.maxProduct(nums);
	assert(result==6);
	return 0;
}