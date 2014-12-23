//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
		int begin=0,end=n;
		while(begin!=end)
		{
			int mid=(begin+end)/2;
			if(A[mid]==target)
				return mid;
			if(A[begin] <=A[mid])
			{
				if(A[begin]<=target&&target<A[mid])
					end=mid;
				else
					begin=mid+1;
			}
			else
			{
				if(A[mid]<target && target <=A[end-1])
					begin = mid+1;
				else
					end = mid;
			}
		}
		return -1;
    }
};

int main()
{
	//int A[]={6,7,0,1,2,4,5};
	int A[]={5,1,3};
	Solution solute;
	cout <<solute.search(A,3,5)<<endl;
}