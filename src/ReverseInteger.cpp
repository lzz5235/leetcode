// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)

class Solution {
public:
    int reverse(int x) {
    	long result=0;
		long temp;
    	if(x==0)
    	{
    		return 0;
    	}
    	else if(x>0)
    	{
    		temp = x;
    		while(temp!=0)
    		{	
    			//http://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c
    			//注意int溢出，我们不用和INT_MAX比，跟除去最低位的剩下数字相比就可以了！
    			if(result > INT_MAX/10 || result < INT_MIN/10)
    				return 0;
    			result = result*10 + temp%10;
    			temp /=10;
    		}
    		return result;
    	}
    	else
    	{
    		temp = -x;
    		while(temp!=0)
    		{	
    			if(result > INT_MAX/10 || result < INT_MIN/10)
    				return 0;
    			result = result*10 + temp%10;
    			temp /=10;
    		}
    		return -result;
    	}        
    }
};


int main()
{
    Solution solute;
    cout << solute.reverse(1534236469) <<endl;
    return 0;
}
