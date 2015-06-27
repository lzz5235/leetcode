//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".


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
#include <queue>
#include <functional>
using namespace std;

//DP
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        s = " " + s; //prepare dpArray[0] is true;
        vector<bool> dpArray(s.size());
        dpArray[0] = true;
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<s.size(); j++) {
                if(dpArray[j]) continue;
                if(wordDict.find(s.substr(i+1, j-i))!=wordDict.end() && dpArray[i])
                    dpArray[j] = true;
            }
        }
        return dpArray[dpArray.size()-1];
    }
};


int main()
{
	unordered_set<string> hash_map;
	hash_map.insert("leet");
	hash_map.insert("code");
	hash_map.insert("a");
	hash_map.insert("abc");
	hash_map.insert("b");
	hash_map.insert("cd");
	bool result;
	Solution solute;	
	//result = solute.wordBreak("leetcode",hash_map);
	//assert(result==true);
	result = solute.wordBreak("abcd",hash_map);
	assert(result==true);
	return 0;
}