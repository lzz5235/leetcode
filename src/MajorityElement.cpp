//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.

//if majorElement exists in array.The final flag must be more than 0!


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
    int majorityElement(vector<int> &num) {
		int flag = 0;
		int majorityelement = 0;
		for(int i=0;i<num.size();i++){
			if(flag==0){
				majorityelement =  num[i];
				flag = 1;
			}
			else{
				if(majorityelement == num[i])
					flag++;
				else
					flag--;
			}
		}
		return majorityelement;
    }
};

int main()
{
	int nums[]={1,0,2,3,4,0,0,0,5,67,3,3,1,0,0,321,30,0,0,21,0,0,231};
	vector<int> num(nums,nums+sizeof(nums)/sizeof(nums[0]));
	Solution solute;
	int result = solute.majorityElement(num);

	assert(result==0);
	return 0;
}