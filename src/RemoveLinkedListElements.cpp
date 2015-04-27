//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.

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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(-1);
		ListNode *current,*pre;
		dummy.next = head;
		pre = &dummy;
		current = dummy.next;

		while(current!=NULL){
			if(current->val==val){
				ListNode *temp = current;
				pre->next = current->next;
				current = current->next;
				delete (temp);
			}else{
				pre = current;
				current = current->next;
			}
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
	ListNode * head = solute.removeElements(a1,6);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}