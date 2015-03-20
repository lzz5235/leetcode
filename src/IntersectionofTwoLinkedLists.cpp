//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//For example, the following two linked lists:
//
//A:          a1 ¡ú a2
//                   ¨K
//                     c1 ¡ú c2 ¡ú c3
//                   ¨J            
//B:     b1 ¡ú b2 ¡ú b3
//
//begin to intersect at node c1.
//
//Notes:
//
//    If the two linked lists have no intersection at all, return null.
//    The linked lists must retain their original structure after the function returns.
//    You may assume there are no cycles anywhere in the entire linked structure.
//    Your code should preferably run in O(n) time and use only O(1) memory.
//
//Credits:
//Special thanks to @stellari for adding this problem and creating all test cases.


//final list must be the common,so the step must be the begin step
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
			return NULL;
		ListNode *tempA = headA,*tempB = headB;
		int lengthA=0,lengthB=0;
		while(tempA!=NULL){lengthA++;tempA = tempA->next;}
		while(tempB!=NULL){lengthB++;tempB = tempB->next;}
		int n = lengthA-lengthB;
		if(n<0){
			n = -n;
			tempB = headB;
			tempA = headA;
			while(n--){tempB = tempB->next;}
		}
		else{
			tempA = headA;
			tempB = headB;
			while(n--){tempA = tempA->next;}
		}
		while(tempA!=tempB)
		{
			tempA = tempA->next;
			tempB =tempB->next;
		}
		return tempA;
    }
};

int main()
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(4);
	ListNode *c1 = new ListNode(3);
	ListNode *c2 = new ListNode(2);
	ListNode *c3 = new ListNode(5);
	ListNode *b1 = new ListNode(2);
	ListNode *b2 = new ListNode(2);
	ListNode *b3 = new ListNode(2);

	a1->next = a2;
	a2->next = c1;
	c1->next = c2;
	c2->next = c3;
	c3->next = NULL;
	b1->next = b2;
	b2->next = b3;
	b3->next = c1;

	Solution solute;
	ListNode * head = solute.getIntersectionNode(a1,b1);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}