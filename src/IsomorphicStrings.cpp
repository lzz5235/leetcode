//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

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
    bool isIsomorphic(string s, string t) {
		if(s.size()!=t.size())
			return false;
		char symbols[256]={0},symbolt[256]={0};
		for(int i=0;i<s.size();i++){
			if(symbols[s[i]]==0)
				symbols[s[i]] = t[i];
			else if(symbols[s[i]]!=t[i])
				return false;
			if(symbolt[t[i]]==0)
				symbolt[t[i]] = s[i];
			else if(symbolt[t[i]]!= s[i])
				return false;
		}
		return true;
    }
};

int main()
{
	bool result;
	Solution solute;
	result = solute.isIsomorphic(string("egg"),string("add"));
	assert(result==true);
	result = solute.isIsomorphic(string("foo"),string("bar"));
	assert(result==false);
	result = solute.isIsomorphic(string("paper"),string("title"));
	assert(result==true);
	return 0;
}