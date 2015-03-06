//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//()()
//()
//)()())
class Solution {
public:
    int longestValidParentheses(string s) {
		int max_len=0,flag=-1;//flag is for "()...."
		int i=0;
		//if(s[0]=='('&&s[1]==')')
		//	max_len=2;
		for(auto c:s){
			if(c=='(')
				stk.push(i);
			else{
				if(stk.empty())
					flag = i ;
				else{
					stk.pop();
					if(stk.empty())
						max_len = max(max_len,i-flag);
					else
						max_len = max(max_len,i-stk.top());
				}
			}
			i++;
		}
		return max_len;
    }
private:
	stack<int> stk;
};

int main()
{
	string s(")()()");
	Solution solute;
	int count = solute.longestValidParentheses(s);

	printf("%d\n",count);
	return 0;
}