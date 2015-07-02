//Given a string, find the length of the longest substring 
//without repeating characters. For example, the longest substring 
//without repeating letters for "abcabcbb" is "abc", which the length is 3. 
//For "bbbbb" the longest substring is "b", with the length of 1.


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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0,cur=0;
        string str;
        for(int i=0;i<s.size();++i)
        {
            int pos=str.find(s[i]);
            if(pos!=string::npos)
                {
                    length=max(length,(int)str.size());
                    str.erase(str.begin(),str.begin()+pos+1);
                }
            str.push_back(s[i]);    
        }
        return max(length,(int)str.size());
    }
};


int main()
{
	int result;
	Solution solute;	
	result = solute.lengthOfLongestSubstring("abcabcbb");
	assert(result==3);
	result = solute.lengthOfLongestSubstring("bbbbbc");
	assert(result==2);
	result = solute.lengthOfLongestSubstring("abcabcbbacd");
	assert(result==4);
	return 0;
}