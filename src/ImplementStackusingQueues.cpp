//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue -- which means only push to back, pop from front, size, and is empty operations are valid.
//Update (2015-06-11):
//The class name of the Java function had been updated to MyStack instead of Stack.
//
//Credits:
//Special thanks to @jianchao.li.fighter for adding this problem and all test cases.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_set>
using namespace std;

class Stack {
private:
	queue<int> p,q;
public:
    // Push element x onto stack.

	//p only has one element while q has other elements  
    void push(int x) {
		p.push(x);
		while(p.size()>1){
			q.push(p.front());
			p.pop();
		}
    }

    // Removes the element on top of the stack.
    void pop(void) {
        top();
		p.pop();
    }

    // Get the top element.
    int top(void) {
		if(p.empty()){
			int size_q = q.size();
			int i=0;
			while(i<size_q-1){
				q.push(q.front());
				q.pop();
				i++;
			}
			p.push(q.front());
			q.pop();
		}
		return p.front();
    }

    // Return whether the stack is empty.
    bool empty(void) {
		return p.empty()&&q.empty();
    }
};

int main()
{
	Stack stk;
	stk.push(2);
	stk.push(6);
	stk.push(4);
	stk.push(1);
	stk.push(5);
	assert(stk.empty()==false);
	assert(stk.top()==5);
	stk.pop();
	assert(stk.top()==1);
	stk.pop();
	assert(stk.top()==4);
	return 0;
}