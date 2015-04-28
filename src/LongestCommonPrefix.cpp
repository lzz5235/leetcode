//Write a function to find the longest common prefix string amongst an array of strings.

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
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty())
			return "";
		for(int idx = 0;idx < strs[0].size();idx++){
			for(int i = 1;i<strs.size();i++){
				if(strs[i][idx]!=strs[0][idx])
					return strs[0].substr(0,idx);
			}
		}
		return strs[0];
    }
};

int main()
{
	string result;
	vector<string> strs;
	strs.push_back(string("ABcdfe"));
	strs.push_back(string("ABCdefg"));
	strs.push_back(string("ABcsfeded"));
	Solution solute;
	result = solute.longestCommonPrefix(strs);
	assert(result==string("AB"));
	return 0;
}