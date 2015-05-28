//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ array's length.
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <queue>
#include <functional>
using namespace std;

struct cmp  
{  
    bool operator () (int &a, int &b)  
    {  
        return a > b ;              // 从小到大排序，值 小的 优先级别高  
    }  
}; 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		//way 1
		//priority_queue<int,vector<int>,cmp> q;
		//int i=0;
		//for(;i<k;i++)
		//	q.push(nums[i]);
		//for(;i<nums.size();i++){
		//	if(q.top()<nums[i]){
		//		q.pop();
		//		q.push(nums[i]);
		//	}
		//}
		//return q.top();

		//way 2
		partial_sort(nums.begin(),nums.begin()+k,nums.end(),greater<int>());
		return nums[k-1];
    }
};


int main()
{
	int a[]={3,2,1,5,6,4};
	int result;
	vector<int> num(a,a+6);
	Solution solute;	
	result = solute.findKthLargest(num,2);
	assert(result==5);
	return 0;
}