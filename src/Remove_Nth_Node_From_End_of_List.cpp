//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy, *q = &dummy;

		for (int i = 0; i < n; i++)
			q = q->next;
		while(q->next!=NULL) { 
			p = p->next;
			q = q->next;
		}
		ListNode *tmp = p->next;
		p->next = tmp->next;
//		delete tmp;
		return dummy.next;
    }
};

int main()
{
	ListNode head(0);
	ListNode p(1),a(2),b(3),c(4);
	head.next = &p; 
	p.next = &a; 
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	
	Solution solute;
	solute.removeNthFromEnd(&head,5);
}