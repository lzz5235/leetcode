//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is:
//
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
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
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
		vector<int> path;
		vector<int> candidates;
		for(int i=1;i<=n;i++)
			candidates.push_back(i);
		dfs(result,candidates,path,0,n,k);
		return result;
    }
private:
	void dfs(vector<vector<int>> &result,vector<int>& candidates,vector<int> path,int step,int n,int k){
		if(path.size() == k){
			result.push_back(path);
			return;
		}

		if(path.size()< k){
//			int i = path.empty()?1:path.back()+1;
			for(;step<=n;step++){
				if(step >= candidates.size())
					return;
				path.push_back(candidates[step]);
				dfs(result,candidates,path,step+1,n,k);
				path.pop_back();
			}
		}

	}
};


int main()
{
	vector<vector<int>> result;
	Solution solute;	
	result = solute.combine(4,2);
	return 0;
}