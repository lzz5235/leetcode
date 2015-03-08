//Given a non-negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int bit = 1 ;
		for(int i=digits.size()-1;i>=0;i--){
			if(bit>0){
				digits[i] +=1;
				bit=0;
			}
			if(digits[i]>=10){
				bit = digits[i]/10;
				digits[i] %=10;
			}
		}
		if(bit>0){
			digits.insert(digits.begin(),1);
		}
		return digits;
    }
};

int main()
{
	int digits[]={9,9,9};

	vector<int> vec(digits,digits+sizeof(digits)/sizeof(digits[0]));
	vector<int> result;
	Solution solute;
	result = solute.plusOne(vec);

	for(int i=0;i<result.size();i++)
		printf("%d\n",result[i]);
	return 0;
}