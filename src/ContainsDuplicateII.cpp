//Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int,int> hmap;
		for(int i=0;i<nums.size();i++){
			if(hmap.count(nums[i])){
				if(i-hmap[nums[i]]<=k)
					return true;
			}
			hmap[nums[i]] = i;
		}
		return false;
        
    }
};


int main()
{
	int num[]={-2,1,-3,4,-1,2,1,-5,4};
	// first 4 's index is 3   second 4's index is 8   8-3 is 5 > k 
	vector<int> nums(num,num+9);
	bool result;
	Solution solute;	
	result = solute.containsNearbyDuplicate(nums,5);
	assert(result==true);
	return 0;
}