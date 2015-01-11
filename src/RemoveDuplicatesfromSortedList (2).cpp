//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode dummy(-1);
		dummy.next = head;

		ListNode *p=&dummy;
		
		ListNode *flag = p->next;
		
		while(flag!=NULL)
		{
			bool same = false;
			while(flag->next!=NULL&&flag->val==flag->next->val)
			{
				same = true;
				ListNode *temp = flag;
				flag = flag->next;
				delete temp;
			}
			if(same==true)
			{
				ListNode *temp = flag;
				flag = flag->next;
				delete temp;
				continue;
			}
			p->next=flag;
			p = p->next;
			flag = flag->next;
		}
		p->next=flag;
		return dummy.next;
    }
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(1);
	ListNode *d = new ListNode(2);
	ListNode *e = new ListNode(3);

	a->next = b;
	b->next = c; 
	c->next = d; 
	d->next = e;

	//ListNode a(1);
	//ListNode b(1);
	//a.next  = &b;
	Solution solute;

	a = solute.deleteDuplicates(a);
}