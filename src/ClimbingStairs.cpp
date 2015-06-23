//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

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

//DP
class Solution {
public:
    int climbStairs(int n) {
		if(n==0)
			return 0;
		if(n==1)
			return 1;
		if(n==2)
			return 2;
		
		int *array_stairs = new int[n+1];
		array_stairs[0]=0;
		array_stairs[1]=1;
		array_stairs[2]=2;
		for(int i=3;i<=n;i++){
			array_stairs[i] = array_stairs[i-1] + array_stairs[i-2];
		}
		return array_stairs[n];
    }
};

int main()
{
	int result;
	Solution solute;	
	result = solute.climbStairs(1);
	assert(result==1);
	result = solute.climbStairs(2);
	assert(result==2);
	result = solute.climbStairs(5);
	assert(result==8);
	return 0;
}