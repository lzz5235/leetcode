//Merge two sorted linked lists and return it as a new list. 
//The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode dummy(-1);
		ListNode *temp = &dummy;
		for(;l1!=NULL&&l2!=NULL;temp=temp->next){
			if(l1->val > l2->val){
				temp->next = l2;
				l2 = l2->next;
			}
			else{
				temp->next = l1;
				l1 = l1->next;
			}
		}
		if(l1==NULL)
			temp->next = l2;
		else
			temp->next = l1;

		return dummy.next;
    }
};

int main()
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(4);
	ListNode *c1 = new ListNode(5);
	ListNode *c2 = new ListNode(10);
	ListNode *c3 = new ListNode(11);
	ListNode *b1 = new ListNode(2);
	ListNode *b2 = new ListNode(6);
	ListNode *b3 = new ListNode(9);

	a1->next = a2;
	a2->next = c1;
	c1->next = c2;
	c2->next = c3;
	c3->next = NULL;
	b1->next = b2;
	b2->next = b3;
	b3->next = NULL;

	Solution solute;
	ListNode * head = solute.mergeTwoLists(a1,b1);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}