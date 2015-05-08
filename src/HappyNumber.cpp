//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: 
//Starting with any positive integer, replace the number by the sum of the squares of its digits, 
//and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
//Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1

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
    bool isHappy(int n) {
		set<int> set_n;
		int temp = n;
		while(true){
			if(temp==1)
				return true;
			if(set_n.find(temp)!=set_n.end())
				return false;
			set_n.insert(temp);
			temp = cal(temp);
		}        
    }
private:
	int cal(int n){
		int ret = 0;
		while(n!=0){
			ret +=(n%10)*(n%10);
			n /=10;
		}
		return ret;
	}
};

int main()
{
	bool result;
	Solution solute;
	result = solute.isHappy(19);
	assert(result==true);
	return 0;
}