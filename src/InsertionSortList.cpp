//Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
		ListNode dummy(INT32_MIN);
		//dummy.next = head;
		ListNode *current  = head;
		while(current!=NULL){
			auto pos = findpos(&dummy,current->val);
			ListNode *temp = current->next;
			current->next = pos->next;
			pos->next = current;
			current = temp;
		}
		return dummy.next;
    }
private:
	ListNode *findpos(ListNode *head,int value){
		ListNode *pre=NULL;
		ListNode *current = head;
		for(;current!=NULL&&current->val <=value;
			pre = current,current = current->next);
		return pre;
	}
};

int main()
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(8);
	ListNode *c1 = new ListNode(5);
	ListNode *c2 = new ListNode(9);
	ListNode *c3 = new ListNode(11);
	ListNode *b1 = new ListNode(2);
	ListNode *b2 = new ListNode(6);
	ListNode *b3 = new ListNode(9);

	ListNode *d1 = new ListNode(0);
	ListNode *d2 = new ListNode(1);
	ListNode *d3 = new ListNode(3);

	a1->next = a2;
	a2->next = c1;
	c1->next = c2;
	c2->next = c3;
	c3->next = NULL;
	b1->next = b2;
	b2->next = b3;
	b3->next = NULL;
	d1->next = d2;
	d2->next = d3;
	d3->next = NULL;

	vector<ListNode *> lists;
	lists.push_back(a1);
	lists.push_back(b1);
	lists.push_back(d1);

	Solution solute;
	ListNode * head = solute.insertionSortList(a1);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}