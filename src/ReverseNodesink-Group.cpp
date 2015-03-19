//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5


//k=3  1->2->3->4->5->6    return 3->2->1->6->5->4
//看清楚是reverse！不是swap！

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
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(k>2)
		{
				int time = k-1;
				ListNode * dummy = new ListNode(-1);
				if(head==NULL||head->next==NULL)
					return head;
				dummy->next = head;
				ListNode * prev = dummy;
				ListNode * current = dummy->next;
				ListNode * next = current;
				while(next!=NULL){
					while(time--){
						next = next->next;
						if(next==NULL)
							goto final;
					}

					prev = reverse(prev,current,next);
					current = prev->next;
					next = current;
					time = k-1;
				}
		final:
				return dummy->next;
		}
		else if(k==2)
			return swapPairs(head);
		else
			return head;
    }
private:
	ListNode * reverse(ListNode *prev,ListNode *start,ListNode *end){
		ListNode *end_next = end->next;
		ListNode *temp = start;
		ListNode *current = start->next;
		ListNode *next = current->next;
		while(current!=end_next){
			current->next = temp;

			temp = current;
			current = next;
			if(next==NULL)
				break;
			next = next->next;
			
		}
		prev->next = temp;
		start->next = end_next;

		return start;
	}
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
	ListNode *f = new ListNode(6);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = NULL;

	Solution solute;
	ListNode * head = solute.reverseKGroup(a,3);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}