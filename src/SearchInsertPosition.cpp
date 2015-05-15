//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		return distance(A,lower_bound(A,A+n,target));
    }
};

int main()
{

	int a[]={5, 7, 7, 8, 8, 10};
//	int a[]={1,1};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	int result;
	Solution solute;
	result = solute.searchInsert(a,sizeof(a)/sizeof(a[0]),9);
	
	return 0;
}