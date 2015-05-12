//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1,2,2], a solution is:
//
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]

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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> result;
        vector<int> path;
		dfs(nums,path,result,nums.begin());
		return result; 
    }
private:
	void dfs(vector<int>& nums,vector<int> &path,vector<vector<int>> &result,
		vector<int>::iterator start){
		
		result.push_back(path);
		
		for(auto i = start;i<nums.end();i++)
		{
			if(i!=start&&*i==*(i-1))
				continue;
			path.push_back(*i);
			dfs(nums,path,result,i+1);
			path.pop_back();		
		}
	}
};


int main()
{
	int a[]={1,2,2};
	vector<vector<int>> result;
	vector<int> num(a,a+3);
	Solution solute;
	
	result = solute.subsetsWithDup(num);

	return 0;
}