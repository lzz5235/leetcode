//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Follow up:
//Can you solve it without using extra space?

//设整个链表长L，环入口点与相遇点距离为a，起点到环入口点的距离为x,一圈的长度为r
//当slow与fast重合后，必定slow在cycle中，fast已经在cycle中循环了nr长度
//这时如果slow如果想再回到cycle入口点，则需要走L-x-a步
//x+a = nr = (n-1)r+r =(n-1)r+L-x
//x = (n-1)r+(L-x-a)  所以temp一定会与slow相遇

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
		ListNode *fast = head;

		while(fast!=NULL&&fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast){
				ListNode *temp = head;
				while(temp!=slow){
					temp=temp->next;
					slow=slow->next;
				}
				return temp;
			}
		}
		return false;
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
	ListNode *g = new ListNode(7);
	ListNode *h = new ListNode(8);

	a->next = b;
	b->next = c; 
	c->next = d; 
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = f;

	Solution solute;
	ListNode *temp = solute.detectCycle(a);

	printf("%d\n",temp->val);
	return 0;
}