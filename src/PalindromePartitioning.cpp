//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//  [
//    ["aa","b"],
//    ["a","a","b"]
//  ]

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;
		DFS(s,result,path,0);
		return result;        
    }
private:
	void DFS(string &s,vector<vector<string>> &result,vector<string> &path,int step){
		if(step>=s.size()){
			result.push_back(path);
			return;
		}
		for(auto i = step;i<s.size();i++){
			if(is_palindrome(s,step,i)){
				path.push_back(s.substr(step,i-step+1));
				DFS(s,result,path,i+1);
				path.pop_back();
			}
		}
	}

	bool is_palindrome(string &s,int start,int end){
		while(start < end){
			if(s[start]!=s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};

int main()
{
	vector<vector<string>> result;
	Solution solution;
	result = solution.partition("aab");
	return 0;
}