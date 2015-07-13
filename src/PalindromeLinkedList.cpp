//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
//Could you do it in O(n) time and O(1) space?

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }//tow pointer
		slow->next=reverseList(slow->next);
        slow=slow->next;//faster

        while(slow!=NULL){
            if(head->val!=slow->val)//slow->head
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
private:
	ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

int main()
{
	bool result;
	Solution solution;
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *c1 = new ListNode(6);
	ListNode *c2 = new ListNode(3);
	ListNode *c3 = new ListNode(4);
	ListNode *b1 = new ListNode(5);
	ListNode *b2 = new ListNode(4);
	ListNode *b3 = new ListNode(3);

	ListNode *d1 = new ListNode(6);
	ListNode *d2 = new ListNode(2);
	ListNode *d3 = new ListNode(1);

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

	result = solution.isPalindrome(a1);
	return 0;
}