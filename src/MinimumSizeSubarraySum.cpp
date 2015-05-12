//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice:
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
//
//Credits:
//Special thanks to @Freezen for adding this problem and creating all test cases.

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
    int minSubArrayLen(int s, vector<int>& nums) {
		vector<int>::iterator i = nums.begin();
		deque<int> quene;
		int len=INT_MAX,temp_len=0;
		int sum = 0;
		for(;i<nums.end();i++){
			sum +=*i;
			quene.push_back(*i);

			if(sum>=s){
				while(sum - quene.front()>= s){
					sum -=quene.front();
					quene.pop_front();
				}
				len = min(len,(int)quene.size());
			}
		}
		return len==INT_MAX?0:len;
    }
};


int main()
{
	int a[]={2,3,1,1,1,1,1};
	int result;
	vector<int> num(a,a+7);
	Solution solute;
	
	result = solute.minSubArrayLen(5,num);
	return 0;
}