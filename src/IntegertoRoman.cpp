//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

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
    string intToRoman(int num) {
		const int radix[] = {1000, 900, 500, 400, 100, 90,
					50, 40, 10, 9, 5, 4, 1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
					"L", "XL", "X", "IX", "V", "IV", "I"};
		string result;
		for(int i=0;num>0;i++)
		{
			int count = num / radix[i];
			num %=radix[i];
			for(;count>0;count--)
				result +=symbol[i];
		}
		return result;
    }
};
//http://wenku.baidu.com/link?url=f8_GbXwIQD5qwvphQI4OxmSGnf9FL3dAp2sblIG_gt_GI-exahcPhmnDH-5dkJdBctCWIOwu60_H5T34P-cy5XNKhWisoYh0maE9bPgkpy_

int main()
{
	string result;
	Solution solute;
	result = solute.intToRoman(109);
	assert(result==string("CIX"));
	return 0;
}