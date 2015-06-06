//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
//A solution set is: 
//[1, 7] 
//[1, 2, 5] 
//[2, 6] 
//[1, 1, 6] 


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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
		vector<int> path;
		sort(candidates.begin(),candidates.end());
		dfs(result,candidates,path,0,target);
		return result;
    }
private:
	void dfs(vector<vector<int>> &result,vector<int>& candidates,vector<int> path,int current,int target){
		if(!path.empty()&&target==0){
			result.push_back(path);
			return;
		}
		if(current<candidates.size()){
			int tmp = -1;//start from 0 and 1
			for(;current<candidates.size();current++){
				
				if(candidates[current]==tmp)
					continue;
				if(target-candidates[current]<0)
					return;

				tmp = candidates[current];
				path.push_back(candidates[current]);
				dfs(result,candidates,path,current+1,target-candidates[current]);
				path.pop_back();
			}
		}
	}
};


int main()
{
	int num[]={10,1,2,7,6,1,5}; 
	vector<int> nums(num,num+7);
	vector<vector<int>> result;
	Solution solute;	
	result = solute.combinationSum2(nums,8);
	return 0;
}