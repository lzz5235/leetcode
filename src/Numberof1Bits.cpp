//Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).
//
//For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.

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
    int hammingWeight(uint32_t n) {
		int count =0;
		for(int i=0;i<32;i++){
			if(n&1)
				count++;
			n = n>>1;
		}
		return count;
    }
};

int main()
{
	Solution solute;
	uint32_t n=11;
	unsigned int result = solute.hammingWeight(n);

	assert(result==3);
	return 0;
}