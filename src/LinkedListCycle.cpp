//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?


#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;

		while(fast!=NULL&&fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
				return true;
		}
		return false;
    }
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *e = new ListNode(5);

	a->next = b;
	b->next = c; 
	c->next = d; 
	d->next = e;
	e->next=a;

	Solution solute;
	bool count = solute.hasCycle(a);

	printf("%d\n",count);
	return 0;
}