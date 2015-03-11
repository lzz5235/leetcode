//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode * dummy = new ListNode(-1);
		if(head==NULL||head->next==NULL)
			return head;
		dummy->next = head;
		ListNode * prev = dummy;
		ListNode * current = dummy->next;
		ListNode * next = current->next;
		while(next!=NULL){
			prev->next = next;
			current ->next = next->next;
			next->next = current;

			prev = current;
			current = current->next;
			if(current==NULL)
				break;
			next = current->next;
		}
		return dummy->next;
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
	e->next = NULL;

	Solution solute;
	ListNode * head = solute.swapPairs(a);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}