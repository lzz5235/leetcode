//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		return  sortedListToBST(head,0,length_of_List(head)-1);     
    }
	ListNode *buildList(vector<int> &num)
	{
		int length = num.size();
		if(length==0)
			return 0;
		ListNode *dummy=NULL;
		length--;
		for(;length>=0;length--){
			ListNode *temp = new ListNode(num[length]);
			temp->next = dummy;
			dummy = temp;
		}
		return dummy;
	}
private:
	TreeNode *sortedListToBST(ListNode *&head,int begin,int end) {
		if(end - begin < 0)
			return NULL;
		int mid = begin + (end-begin)/2;

		TreeNode *left = sortedListToBST(head,begin,mid-1);
		TreeNode *root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		root->right = sortedListToBST(head,mid+1,end);

		return root;
	}
	ListNode * find_Kth_ListNode(ListNode *head,int K)
	{
		while(K--)
			head = head->next;
		return head;
	}
	int length_of_List(ListNode *head)
	{
		int length = 0;
		ListNode *temp = head;
		while(temp!=NULL){
			length++;
			temp = temp->next;
		}
		return length;
	}
};

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	Solution solute;	
	bool result;
	
	TreeNode *root ;
	ListNode *head ;
	head = solute.buildList(num);
	root = solute.sortedListToBST(head);

	return 0;
}