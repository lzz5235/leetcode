//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range [5, 7], you should return 4.
//
//Credits:
//Special thanks to @amrsaqr for adding this problem and creating all test cases.

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
    int rangeBitwiseAnd(int m, int n) {
		//int ret = m;
		//for(int i=m;i<=n;i++){
		//	ret &=i;
		//}
		//return ret;
		//time execeed
		int temp = m^n;
		int i=0;
		while(temp!=0){
			i++;
			temp >>=1;
		}
		return ((n>>i)<<i);
    }
};

int main()
{
	int result;
	Solution solute;
	result = solute.rangeBitwiseAnd(5,7);
	assert(result==4);
	return 0;
}