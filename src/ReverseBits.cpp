//Reverse bits of a given 32 bits unsigned integer.
//
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//Follow up:
//If this function is called many times, how would you optimize it?
//
//Related problem: Reverse Integer
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.

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
    uint32_t reverseBits(uint32_t n) {
		uint32_t temp=0;
		for(int i=0;i<32;i++){
			temp = temp<<1;
			temp = temp | (n & 1);
			n = n>>1;
		}
		return temp;
    }
};

int main()
{
	Solution solute;
	uint32_t n=43261596;
	unsigned int result = solute.reverseBits(n);

	assert(result==964176192);
	return 0;
}