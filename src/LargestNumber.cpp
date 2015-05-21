//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
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
    string largestNumber(vector<int>& nums) {
		stable_sort(nums.begin(),nums.end(),compareGreater);
		if(!nums.empty()&&nums[0]==0)
			return "0";
		string result;
		for(auto c:nums){
			result +=to_string(c);
		}
		return result;
    }
private:
	static unsigned int numDigits(int num)
    {
        unsigned int count = 0;
        do
        {
            count++;
            num /= 10;
        } while (num);
        return count;
    }

    static bool compareGreater(int lhs, int rhs)
    {
        unsigned int left_n = numDigits(lhs);
        unsigned int right_n = numDigits(rhs);

        unsigned int L = lhs*pow(10, right_n) + rhs;
        unsigned int R = rhs*pow(10, left_n) + lhs;
        return L > R;
    }
};


int main()
{
	int a[]={3, 30, 34, 5, 9};
	string result;
	vector<int> num(a,a+5);
	Solution solute;	
	result = solute.largestNumber(num);
	assert(result==string("9534330"));
	return 0;
}