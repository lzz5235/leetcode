//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		string left="([{";
		string right=")]}";
		stack<char> stk;

		for(auto c: s){
			if(left.find(c)!=string::npos)
				stk.push(c);
			else{
				if(stk.empty()||stk.top()!=left[right.find(c)])
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
    }
};

int main()
{
	Solution solute;
	bool flag = solute.isValid("()[]{}");

	printf("%d\n",flag);
	return 0;
}