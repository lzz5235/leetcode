//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

// t >= |nums[i]-nums[j]|
// k >= |i-j|

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> Map;
        int l=0;
        for (int r=0;r<nums.size();r++) {
            if (r-l>k && Map[nums[l]]==l)
                Map.erase(nums[l++]);
            auto it=Map.lower_bound(nums[r]-t);
            if (it!=Map.end() && abs(it->first-nums[r])<=t)
                return true;
            Map[nums[r]]=r;
        }
        return false;
     }
};



int main()
{
	int num[]={1,3,4,5,6,9,20,23,24};
	int num1[]={3,6,0,4};
	// first 4 's index is 3   second 4's index is 8   8-3 is 5 > k 
	vector<int> nums(num,num+9);
//	vector<int> nums1(num1,num1+4);
	bool result;
	Solution solute;	
	result = solute.containsNearbyAlmostDuplicate(nums,2,2);
	assert(result==true);
	return 0;
}