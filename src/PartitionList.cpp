//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
		ListNode *small = new ListNode(-1);
		ListNode *big = new ListNode(-1);

        ListNode *small_cur = small;
		ListNode *big_cur = big;

		for(ListNode *current=head;current!=NULL;current=current->next){
			if(current->val<x){
				small_cur->next = current;
				small_cur = current;
			}
			else{
				big_cur->next=current;
				big_cur = current;
			}
		}
		small_cur->next = big->next;
		big_cur->next=NULL;

		return small->next;
    }
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(4);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(2);
	ListNode *e = new ListNode(5);
	ListNode *f = new ListNode(2);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = NULL;

	Solution solute;
	ListNode * head = solute.partition(a,3);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}