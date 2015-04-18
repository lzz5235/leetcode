//Merge two sorted linked lists and return it as a new list. 
//The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		//if(lists.size()==0)
		//	return NULL;
		//int k = lists.size();
		//ListNode *temp1 = lists[0];
		//ListNode *temp2 = lists[k/2];
		//int i,j;

		//for(i=1,j=k/2;i<k/2&&j<k;i++,j++){
		//	temp1 = mergeTwoLists(temp1,lists[i]);
		//	temp2 = mergeTwoLists(temp2,lists[j]);
		//}
		//temp1 = mergeTwoLists(temp1,temp2);
		//return temp1;
		ListNode head(-1);
		ListNode *p = &head;
		priority_queue<ListNode*,vector<ListNode*>,cmp> Heap;
       
        for(int i = 0;i < lists.size();i++){
            if(lists[i] != NULL){
                Heap.push(lists[i]);
			}
        }
        
        while(!Heap.empty()){
            ListNode *list = Heap.top();
            Heap.pop();
            p->next = list;
            p = list;
            if(list->next != NULL){
                Heap.push(list->next);
            }
        }
        return head.next;
    }
private:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		if(l1==l2)
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
	struct cmp {
        bool operator()(ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };
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
	ListNode * head = solute.mergeKLists(lists);

	while(head!=NULL){
		printf("%d\t",head->val);
		head = head->next;
	}
	return 0;
}