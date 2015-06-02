//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 2,3,6,7 and target 7, 
//A solution set is: 
//[7] 
//[2, 2, 3] 

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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
			for(;current<candidates.size();current++){
				if(target-candidates[current]<0)
					return;
				path.push_back(candidates[current]);
				dfs(result,candidates,path,current,target-candidates[current]);
				path.pop_back();
			}
		}
	}
};

int main()
{
	int num[]={2,3,6,7}; 
	vector<int> nums(num,num+4);
	vector<vector<int>> result;
	Solution solute;	
	result = solute.combinationSum(nums,7);
	return 0;
}