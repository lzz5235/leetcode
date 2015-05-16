//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ¡Ü m ¡Ü n ¡Ü length of list.



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

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//		int distance = n-m+1;
//		if(distance==1)
//			return head;
//		
//		while(distance--&&fast!=NULL)
//			fast = fast->next;
//		m -=2;
//		while(m--&&fast->next!=NULL){
//			slow = slow->next;
//			fast = fast->next;
//		}
//		ListNode* after_fast = fast->next;
//		fast->next = NULL;
//		ListNode* after_slow = slow->next;
//		
//		ListNode* tempfirst = reverseList(after_slow,after_fast);
//		slow->next = tempfirst;
//
//		return head;
//    }
//private:
//    ListNode* reverseList(ListNode* head,ListNode* end) {
//		if(head==NULL || head->next==NULL)
//			return head;
//
//		ListNode *pre=head;
//		ListNode *current = head->next;
//		ListNode *Next = current->next;
//		while(current!=NULL){
//			current->next = pre;
//			pre = current;
//			current = Next;
//			Next = Next?Next->next:NULL;
//		}
//		head->next = end;
//		return pre;        
//    }
//};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *prev = &dummy;

		for (int i = 0; i < m-1; ++i)
			prev = prev->next;
	
		ListNode* const head2 = prev;
		prev = head2->next;
		ListNode *cur = prev->next;
		for (int i = m; i < n; ++i) {
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur; // Í·²å·¨
			cur = prev->next;
		}
		return dummy.next;
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
	ListNode * head = solute.reverseBetween(a1,2,4);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}