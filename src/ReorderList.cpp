//Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
//reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		if(head==NULL || head->next==NULL)
			return;
		ListNode *pre=NULL,*slow = head,*fast = head;
		while(fast!=NULL&&fast->next!=NULL){
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;//cut the list in the middle

		slow = reverseList(slow);
		ListNode *current = head;
		while(current->next!=NULL){
			ListNode *temp = current->next;
		//	ListNode *second_temp = slow->next;
			current->next = slow;
			slow = slow->next;
			current->next->next = temp;
			current = temp;
		}
		current->next = slow;
    }
private:
	ListNode * reverseList(ListNode *head){
		if(head==NULL || head->next==NULL)
			return head;

		ListNode *pre=head;
		ListNode *current = head->next;
		ListNode *Next = current->next;
		while(current!=NULL){
			current->next = pre;
			pre = current;
			current = Next;
			Next = Next?Next->next:NULL;
		}
		head->next = NULL;
		return pre;
	}
};

int main()
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *c1 = new ListNode(6);
	ListNode *c2 = new ListNode(3);
	ListNode *c3 = new ListNode(4);
	ListNode *b1 = new ListNode(5);
	ListNode *b2 = new ListNode(6);
	ListNode *b3 = new ListNode(6);

	ListNode *d1 = new ListNode(5);
	ListNode *d2 = new ListNode(9);
	ListNode *d3 = new ListNode(6);

	a1->next = a2;
	a2->next = c1;
	c1->next = c2;
	c2->next = c3;
	c3->next = b1;
	b1->next = b2;
	b2->next = b3;
	b3->next = d1;
	d1->next = d2;
	d2->next = d3;
	d3->next = NULL;

	Solution solute;
	solute.reorderList(a1);
	ListNode *head = a1;

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}