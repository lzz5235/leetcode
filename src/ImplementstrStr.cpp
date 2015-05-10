//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Update (2014-11-02):
//The signature of the function had been updated to return the index instead of the pointer. 
//If you still see your function signature returns a char * or String, please click the 

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
    int strStr(string haystack, string needle) {
		int j=0;
		if(needle.size()==0)
			return 0;
		if(needle.size()>haystack.size())
			return -1;
		int needle_len = needle.size();
		int haystack_len = haystack.size();

		for(int i=0;i<haystack_len-needle_len+1;i++)
		{
			j = 0;
			while(haystack[i+j]==needle[j]){
				j++;
				if(j==needle_len)
					return i;
			}
		}
		return -1;
    }
};

int main()
{
	int result;
	Solution solute;
	result = solute.strStr(string("abcdef"),string("bcd"));
	assert(result==1);
	result = solute.strStr(string("abcdef"),string("bce"));
	assert(result==-1);
	result = solute.strStr(string("abcdef"),string("cdefg"));
	assert(result==-1);
	return 0;
}