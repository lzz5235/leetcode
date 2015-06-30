//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
//
//Credits:
//Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.



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


//[0,1,2,4,5,7], return ["0->2","4->5","7"].
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		int size_n = nums.size();
		if(size_n==0)
			return result;
		int i = 0;
		while(i<size_n){
			int start = i,end = i;
			while(end+1<size_n&&nums[end+1]==nums[end]+1)
				end++;
			if(end > start)
				result.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
			else
				result.push_back(to_string(nums[start]));
			i = end+1;
		}
		return result;
    }
};


int main()
{
	vector<string> result;
	int num1[6]={0,1,2,4,5,7};
	vector<int> temp1(num1,num1+6);
	int num2[1]={5};
	vector<int> temp2(num2,num2+1);
	
	Solution solute;
	result = solute.summaryRanges(temp1);

	result = solute.summaryRanges(temp2);
	return 0;
}