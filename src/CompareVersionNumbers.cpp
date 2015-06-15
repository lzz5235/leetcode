//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//0.1 < 1.1 < 1.2 < 13.37
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
		int len1 = version1.size(),len2 = version2.size();

		int num1=0,num2=0;
		while (i<len1||j<len2)
		{
			while(i<len1&&version1[i]!='.'){
				num1 = num1*10 + version1[i]-'0';
				i++;
			}
			while(j<len2&&version2[j]!='.'){
				num2 = num2*10 + version2[j]-'0';
				j++;
			}
			
			if(num1>num2)
				return 1;
			else if(num1<num2)
				return -1;
			num1=num2=0;
			i++;
			j++;
		}
		return 0;
    }
};


int main()
{
	int result;
	Solution solute;	
	//result = solute.compareVersion(string("1.1"),string("1.2"));
	//assert(result==-1);
	//result = solute.compareVersion(string("1.1"),string("1.0"));
	//assert(result==1);
	//result = solute.compareVersion(string("13.37"),string("13.37"));
	//assert(result==0);
	result = solute.compareVersion(string("01"),string("1"));
	assert(result==0);
	return 0;
}