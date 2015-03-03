//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//注意栈的特性，只能从一面出去
//push ： 5,1,2     minstack 5,1   
//pop ：2    minstack 5,1
//pop: 1     minstack 5

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
private:
	stack<int> Stack;
	stack<int> minstack;
public:
    void push(int x) {
		Stack.push(x);
		if(minstack.empty()||(!minstack.empty()&&x<=minstack.top()))
		{//注意保留相同最小元素
			minstack.push(x);
		}
    }

    void pop() {
		if(!Stack.empty()){
			if(minstack.top()==Stack.top())
				minstack.pop();
			Stack.pop();
		}
    }

    int top() {
		return Stack.top();        
    }

    int getMin() {
		return minstack.top();
    }
};

int main()
{
	MinStack sta;
	sta.push(2);
	sta.push(6);
	sta.push(4);
	sta.push(1);
	sta.push(5);
	printf("%ld\n",sta.getMin());
	sta.pop();
	sta.pop();
	printf("%ld\n",sta.getMin());
	return 0;
}