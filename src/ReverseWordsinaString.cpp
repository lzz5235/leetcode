//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space. 


//""	->""
//" "	->""
//" 1"	->"1"
//"  1   "->"1"
//"    a     b   "   ->"b a"
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
	string temp;  
    int i = s.size()-1;  
		while(i>=0)  
		{  
			while(i>=0&&s[i] == ' ')  
			{  
				i --;  
			}  
			if(i<0) 
				break;  
			if(temp.length()!=0)  
				temp.push_back(' ');  
			string tempstr;  
			for(;i>=0&&s[i]!=' ';i--)  
				tempstr.push_back(s[i]);  
			reverse(tempstr.begin(),tempstr.end());  
			temp.append(tempstr);  
		}
		s=temp; 
	}
};

int main()
{
	//the sky is blue
	//eulb si yks eht
	string str("the sky is blue");
	Solution solute;
	solute.reverseWords(str);
	assert(str==string("blue is sky the"));
	return 0;
}