//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Ensure that numbers within the set are sorted in ascending order.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//[[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//[[1,2,6], [1,3,5], [2,3,4]]
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.


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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
		vector<int> path;
		dfs(result,path,k,n);
		return result;
    }
private:
	void dfs(vector<vector<int>> &result,vector<int> &path,int k,int n){
		if(path.size()==k && n==0){
			result.push_back(path);
			return;
		}
		if(path.size()< k){
			int i = path.empty()?1:path.back()+1;
			for(;i<=9;i++){
				if(n-i<0)
					break;
				path.push_back(i);
				dfs(result,path,k,n-i);
				path.pop_back();
			}
		}
	}
};

int main()
{
	vector<vector<int>> result;
	Solution solute;
	result = solute.combinationSum3(3,9);

	return 0;
}