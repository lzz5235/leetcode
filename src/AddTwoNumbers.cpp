//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *pa = l1,*pb=l2;
		ListNode dummy(-1);
		ListNode *p = &dummy;
		int carry =0;
		if(pa==NULL || pb==NULL)
			return NULL;
		for(;pa!=NULL||pb!=NULL;p=p->next)
		{
			int value_a,value_b;

			if(pa==NULL)
				value_a = 0;
			else
				value_a = pa->val;
			if(pb==NULL)
				value_b = 0;
			else
				value_b = pb->val;			
			
			int value = (value_a+value_b + carry)%10;
			carry = (value_a+value_b + carry)/10;
			p->next = new ListNode(value);

			if(pa!=NULL)
				pa=pa->next;
			if(pb!=NULL)
				pb=pb->next;
		}
		if(carry>0)
			p->next = new ListNode(carry);
		return dummy.next;
    }
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(8);

	ListNode *d = new ListNode(0);


	a->next = b;
	b->next;
 
	d->next = NULL;

	//ListNode a(1);
	//ListNode b(1);
	//a.next  = &b;
	Solution solute;

	a = solute.addTwoNumbers(a,d);
}