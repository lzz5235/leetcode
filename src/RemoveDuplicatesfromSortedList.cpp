//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

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
		if(p->next==NULL || p->next->next==NULL)
			return dummy.next;

		while(1)
		{
			p = p->next;
			
			if(p==NULL || p->next ==NULL)
				break;
			ListNode *temp = p->next;
			
			if(p->val==temp->val)
			{
				while(temp->next!=NULL)
				{
					if(p->val!=temp->next->val)
						break;
					ListNode *ttemp = temp;
					temp = temp->next;
					delete ttemp;
				}
				p->next = temp->next;
				delete temp;
			}
		}

		return dummy.next;
    }
};

int main()
{
	//ListNode a(1);
	//ListNode b(1),c(1),d(2),e(3);
	//a.next = &b;b.next = &c; c.next = &d; d.next = &e;

	ListNode a(1);
	ListNode b(1);
	a.next  = &b;
	Solution solute;

	solute.deleteDuplicates(&a);
}