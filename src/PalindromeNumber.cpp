//Determine whether an integer is a palindrome. Do this without extra space.
//
//click to show spoilers.
//
//Some hints:
//Could negative integers be palindromes? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//
//There is a more generic way of solving this problem.

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

class Solution {
public:
bool isPalindrome(int x) {
        if (x < 0) return false;
        int p1 = 0, p2 = x;
        while (p2 > 0) {
            p1 = p1*10 + p2%10;
            p2 /= 10;
        }
        return p1 == x;
    }
};

int main()
{
	bool result;
	Solution solute;	
	result = solute.isPalindrome(123454321);
	assert(result==true);
	result = solute.isPalindrome(123);
	assert(result==false);
	result = solute.isPalindrome(0);
	assert(result==true);
	return 0;
}