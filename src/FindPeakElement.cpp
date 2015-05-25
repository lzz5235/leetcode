//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -¡Þ.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left=0,right=nums.size()-1;

		while(left < right-1){
			int mid = (left+right)/2;
			if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])
				return mid;
			else if(nums[mid]>nums[mid+1])
				right = mid-1;
			else
				left = mid+1;
		}
		return nums[left]>nums[right]?left:right;
    }
};


int main()
{
	int result;
	int num[]={1, 2, 3, 5, 8, 6};
//	int num[]={1, 2};
	Solution solute;
	vector<int> nums(num,num+6);
	result = solute.findPeakElement(nums);
	assert(result==4);
	return 0;
}