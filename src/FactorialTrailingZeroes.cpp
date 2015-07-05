//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases..



#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

//我们很容易观察到质因子中2的个数总是大于等于5的个数。因此只要计数5的个数就可以了。
//那么怎样计算n!的质因子中所有5的个数呢？一个简单的方法是计算floor(n/5)。
//例如，7!有一个5，10!有两个5。除此之外，还有一件事情要考虑。诸如25，125之类的数字有不止一个5。
//例如，如果我们考虑28!，我们得到一个额外的5，并且0的总数变成了6。
//处理这个问题也很简单，首先对n÷5，移除所有的单个5，然后÷25，移除额外的5，以此类推。
//下面是归纳出的计算后缀0的公式。

class Solution {
public:
    int trailingZeroes(int n) {
		int result=0;
		while(n>0){
			result +=n/5;
			n /=5;
		}
		return result;
    }
};


int main()
{
	int result = 0;
	Solution solute;
	result = solute.trailingZeroes(13);
	assert(result==2);
	result = solute.trailingZeroes(9);
	assert(result==1);
	return 0;
}