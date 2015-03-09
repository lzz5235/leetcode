//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;


class Solution {
private:
	bool is_operation(string &str){
		if(str.size()==1&&string("+-*/").find(str)!=string::npos)
			return true;
		return false;
	}
public:
    int evalRPN(vector<string> &tokens) {
		stack<string> stk;
		for(auto c:tokens){
			if(is_operation(c)==false)
				stk.push(c);
			else{
				int b = stoi(stk.top());
				stk.pop();
				int a = stoi(stk.top());
				stk.pop();
				if(c[0]=='+')
					a +=b;
				else if(c[0]=='-')
					a-=b;
				else if(c[0]=='*')
					a *=b;
				else if(c[0]=='/')
					a /=b;
				stk.push(to_string(a));
			}
		}
		return stoi(stk.top());
    }
};

int main()
{
	char symbol[5][3]={"4", "13", "5", "/", "+"};

	vector<string> tokens;
	for(int i=0;i<5;i++)
	{
		tokens.push_back(symbol[i]);
	}
	Solution solute;
	int count = solute.evalRPN(tokens);

	printf("%d\n",count);
	return 0;
}