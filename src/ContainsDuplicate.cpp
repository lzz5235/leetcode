//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> uset;
		for(auto n:nums){
			auto ret = uset.insert(n);
			if(!ret.second)
				return true;
		}
		return false;
    }
};


int main()
{
	bool result;
	int num[]={1, 2, 3, 9, 5, 8, 6};
//	int num[]={1, 2};
	Solution solute;
	vector<int> nums(num,num+7);
	result = solute.containsDuplicate(nums);
	assert(result==true);
	return 0;
}