//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 
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
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		string symbol[]={"0","A","B","C","D","E","F","G","H","I","J","K","L","M","N"
							,"O","P","Q","R","S","T","U","V","W","X","Y","Z"};
		int result=0;
		for(int i=0;i<s.size();i++){
			result = result*26 + (s[i]-'A'+1);
		}
		return result;
    }
};


int main()
{
	int result;
	Solution solute;
	result = solute.titleToNumber(string("Z"));
	assert(result==26);
	result = solute.titleToNumber(string("AB"));
	assert(result==28);
	result = solute.titleToNumber(string("AA"));
	assert(result==27);
	return 0;
}