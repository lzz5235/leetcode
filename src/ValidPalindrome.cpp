//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers (including target) will be positive integers.
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.

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
    bool isPalindrome(string s) {
		transform(s.begin(),s.end(),s.begin(),::tolower);
		int size_s = s.size();
		int start = 0,end = size_s-1;
		
		for(;start<size_s&&s[start]==' ';start++){}
		for(;end>=0&&s[end]==' ';end--){}
		if(start > end )
			return true;

		while(start < end ){
			if(is_digtal(s[start])&&is_digtal(s[end])){
				if(s[start]==s[end]){
					start++;
					end--;
				}
				else
					return false;
			}
			if(is_digtal(s[start])==false)
				start++;
			if(is_digtal(s[end])==false)
				end--;
		}
		return true;
    }
private:
	bool is_digtal(char c){
		if((c >='a' &&  c<= 'z')||( c>='0' && c <='9'))
			return true;
		return false;
	}
};

int main()
{
	bool result;
	Solution solute;	
	result = solute.isPalindrome(string("A man, a plan, a canal: Panama"));
	assert(result==true);
	result = solute.isPalindrome(string("race a car"));
	assert(result==false);
	result = solute.isPalindrome(string("   A man, a plan, a canal: Panama    "));
	assert(result==true);
	result = solute.isPalindrome(string("   "));
	assert(result==true);
	result = solute.isPalindrome(string("1a2"));
	assert(result==false);
	return 0;
}