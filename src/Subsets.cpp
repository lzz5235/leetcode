//Given a set of distinct integers, nums, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
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
    vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> result;
        vector<int> path;
		dfs(nums,path,result,0);
		return result;
    }
private:
	void dfs(vector<int>& nums,vector<int> &path,vector<vector<int>> &result,int step){
		if(step==nums.size()){
			result.push_back(path);
			return;
		}
		
		dfs(nums,path,result,step+1);

		path.push_back(nums[step]);
		dfs(nums,path,result,step+1);
		path.pop_back();		
	}
};

int main()
{
	int a[]={1,2,3};
	vector<vector<int>> result;
	vector<int> num(a,a+3);
	Solution solute;
	
	result = solute.subsets(num);

	return 0;
}