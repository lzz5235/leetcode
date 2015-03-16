//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

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
    string addBinary(string a, string b) {
		string temp="";
		int ia=a.size(),ib=b.size();
        int max_n = ia>ib?ia:ib;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int carry = 0;
		for(int i=0;i<max_n;i++){
			int a_value = ia>i?a[i]-'0':0;//clear out of range
			int b_value = ib>i?b[i]-'0':0;//clear out of range

			int value = (a_value+b_value+carry)%2;
			carry = (a_value+b_value+carry)/2;
			temp.insert(temp.begin(),'0'+value);
		}
		if(carry==1)
			temp.insert(temp.begin(),'1');

		return temp;
    }
};

int main()
{
	Solution solute;
	string result = solute.addBinary(string("11"),string("1"));
	assert(result==string("100"));
	result = solute.addBinary(string("1100"),string("10"));
	assert(result==string("1110"));
	return 0;
}