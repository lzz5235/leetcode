//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//
//Write a function to determine if a given target is in the array.

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
				return true;
			if(A[begin] < A[mid])
			{
				if(A[begin]<=target&&target< A[mid])
					end=mid;
				else
					begin=mid+1;
			}
			else if(A[begin] > A[mid])
			{
				if(A[mid]<target && target <=A[end-1])
					begin = mid+1;
				else
					end = mid;
			}
			else
				begin++;
		}
		return false;
    }
};

int main()
{
	//int A[]={6,7,0,1,2,4,5};
	int A[]={5,1,1,2,3};
	Solution solute;
	cout <<solute.search(A,5,2)<<endl;
}