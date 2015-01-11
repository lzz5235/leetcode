//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(head==NULL|| k==0)
			return head;
		int list_len = 1,step = 0;
		ListNode *p = head;
		while(p->next!=NULL)
		{
			list_len++;
			p=p->next;
		}
		k = list_len - k%list_len;

		p->next = head;
		while(1)
		{
			if(step==k)
				break;
			p = p->next;
			step++;
		}
		head = p->next;
		p->next = NULL;
		return head;
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

	//ListNode a(1);
	//ListNode b(1);
	//a.next  = &b;
	Solution solute;

	a = solute.rotateRight(a,2);
}