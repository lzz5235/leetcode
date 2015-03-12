//Given an array of integers, every element appears twice except for one. 
//Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. 
//Could you implement it without using extra memory?

// 异或相同为0，不同为不为零的值
//eg:    0^10 = 10
//eg:    10^10 =0
//但是这里要保证起始为0，这样才可以保证出现两次归0，如果出现 3^10 则变为按位与或，无意义。

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int flag =0;
		for (int i=0;i<n;i++){
			flag = flag^A[i];
		}
		return flag;        
    }
};

int main()
{
	int num[]={1,1,2,2,3,3,4,5,4,6,6,7,7,8,8,9,9,10,10};
	
	Solution solute;
	int result = solute.singleNumber(num,sizeof(num)/sizeof(num[0]));

	assert(result==5);
	return 0;
}