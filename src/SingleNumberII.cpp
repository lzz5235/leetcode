//Given an array of integers, every element appears three times except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

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
		int bitmap[32]={0};
		int result=0;
		for(int i=0;i<32;i++){
			for(int j=0;j<n;j++){
				bitmap[i] = bitmap[i]+((A[j]>>i)&1);
			}
			bitmap[i] = bitmap[i] %3;// 3 可以任意换，三个相同的数字在bitmap中必然可以被3模
		}
		//for(int i=0;i<32;i++)
		//	printf("%d\t",bitmap[i]);
		for(int i=0;i<32;i++)
			result +=(bitmap[i]<<i);
		return result;
    }
};

int main()
{
	int num[]={1,1,1,2,2,2,3,3,3,4,5,4,4,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
	
	Solution solute;
	int result = solute.singleNumber(num,sizeof(num)/sizeof(num[0]));

	assert(result==5);
	//int i = 3;
	//int flag =1;
	//flag = flag & (i>>1);
	//cout<<flag;
	return 0;
}