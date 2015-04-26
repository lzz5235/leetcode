//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].

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
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		int lower = distance(A,lower_bound(A,A+n,target));
		int high = distance(A,upper_bound(A,A+n,target));
		
		if(A[lower]!=target){
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else{
			result.push_back(lower);
			result.push_back(high-1);
			return result;
		}
    }
};

int main()
{

//	int a[]={5, 7, 7, 8, 8, 10};
	int a[]={1,1};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> result;
	Solution solute;
	result = solute.searchRange(a,sizeof(a)/sizeof(a[0]),1);
	
	return 0;
}